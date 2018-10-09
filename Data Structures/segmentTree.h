#ifndef _SEGMENT_TREE_H_
#define _SEGMENT_TREE_H_

#include<vector>
#include<algorithm>

class segmentTree{
	int nextPowerOf2(int n);
	int rangeQuery(int left, int right, int left_ind, int right_ind, int pos);
	int rangeUpdate(int left, int right, int valueAdd, int left_ind, int right_ind, int pos);
public:
	std::vector<int> tree;
	std::vector<int> lazyTree;
	int nodes;
	int dummyValue;

	segmentTree(std::vector<int>& a);//dummy=0 for sum, INT_MAX or min query, INT_MIN for max_query
	int rangeQuery(int left, int right); //0 based; inclusive
	void update(int index, int value);
	void rangeUpdate(int left, int right, int valueAdd);
};

#endif