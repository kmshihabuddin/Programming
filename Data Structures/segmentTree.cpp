#include "stdafx.h"
#include "segmentTree.h"


segmentTree::segmentTree(std::vector<int>& a):dummyValue(INT_MAX){
	nodes = nextPowerOf2((int)a.size());
	tree = std::vector<int>(2*nodes-1, dummyValue);
	lazyTree = std::vector<int>(2 * nodes - 1, 0);
	std::copy(a.begin(), a.end(), tree.begin() + nodes - 1);

	for (int i = nodes - 2; i >= 0; --i){
		tree[i] = std::min(tree[2 * i + 1], tree[2 * i + 2]); //min query
	}
}

int segmentTree::rangeQuery(int left, int right){
	return rangeQuery(left, right, 0, nodes - 1, 0);
}

void segmentTree::rangeUpdate(int left, int right, int valueAdd) {
	rangeUpdate(left, right, valueAdd, 0, nodes - 1, 0);
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
		if (lazyTree[pos] == 0) {
			return tree[pos];
		}
		tree[pos] += lazyTree[pos];
		if (2 * pos + 2 < 2 * nodes - 1) {
			lazyTree[2 * pos + 1] = lazyTree[pos];
			lazyTree[2 * pos + 2] = lazyTree[pos];
		}
		lazyTree[pos] = 0;
		return tree[pos];
	}
	else{
		tree[pos] += lazyTree[pos];
		if (2 * pos + 2 < 2 * nodes - 1) {
			lazyTree[2 * pos + 1] = lazyTree[pos];
			lazyTree[2 * pos + 2] = lazyTree[pos];
		}
		lazyTree[pos] = 0;
		int mid_ind = (left_ind + right_ind) / 2;
		return std::min(rangeQuery(left, right, left_ind, mid_ind, 2 * pos + 1), 
						rangeQuery(left, right, mid_ind + 1, right_ind, 2 * pos + 2));
	}
}



int segmentTree::rangeUpdate(int left, int right, int valueAdd, int left_ind, int right_ind, int pos) {
	if (left_ind > right || right_ind < left) {
		return dummyValue;
	}
	else if (left_ind >= left && right_ind <= right) {
		tree[pos] += valueAdd;
		if (2 * pos + 2 < 2 * nodes - 1) {
			lazyTree[2 * pos + 1] += valueAdd;
			lazyTree[2 * pos + 2] += valueAdd;
		}
		return tree[pos];
	}
	else {
		tree[pos] += valueAdd;
		if (2 * pos + 2 < 2 * nodes - 1) {
			lazyTree[2 * pos + 1] += valueAdd;
			lazyTree[2 * pos + 2] += valueAdd;
		}
		int mid_ind = (left_ind + right_ind) / 2;
		tree[pos] = std::min(rangeUpdate(left, right, valueAdd, left_ind, mid_ind, 2 * pos + 1),
							 rangeUpdate(left, right, valueAdd, mid_ind + 1, right_ind, 2 * pos + 2));
	}
}

int segmentTree::nextPowerOf2(int n){
	int res = 1;
	while (res < n){
		res *= 2;
	}
	return res;
}