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

	int n, m;
	std::cin >> n >> m;
	int test = 1;

	while (n || m) {
		std::vector<std::string> names(n);
		std::string name1,name2;
		std::unordered_map<std::string, int> Map;
		int index = 0;

		directedTarjanSCC graph(n);

		while (m--) {
			std::cin >> name1 >> name2;
			int u = 0, v = 0;

			if (Map.find(name1) == Map.end()) {
				names[index] = name1;
				Map[name1] = index;
				u = index;
				++index;
			}
			else {
				u = Map[name1];
			}

			if (Map.find(name2) == Map.end()) {
				names[index] = name2;
				Map[name2] = index;
				v = index;
				++index;
			}
			else {
				v = Map[name2];
			}
			graph.addEdge(u, v);
		}

		graph.tarjanSCC();

		std::cout << "Calling circles for data set "<< test << ":" << std::endl;
		for (auto& vec : graph.allSCC) {
			std::cout << names[vec[0]];
			for (size_t i = 1; i < vec.size(); ++i) {
				std::cout << ", " << names[vec[i]];
			}
			std::cout << std::endl;
		}

		std::cin >> n >> m;
		if (n || m) {
			std::cout << std::endl;
		}
		++test;
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


void directedTarjanSCC::addEdge(int u, int v) {
	graph[u].push_back(v);
}