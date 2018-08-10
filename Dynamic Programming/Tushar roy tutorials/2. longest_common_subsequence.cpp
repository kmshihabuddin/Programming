#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

std::string longestCommonSubsequence(std::string& a, std::string& b){
	int rows = a.length(), cols = b.length();
	std::string result = "";
	std::vector<std::vector<int>> dp(rows+1, std::vector<int>(cols+1, 0));

	for (int i = 1; i <= rows; ++i){
		for (int j = 1; j <= cols; ++j){
			dp[i][j] = std::max(std::max(dp[i - 1][j], dp[i][j - 1]), dp[i-1][j-1]+(a[i-1]==b[j-1]) );
		}
	}

	while (dp[rows][cols]){
		if (dp[rows][cols] == dp[rows - 1][cols]){
			--rows;
		}
		else if (dp[rows][cols] == dp[rows][cols - 1]){
			--cols;
		}
		else{
			result += a[rows-1];//or b[cols-1]
			--rows;
			--cols;
		}
	}
	std::reverse(result.begin(), result.end());
	return result;
}

bool test1_lcs(){
	std::string a = "abcdaf", b = "acbcf";
	return longestCommonSubsequence(a, b) == "abcf";
}