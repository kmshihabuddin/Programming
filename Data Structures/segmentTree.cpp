#include "stdafx.h"
#include "segmentTree.h"


segmentTree::segmentTree(std::vector<int>& a):dummyValue(INT_MAX){
	nodes = nextPowerOf2((int)a.size());
	tree = std::vector<int>(2*nodes-1, dummyValue);
	std::copy(a.begin(), a.end(), tree.begin() + nodes - 1);

	for (int i = nodes - 2; i >= 0; --i){
		tree[i] = std::min(tree[2 * i + 1], tree[2 * i + 2]); //min query
	}
}

int segmentTree::rangeQuery(int left, int right){
	return rangeQuery(left, right, 0, nodes - 1, 0);
}

void segmentTree::update(int index, int value){
	index += (nodes - 1);
	tree[index] = value;

	index = (index - 1) / 2;

	while (index){
		tree[index] = std::min(tree[2 * index + 1], tree[2 * index + 2]);
		index = (index - 1) / 2;
	}

	if (2 * index + 2 < (int)tree.size()){
		tree[index] = std::min(tree[2 * index + 1], tree[2 * index + 2]);
	}
	
}

int segmentTree::rangeQuery(int left, int right, int left_ind, int right_ind, int pos){
	if (right<left_ind || left>right_ind){
		return dummyValue;
	}
	else if (left_ind >= left && right_ind <= right){
		return tree[pos];
	}
	else{
		int mid_ind = (left_ind + right_ind) / 2;
		return std::min(rangeQuery(left, right, left_ind, mid_ind, 2 * pos + 1), 
						rangeQuery(left, right, mid_ind + 1, right_ind, 2 * pos + 2));
	}
}

int segmentTree::nextPowerOf2(int n){
	int res = 1;
	while (res < n){
		res *= 2;
	}
	return res;
}