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

class directedTarjanSCC {

	const int UNVISITED = -1;
	int V, dfsNumberCounter;
	std::vector<int> dfs_num, dfs_low, S;
	std::vector<bool> visited;

	std::vector<std::vector<int>> graph;

public:
	std::vector<std::unordered_set<int>> allSCC;

	directedTarjanSCC(int no_of_nodes);
	void tarjanSCC(int u);
	void tarjanSCC();
	void addEdge(int u, int v);
};

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	int t;
	input >> t;

	for(int test=1;test<=t;++test){
		int n, m;
		int u, v;
		input >> n >> m;

		directedTarjanSCC graph(n);
		std::vector<std::vector<int>> incoming_edges(n);

		while (m--) {
			input >> u >> v;
			graph.addEdge(u-1, v-1);
			incoming_edges[v - 1].push_back(u-1);
		}

		graph.tarjanSCC();

		int res = 0;
		for (auto& vec : graph.allSCC) {
			bool b = true;
			for (int node:vec) {
				for (int neighbor : incoming_edges[node]) {
					if (vec.find(neighbor) == vec.end()) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				++res;
			}
		}

		output << res << std::endl;
	}
	input.close();
	output.close();
	return 0;
}

directedTarjanSCC::directedTarjanSCC(int no_of_nodes) :V{ no_of_nodes } {
	graph = std::vector<std::vector<int>>(V);
}

void directedTarjanSCC::tarjanSCC() {
	dfsNumberCounter = 0;
	allSCC.clear();
	dfs_num = std::vector<int>(V, UNVISITED);
	dfs_low = std::vector<int>(V, 0);
	visited = std::vector<bool>(V, false);
	S.clear();

	for (int i = 0; i < V; ++i) {
		if (dfs_num[i] == UNVISITED) {
			tarjanSCC(i);
		}
	}
}

void directedTarjanSCC::tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = true;

	for (int v : graph[u]) {
		if (dfs_num[v] == UNVISITED) {
			tarjanSCC(v);
		}

		if (visited[v]) {
			dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
		}
	}

	if (dfs_low[u] == dfs_num[u]) {
		allSCC.push_back({});
		while (true) {
			int v = S.back();
			S.pop_back();
			visited[v] = false;
			allSCC[allSCC.size() - 1].insert(v);
			if (u == v) {
				break;
			}
		}
	}
	
}


void directedTarjanSCC::addEdge(int u, int v) {
	graph[u].push_back(v);
}