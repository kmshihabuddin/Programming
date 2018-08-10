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
	int n = 5;

	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i <= n; ++i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printVector(dp);

	getchar();
	return 0;
}

