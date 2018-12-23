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

void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int source, std::vector<int>& output);

int main()
{
	int n, m;
	std::cin >> n >> m;
	while (n || m) {
		std::vector<std::vector<int>> graph(n);
		int u, v;
		while (m--) {
			std::cin >> u >> v;
			graph[u - 1].push_back(v-1);
		}

		std::vector<int> res;
		std::vector<bool> visited(n, false);

		for (int i = 0; i < n; ++i) {
			dfs(graph, visited, i, res);
		}

		std::reverse(res.begin(), res.end());

		std::cout << res[0]+1;
		for (int i = 1; i < n; ++i) {
			std::cout << ' ' << res[i] + 1;
		}
		std::cout << '\n';

		std::cin >> n >> m;
	}
    return 0;
}


void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int source, std::vector<int>& output) {
	if (!visited[source]) {
		visited[source] = true;
		for (int nextNode : graph[source]) {
			dfs(graph, visited, nextNode, output);
		}
		output.push_back(source);
	}
}