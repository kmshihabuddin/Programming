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
	//Count Number of Binary Search Tree Possible given n keys
	

	std::vector<int> dp(n + 1,0);

	dp[0] = 1;

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < i; ++j){
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}

	printVector(dp);

	getchar();
	return 0;
}

