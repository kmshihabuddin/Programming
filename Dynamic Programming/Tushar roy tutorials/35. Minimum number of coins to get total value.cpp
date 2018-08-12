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
	int total = 10;
	std::vector<int> coins{ 1, 2, 3 };
	//minimum number of coins to get the total

	//bottom up approach
	
	int n = coins.size();

	std::vector<int> dp(total + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < n; ++i){
		for (int j = coins[i]; j <= total; ++j){
			dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	printVector(dp);

	getchar();
	return 0;
}

