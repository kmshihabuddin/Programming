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

int query(std::vector<std::vector<int>>& dp, int row, int col){
	if (row < 0 || col < 0){
		return 0;
	}
	return dp[row][col];
}

int query(std::vector<std::vector<int>>& dp, int left_row, int left_col, int right_row, int right_col){
	return query(dp, right_row, right_col) - query(dp, left_row-1, right_col) - query(dp, right_row, left_col-1) + query(dp, left_row-1, left_col-1);
}

int main()
{
	std::vector<std::vector<int>> a{
		{ 2,0,-3,4 },
		{ 6,3,2,1 },
		{ 5,4,7,3 },
		{ 2,-6,8,1 } };
	 

	int n = a.size(), m = a[0].size();

	std::vector<std::vector<int>> dp(a);

	dp[0][0] = a[0][0];

	for (int i = 1; i < n; ++i){
		dp[i][0] += dp[i - 1][0];
	}

	for (int j = 1; j < m; ++j){
		dp[0][j] += dp[0][j - 1];
	}

	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
		}
	}

	std::cout << query(dp, 1, 2, 3, 3) << std::endl;

	getchar();
	return 0;
}

