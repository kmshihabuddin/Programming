#ifndef _BITREE_H_
#define _BITREE_H_

#include<iostream>
#include<vector>


class bitree{
	std::vector<int> elements;
	std::vector<int> tree;

	int query(int index);
public:
	bitree();
	bitree(int nElements);
	bitree(std::vector<int>& vec);
	bitree(const bitree& rhs);
	~bitree();

	void update(const int& elem, int index);
	int query(int left, int right);//0 based index, inlcusive
	
};

#endif