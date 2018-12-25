// UvaProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "printUtility.h"

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<string>
#include<cctype>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<fstream>
#include<utility>
#include<numeric>

class undirectedArticulationPointBridge {

	const int UNVISITED = -1;
	int V,dfsNumberCounter, dfsRoot, rootChildren;
	std::vector<int> dfs_num, dfs_low, dfs_parent;

	std::vector<std::vector<int>> graph;

public:
	std::vector<bool> articulationVertex;
	std::vector<std::pair<int, int>> articulationBridge;

	undirectedArticulationPointBridge(int no_of_nodes);
	void articulationPoint(int u);
	void articulationPoint();
	void addEdge(int u, int v);
};

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");
	int n;

	while (std::cin>>n) {

		undirectedArticulationPointBridge graph(n);

		int u, v;
		
		for(int i=0;i<n;++i) {
			std::cin >> u;
			char temp;
			int edges;
			std::cin >> temp >> edges >> temp;
			while (edges--) {
				std::cin >> v;
				graph.addEdge(u, v);
			}
		}

		graph.articulationPoint();

		std::cout << graph.articulationBridge.size() << " critical links"<<std::endl;

		std::sort(graph.articulationBridge.begin(), graph.articulationBridge.end());

		for (auto& int_pair : graph.articulationBridge) {
			std::cout << int_pair.first << " - " << int_pair.second << std::endl;
		}
		std::cout << std::endl;

	}
    return 0;
}

undirectedArticulationPointBridge::undirectedArticulationPointBridge(int no_of_nodes):V{no_of_nodes} {
	graph = std::vector<std::vector<int>>(V);
}

void undirectedArticulationPointBridge::articulationPoint() {
	dfsNumberCounter = 0;
	dfs_num = std::vector<int>(V, UNVISITED);
	dfs_low = std::vector<int>(V, 0);
	dfs_parent = std::vector<int>(V, 0);
	articulationVertex = std::vector<bool>(V, false);
	articulationBridge.clear();

	for (int i = 0; i < V; ++i) {
		if (dfs_num[i] == UNVISITED) {
			dfsRoot = i;
			rootChildren = 0;
			articulationPoint(i);
			articulationVertex[dfsRoot] = (rootChildren > 1);
		}
	}
}

void undirectedArticulationPointBridge::articulationPoint(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for (int v : graph[u]) {
		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfsRoot) {
				++rootChildren;
			}
			articulationPoint(v);

			if (dfs_low[v] >= dfs_num[u]) {
				articulationVertex[u] = true;
			}
			if (dfs_low[v] > dfs_num[u]) {
				articulationBridge.push_back(std::make_pair(std::min(u, v),std::max(u,v)));
			}
			dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
		}
		else if(v!=dfs_parent[u]){
			dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
		}
	}
}


void undirectedArticulationPointBridge::addEdge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}