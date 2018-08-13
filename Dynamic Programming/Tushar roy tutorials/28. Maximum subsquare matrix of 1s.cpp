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
	std::vector<std::vector<int>>
		a{ { 0, 0, 1, 1, 1 }, 
			{0, 0, 1, 1, 1}, 
			{0, 1, 1, 1, 1},
			{1, 0, 1, 1, 1}
		};
	//matrix consists of 0's and 1's
	// find largest sub square matrix made up of 1's

	int n = a.size();
	int m = a[0].size();

	std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,0));

	for (int k = 1; k <= n; ++k){

		for (int i = k; i <= n; ++i){
			if (a[i-1][k-1] == 1){
				dp[i][k] = std::min(dp[i - 1][k - 1], std::min(dp[i - 1][k], dp[i][k - 1])) + 1;
			}
		}

		for (int j = k; j <= m; ++j){
			if (a[k-1][j - 1] == 1){
				dp[k][j] = std::min(dp[k - 1][j - 1], std::min(dp[k - 1][j], dp[k][j - 1])) + 1;
			}
		}

	}

	printMatrix(dp);

	getchar();
	return 0;
}

