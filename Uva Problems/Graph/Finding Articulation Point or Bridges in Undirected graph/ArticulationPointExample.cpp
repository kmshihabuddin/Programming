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

	int n = 6;

	undirectedArticulationPointBridge graph(n);
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(1, 4);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);

	graph.articulationPoint();
	printVector(graph.articulationVertex);
	printVector(graph.articulationBridge);
	getchar();
	//input.close();
	//output.close();
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
				articulationBridge.push_back(std::make_pair(u, v));
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