// UvaJudge.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include <fstream>
#include<list>
#include<unordered_set>

void dfs(std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited);

int main(){

	int t, n;
	std::cin >> t;

	for (int test = 1; test <= t; ++test){
		std::cin >> n;
		std::vector<std::vector<int>> graph(n);
		std::vector<std::vector<bool>> res(n, std::vector<bool>(n, false));

		//input
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				int temp;
				std::cin >> temp;
				if (temp){
					graph[i].push_back(j);
				}
			}
		}

		//rechable nodes from 0
		std::vector<bool> reachable(n, false);
		dfs(graph, 0, reachable);
		res[0] = reachable;

		//dominator for all nodes 
		for (int i = 1; i < n; ++i){
			std::vector<int> temp = graph[i];
			graph[i].clear();

			std::vector<bool> visited(n, false);
			dfs(graph, 0, visited);

			if (reachable[i]){
				for (int j = 0; j < n; ++j){
					if (i == j){
						res[i][j] = true;
					}
					else{
						res[i][j] = reachable[j] & !visited[j];
					}
				}
			}

			graph[i] = temp;
		}
		

		//printing outputs
		std::cout << "Case " << test << ":\n";
		std::cout << '+' << std::string(2*n-1, '-') << '+' << '\n';
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				std::cout << '|';
				if (res[i][j]){
					std::cout << 'Y';
				}
				else{
					std::cout << 'N';
				}
			}
			std::cout << "|\n";
			std::cout << '+' << std::string(2*n-1, '-') << '+' << '\n';
		}
	}

	
	return 0;
}


void dfs(std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited){
	if (!visited[node]){
		visited[node] = true;
		for (int temp : graph[node]){
			if (!visited[temp]){
				dfs(graph,temp,visited);
			}
		}
	}
}