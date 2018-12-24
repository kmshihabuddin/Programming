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

bool bfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int source, int& blue, int& red);

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int n, m;
	int test = 1;
	std::cin >> test;
	while (test--) {

		std::cin >> n >> m;
		std::vector<std::vector<int>> graph(n);

		int u, v;
		
		while (m--) {
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		std::vector<bool> visited(n, false);
		int blue, red;
		int res = 0;

		for (int i = 0; i < n; ++i) {
			if (bfs(graph, visited, i,blue,red)) {
				res += std::min(blue, red);
			}
			else {
				res = -1;
				break;
			}
		}

		std::cout << res << std::endl;
		
	}

	std::cin >> test;
	//input.close();
	//output.close();
    return 0;
}

bool bfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int source, int& blue, int& red) {

	blue = 0;
	red = 0;

	if (visited[source]) {
		return true;
	}
	int n = graph.size();
	 
	std::vector<bool> colors(n, false);

	std::queue<int> nodes;


	nodes.push(source);

	while (nodes.size()) {

		int node = nodes.front();
		nodes.pop();

		if (visited[node]) {
			continue;
		}
		visited[node] = true;
		if (colors[node]) ++blue;
		else ++red;

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

	if (red == 0 || blue == 0) {
		red = 1;
		blue = 1;
	}

	return true;
}