#ifndef _UNION_FIND_
#define _UNION_FIND_

#include<vector>
#include<unordered_map>
#include<map>

class unionFind {
	std::vector<int> parents;
	std::vector<int> sizes;
	std::map<int, int> teams;

public:
	unionFind(int n);
	int find(int x);
	void unionSets(int root1, int root2);
	long long countPairs(int c);
};

#endif
