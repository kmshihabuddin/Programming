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

class unionFind {
	std::vector<int> roots;
	std::vector<int> sizes;

public:
	unionFind(int n);
	int find(int val);
	bool unionSets(int val1, int val2);
	int getSize(int val);
};

int main()
{
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	int t;
	t = 1;

	for(int test=1;test<=t;++test){
		int n, m, res=0;
		int u, v, w;

		n = 5;
		std::vector<std::vector<int>> edgeList;
		edgeList.push_back({ 0,1,4});//u,v,w
		edgeList.push_back({ 0,2,4 });
		edgeList.push_back({ 0,3,6 });
		edgeList.push_back({ 0,4,6 });

		edgeList.push_back({ 1,2,2 });

		edgeList.push_back({ 2,3,8 });

		edgeList.push_back({ 3,4,9 });

		std::sort(edgeList.begin(), edgeList.end(), [](std::vector<int>& a, std::vector<int>& b) {
			return a[2] < b[2];
		});

		unionFind disjoint(n);

		for (auto& edge : edgeList) {
			if (disjoint.unionSets(edge[0], edge[1])) {
				res += edge[2];
			}
		}

		std::cout << res << std::endl;
	}
	//input.close();
	//output.close();
	getchar();
	return 0;
}

unionFind::unionFind(int n) {
	roots = std::vector<int>(n, -1);
	sizes = std::vector<int>(n, 1);
}

int unionFind::find(int val) {
	if (roots[val] < 0) {
		return val;
	}
	return roots[val] = find(roots[val]);
}

bool unionFind::unionSets(int val1, int val2) {
	int root1 = find(val1);
	int root2 = find(val2);

	if (root1 != root2) {
		roots[root1] = root2;
		sizes[root2] += sizes[root1];
		return true;
	}
	return false;
}

int unionFind::getSize(int val) {
	return sizes[find(val)];
}