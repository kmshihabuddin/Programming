// dpProblems.cpp : Defines the entry point for the console application.
//
#include "UtilityTemplates.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<list>
#include<numeric>


int main()
{
	//std::vector<int> a{ 2, -1, 4, 3, 5, -1, 3, 2 };
	std::vector<int> a{ 15, -5, 7, 7, 6, 12, -3 };
	//longest bitonic sequence
	//bitonic: first increasing; then decreasing
	
	int n = a.size();

	std::vector<int> increasing(n,1),decreasing(n,1);

	for (int i = 1; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (a[i]>a[j]){
				increasing[i] = std::max(increasing[i], 1 + increasing[j]);
			}

			if (a[n - 1 - i]>a[n - 1 - j]){
				decreasing[n - 1 - i] = std::max(decreasing[n - 1 - i], 1 + decreasing[n - 1 - j]);
			}
		}
	}

	printVector(increasing);
	printVector(decreasing);

	int res = 0;

	for (int i = 0; i < n; ++i){
		res = std::max(res, increasing[i] + decreasing[i] - 1);
	}

	std::cout << res << std::endl;

	getchar();
	return 0;
}

