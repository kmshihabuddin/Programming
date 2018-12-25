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
	std::vector<std::vector<int>> allSCC;

	directedTarjanSCC(int no_of_nodes);
	void tarjanSCC(int u);
	void tarjanSCC();
	void addEdge(int u, int v);
};

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int n = 8;

	directedTarjanSCC graph(n);
	graph.addEdge(0, 1);

	graph.addEdge(1, 3);
	graph.addEdge(3, 2);
	graph.addEdge(2, 1);

	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 7);
	graph.addEdge(7, 6);
	graph.addEdge(6, 4);

	graph.tarjanSCC();

	std::cout << "SCC groups:" << std::endl;
	for (auto& vec : graph.allSCC) {
		printVector(vec);
	}
	getchar();
	//input.close();
	//output.close();
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

		if (dfs_low[u] == dfs_num[u]) {
			allSCC.push_back({});
			while (true) {
				int v = S.back();
				S.pop_back();
				visited[v] = false;
				allSCC[allSCC.size() - 1].push_back(v);
				if (u == v) {
					break;
				}
			}
		}
	}
}


void directedTarjanSCC::addEdge(int u, int v) {
	graph[u].push_back(v);
}