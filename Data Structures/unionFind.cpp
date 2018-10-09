#include "stdafx.h"
#include "unionFind.h"


unionFind::unionFind(int n) {
	parents = std::vector<int>(n, -1);
	sizes = std::vector<int>(n, 1);
	teams[1] = n;
}


int unionFind::find(int x) {
	if (parents[x] < 0) {
		return x;
	}
	else {
		return parents[x] = find(parents[x]);
	}
}

void unionFind::unionSets(int root1, int root2) {
	
	if (root1 == root2) {
		return;
	}
	
	--teams[sizes[root1]];
	if (teams[sizes[root1]] == 0) {
		teams.erase(sizes[root1]);
	}

	--teams[sizes[root2]];
	if (teams[sizes[root2]] == 0) {
		teams.erase(sizes[root2]);
	}

	if (sizes[root1] > sizes[root2]) {
		parents[root2] = root1;
		sizes[root1] += sizes[root2];
		++teams[sizes[root1]];
	}
	else {
		parents[root1] = root2;
		sizes[root2] += sizes[root1];
		++teams[sizes[root2]];
	}
}


long long unionFind::countPairs(int c) {
	if (c == 0) {
		long long res = parents.size();
		return (res*(res + 1)) / 2;
	}
	return 0;
}