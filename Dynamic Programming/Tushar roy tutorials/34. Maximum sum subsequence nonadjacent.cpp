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
	std::vector<int> a{ 4, 1, 1, 4, 2, 1 };
	//std::vector<int> a{ 2,5,3,1,7};
	//maximum sum subsequence nonadjacent

	//bottom up approach
	
	int n = a.size();

	std::vector<int> dp(n+1,0);
	dp[1] = a[0];

	for (int i = 2; i <= n; ++i){
		dp[i] = std::max(dp[i - 1], a[i - 1] + dp[i - 2]);
	}

	printVector(dp);

	getchar();
	return 0;
}

