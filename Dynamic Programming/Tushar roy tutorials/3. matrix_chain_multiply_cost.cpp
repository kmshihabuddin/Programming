#include <iostream>
#include<vector>
#include<algorithm>
#include<string>


int matrix_chain_multiplication_cost(std::vector<int>& rows, std::vector<int>& cols){
	int n = rows.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
	for (int len = 1; len < n; ++len){
		for (int i = 0; i+len < n; ++i){
			dp[i][i + len] = std::min(dp[i][i+len-1]+rows[i]*rows[i+len]*cols[i+len], dp[i + 1][i + len]+rows[i]*cols[i]*cols[i+len]);
		}
	}
	
	return dp[0][n-1];
}

bool test1_matrix_chain_multiplication_cost(){
	//matrix: [2x3], [3x6], [6x4], [4x5]
	std::vector<int> rows{ 2, 3, 6, 4 }, cols{ 3, 6, 4, 5 };
	return matrix_chain_multiplication_cost(rows, cols) == 124;
}