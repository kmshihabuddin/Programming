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

bool bfs(std::vector<std::vector<int>>& graph);

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int n, m;
	int test = 1;
	std::cin >> n;
	while (n) {

		std::vector<std::vector<int>> graph(n);
		int u, v;
		std::cin >> m;
		while (m--) {
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		
		if (bfs(graph)) {
			std::cout << "BICOLORABLE." << std::endl;
		}
		else {
			std::cout << "NOT BICOLORABLE." << std::endl;
		}
		
		std::cin >> n;
		++test;
	}

	//input.close();
	//output.close();
    return 0;
}

bool bfs(std::vector<std::vector<int>>& graph) {
	int n = graph.size();
	std::vector<bool> visited(n, false);
	std::vector<bool> colors(n, false);

	std::queue<int> nodes;


	nodes.push(0);

	while (nodes.size()) {

		int node = nodes.front();
		nodes.pop();

		if (visited[node]) {
			continue;
		}
		visited[node] = true;

		for (int nextNode : graph[node]) {
			if (visited[nextNode]) {
				if (colors[nextNode] == colors[node]) {
					return false;
				}
			}
			else {
				colors[nextNode] = !colors[node];
				nodes.push(nextNode);
			}
		}
	}

	return true;
}