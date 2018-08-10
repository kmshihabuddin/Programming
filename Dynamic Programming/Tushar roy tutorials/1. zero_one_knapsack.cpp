#include <iostream>
#include<vector>
#include<algorithm>


int zero_one_knapsack(std::vector<int>& weights, std::vector<int>& values, int max_weight){
	int rows = weights.size();
	int cols = max_weight+1;
	std::vector<std::vector<int>> dp(rows, std::vector<int>(cols,0));

	//1st row
	for (int j = weights[0]; j < cols; ++j){
		dp[0][j] = values[0];
	}

	//next rows
	for (int i = 1; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if (j>=weights[i]){
				dp[i][j] = std::max(dp[i - 1][j], values[i] + dp[i - 1][j - weights[i]]);
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[rows - 1][cols - 1];
}

bool test1_zero_one_knapsack(){
	std::vector<int> wt{ 1, 3, 4, 5 }, vals{ 1, 4, 5, 7 };
	int maxw = 7;
	return zero_one_knapsack(wt, vals, maxw) == 9;
}

bool test2_zero_one_knapsack(){
	std::vector<int> wt{ 4, 5, 3, 1 }, vals{ 5, 7, 4, 1 };
	int maxw = 8;
	return zero_one_knapsack(wt, vals, maxw) == 11;
}