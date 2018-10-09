#include "stdafx.h"
#include "BIT.h"
bitree::bitree(){
	
}

bitree::bitree(int nElements){
	elements = std::vector<int>(nElements, 0);
	tree = std::vector<int>(nElements+1, 0);
}

bitree::bitree(std::vector<int>& vec){
	elements = std::vector<int>(vec.size(), 0);
	tree = std::vector<int>(vec.size() + 1, 0);
	for (int i = 0; i < (int)vec.size(); ++i){
		update(vec[i], i);
	}
}

bitree::bitree(const bitree& rhs)
	:tree(rhs.tree),elements(rhs.elements){

}

bitree::~bitree(){
	tree.clear();
}



void bitree::update(const int& elem, int index){
	int original_index = index;
	++index;
	while (index < (int)tree.size()){
		tree[index] += (elem - elements[original_index]);
		index += (index & -index);
	}
	elements[original_index] = elem;
}

int bitree::query(int left, int right){
	return query(right) - query(left-1);
}

int bitree::query(int index){
	++index;
	int temp = 0;
	while (index){
		temp=temp+tree[index];
		index -= (index& -index);
	}
	return temp;
}