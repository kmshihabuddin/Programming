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

struct node {
	std::vector<int> res;
	std::set<int> visited;
	std::vector<std::unordered_set<int>> graph;
};

int main()
{
	int t;
	std::cin >> t;
	std::cin.ignore();
	std::string str;
	int test = 1;

	while(std::getline(std::cin,str)) {
		
		std::getline(std::cin, str);

		int n = (str.length()+1)/2;
		std::vector<char> nodes(n);
		for (int i = 0; i < n; ++i) {
			nodes[i] = str[2 * i];
		}
		std::sort(nodes.begin(), nodes.end());

		std::unordered_map<char, int> Map;
		for (int i = 0; i < n; ++i) {
			Map[nodes[i]] = i;
		}

		std::vector<std::unordered_set<int>> graph(n);
		std::getline(std::cin, str);
		for (int i = 0; i < (int)str.length(); i+=4) {
			graph[Map[str[i + 2]]].insert(Map[str[i]]);
		}

		std::queue<node> Q;
		node tempNode;
		tempNode.visited = std::set<int>();
		tempNode.graph = graph;
		tempNode.res = std::vector<int>();
		Q.push(tempNode);

		for(int index=0;index<n;++index) {

			int len = Q.size();
			while (len--) {
				node curNode = Q.front();
				Q.pop();

				for (int i = 0; i < n; ++i) {
					if (curNode.visited.find(i) == curNode.visited.end() && curNode.graph[i].size() == 0) {
						
						std::set<int> tempVisited = curNode.visited;
						std::vector<int> tempRes = curNode.res;
						std::vector<std::unordered_set<int>> tempGraph = curNode.graph;

						tempVisited.insert(i);
						tempRes.push_back(i);
						for (int j = 0; j < n; ++j) {
							tempGraph[j].erase(i);
						}

						node tempNode;
						tempNode.visited = tempVisited;
						tempNode.graph = tempGraph;
						tempNode.res = tempRes;
						Q.push(tempNode);
					}
				}
			}
		}

		if (Q.size()) {
			while (Q.size()) {
				std::cout << nodes[Q.front().res[0]];
				for (int i = 1; i < (int)Q.front().res.size(); ++i) {
					std::cout << ' ' << nodes[Q.front().res[i]];
				}
				std::cout << '\n';
				Q.pop();
			}
		}
		else {
			std::cout << "NO" << '\n';
		}

		if (test != t) {
			std::cout << std::endl;
		}
		++test;
	}
    return 0;
}


