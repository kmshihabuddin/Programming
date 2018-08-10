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
	int row = 4, col = 5;
	//count number of ways to go from left top to down right
	//only right and down moves allowed
	

	std::vector<std::vector<int>> dp(row, std::vector<int>(col, 1));

	for (int start = 1; start < std::min(row, col); ++start){

		for (int i = start; i < row; ++i){
			dp[i][start] = dp[i - 1][start] + dp[i][start - 1];
		}

		for (int i = start; i < col; ++i){
			dp[start][i] = dp[start - 1][i] + dp[start][i - 1];
		}
	}

	printMatrix(dp);

	getchar();
	return 0;
}

