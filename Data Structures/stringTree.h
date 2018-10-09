#ifndef _STRING_TREE_H_
#define _STRING_TREE_H_

#include<vector>
#include<cstdio>
#include<iostream>

struct char_node{
	char ch;
	int count;
	std::vector<char_node*> children;
	char_node(char ch2);
};
class stringTree{
	char_node* root;
public:
	stringTree(std::string& str, int k);
	int count(std::string& sub_str);
};

#endif