#ifndef _HEAPBINARY_H_
#define _HEAPBINARY_H_

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

class heaps{
	int* a;
	int currentsize;
public:
	heaps();
	~heaps();
	void insert(int value);
	int extract_min();
	bool isempty();
	void print();
	size_t size();
};

#endif