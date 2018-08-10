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

void sorted_index(std::vector<int>& vec, std::vector<int>& index){
	int n = vec.size();
	index.resize(n);
	std::vector<std::pair<int, int>> a(n);

	for (int i = 0; i < n; ++i){
		a[i].first = vec[i];
		a[i].second = i;
	}

	std::sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i){
		index[i] = a[i].second;
	}
}

void reorderVector(std::vector<int>& vec, std::vector<int>& index){
	std::vector<int> temp(vec);

	for (size_t i = 0; i < index.size(); ++i){
		vec[i] = temp[index[i]];
	}
}



int main()
{
	std::vector<int> profits{ 2, 11, 4, 5, 6, 5 };
	std::vector<int> start{ 7, 5, 6, 4, 2, 1 };
	std::vector<int> end{ 9, 8, 7, 6, 5, 3 };
	
	std::vector<int> index;

	sorted_index(end, index);
	reorderVector(profits, index);
	reorderVector(start, index);
	reorderVector(end, index);
	
	std::vector<int> dp(profits);
	int maxProfit = 0;

	for (size_t i = 0; i < dp.size(); ++i){
		for (size_t j = 0; j < i; ++j){
			if (end[j] <= start[i]){
				dp[i] = std::max(dp[i], dp[j] + profits[i]);
			}
		}
		maxProfit = std::max(maxProfit, dp[i]);
	}

	std::cout << maxProfit << std::endl;

	getchar();
	return 0;
}

