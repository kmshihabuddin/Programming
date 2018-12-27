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

bool isNeighbor(std::string& s1, std::string& s2) {
	if (s1.length() != s2.length()) {
		return false;
	}
	int diff = 0;
	for (size_t i = 0; i < s1.length(); ++i) {
		diff += (int)(s1[i] != s2[i]);
	}
	return diff == 1;
}

int bfs_unweighted(std::vector<std::vector<int>>& graph, int u, int v);

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int t;
	std::string s;
	std::getline(std::cin, s);
	t = std::stoi(s);
	std::getline(std::cin, s);
	bool first = true;

	while(std::getline(std::cin,s)){
		std::vector<std::string> words;
		
		while (s != "*") {
			words.push_back(s);
			std::getline(std::cin, s);
		}

		int n = words.size();
		std::unordered_map<std::string, int> Map;
		for (int i = 0; i < n; ++i) {
			Map[words[i]] = i;
		}

		std::vector<std::vector<int>> graph(n);

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isNeighbor(words[i], words[j])) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		if (first) {
			first = false;
		}
		else {
			std::cout << std::endl;
		}

		while (std::getline(std::cin, s) && s.length()) {
			int pos = s.find(' ');
			std::string word1 = s.substr(0, pos), word2 = s.substr(pos + 1);
			int u = Map[word1], v = Map[word2];
			int res= bfs_unweighted(graph, u, v);
			std::cout << s << ' ' << res << std::endl;
		}
	}
	//input.close();
	//output.close();
	//getchar();
	return 0;
}

int bfs_unweighted(std::vector<std::vector<int>>& graph, int u, int v) {
	std::queue<int> nodes, counts;
	nodes.push(u);
	counts.push(0);
	std::vector<bool> visited(graph.size(), false);

	while (nodes.size()) {
		int node = nodes.front();
		int count = counts.front();
		nodes.pop();
		counts.pop();

		if (node == v) {
			return count;
		}

		if (visited[node]) {
			continue;
		}
		visited[node] = true;

		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				nodes.push(neighbor);
				counts.push(count + 1);
			}
		}
	}

	return -1;//if v cannot be reached
}