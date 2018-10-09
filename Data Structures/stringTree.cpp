#include "stdafx.h"
#include "stringTree.h"

char_node::char_node(char ch2)
:ch{ ch2 }, count{ 0 }{
	
}

stringTree::stringTree(std::string& s, int k){
	root = new char_node('0');
	for (size_t i = 0; i < s.length(); ++i){
		char_node* start = root;
		for (size_t j = i; j < s.length(); ++i){
			
		}
	}
}