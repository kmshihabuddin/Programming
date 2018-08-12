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
	int n=5;
	//total number of ways to reach n-th step if you can move only 1 step or 2 step


	std::vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printVector(dp);

	getchar();
	return 0;
}

