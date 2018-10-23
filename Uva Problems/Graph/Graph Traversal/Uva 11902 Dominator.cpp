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

class graph{
	std::vector<std::list<int>> adj;
	std::vector<bool> visited;
	std::vector<bool> visited_outer;
	std::vector<int> result;
	int precede;
public:
	graph(int n);//n=number of nodes
	void addEdge(int a, int b);
	void dfs(int node);
};

int main(){
	
	int n, q, i, j;
	
	
	return 0;
}

graph::graph(int n) 
:adj{ std::vector<std::list<int>>(n) }, visited{ std::vector<bool>(n, false) }, result{ std::vector<int>(n) }{
	visited_outer = visited;
	precede = 0;
}

void graph::addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void graph::dfs(int node){
	bool flag = false;

	for (int n : adj[node]){
		if (!visited[n]){
			visited[n] = true;
			flag = true;
		}
	}

	if (!flag){
		result[node] = node;
	}
}