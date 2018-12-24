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


int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int n, m;
	int test = 1;
	while (std::cin >> n) {
		std::vector<std::string> names(n);
		std::unordered_map<std::string, int> Map;

		for (int i = 0; i < n; ++i) {
			std::cin >> names[i];
			Map[names[i]] = i;
		}

		std::vector<std::unordered_set<int>> graph(n);
		std::string u, v;
		std::cin >> m;
		while (m--) {
			std::cin >> u >> v;
			graph[Map[v]].insert(Map[u]);
		}

		std::vector<int> res;
		std::vector<bool> visited(n, false);

		std::queue<int> nodes;
		for (int i = 0; i < n; ++i) {
			if (graph[i].size() == 0 && !visited[i]) {
				nodes.push(i);
				break;
			}
		}

		while (nodes.size()) {

			int node = nodes.front();
			nodes.pop();
			visited[node] = true;
			res.push_back(node);

			for (int i = 0; i < n; ++i) {
				graph[i].erase(node);
			}

			for (int i = 0; i < n; ++i) {
				if (graph[i].size() == 0 && !visited[i]) {
					nodes.push(i);
					break;
				}
			}
		}

		std::cout << "Case #" << test << ": Dilbert should drink beverages in this order: ";
		
		std::cout << names[res[0]];
		for (int i = 1; i < n; ++i) {
			std::cout << ' ' << names[res[i]];
		}
		std::cout << '.';
		++test;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	//input.close();
	//output.close();
    return 0;
}

