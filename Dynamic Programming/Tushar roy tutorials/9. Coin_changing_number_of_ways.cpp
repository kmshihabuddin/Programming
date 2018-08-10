int coin_changing_ways(std::vector<int>& coins, int total){
	int n = coins.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(total + 1, 0));
	
	//1st row
	for (int i = 0; i*coins[0] <= total; ++i){
		dp[0][i*coins[0]] = 1;
	}

	//dp 
	for (int i = 1; i < n; ++i){
		for (int j = 0; j <= total; ++j){
			if (j < coins[i]){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
			}
		}
	}
	
	return dp[n - 1][total];
}

bool test1_coin_changing_ways(){
	std::vector<int> coins{ 1, 2, 3 };
	int total = 5;
	return coin_changing_ways(coins, total) == 5;
}
