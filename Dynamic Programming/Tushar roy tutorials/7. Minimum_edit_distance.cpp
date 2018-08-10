int minimumEditDistance(std::string& s1, std::string& s2){
	int n = s1.length(), m = s2.length();
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
	//1st row
	for (int i = 0; i <= n; ++i){
		dp[i][0] = i;
	}
	//1st col
	for (int j = 0; j <= m; ++j){
		dp[0][j] = j;
	}
	//dp
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (s1[i - 1] == s2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}

	return dp[n][m];
}

bool test1_minimumEditDistance(){
	std::string s1 = "azced", s2 = "abcdef";
	return  minimumEditDistance(s1, s2) == 3;
}