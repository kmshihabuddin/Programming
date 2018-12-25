#ifndef _PRINT_UTILITY_H_
#define _PRINT_UTILITY_H_

#include<vector>
#include<iostream>
#include<utility>

template<typename T>
void printVector(std::vector<T>& a) {
	for (T n : a) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
}

template<typename T1,typename T2>
void printVector(std::vector<std::pair<T1,T2>>& a) {
	for (size_t i = 0;i<a.size();++i) {
		std::cout << '(' << a[i].first << ',' << a[i].second << ')' << ' ';
	}
	std::cout << std::endl;
}


#endif