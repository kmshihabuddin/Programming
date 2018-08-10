#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

std::set<int> isTotalSubsetSum(std::vector<int>& nums, int total){
	int n = nums.size();
	std::set<int> result;
	std::vector<std::vector<bool>> dp(n, std::vector<bool>(total + 1, false));
	if (nums[0] <= total){
		dp[0][nums[0]] = true;
	}
	dp[0][0] = true;

	for (int i = 1; i < n; ++i){
		for (int j = 0; j <= total; ++j){
			if (j < nums[i]){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
			}
		}
	}

	//track back to find elements
	int col = total, row = n - 1;
	while (col){
		while (row && dp[row - 1][col]){
			--row;
		}
		result.insert(nums[row]);
		col -= nums[row];
	}
	printSet(result);
	return result;
}

bool test1_isTotalSubsetSum(){
	std::vector<int> nums{ 2, 3, 7, 8, 10 };
	int total = 21;
	std::set<int> res{ 3, 8, 10 };
	return isTotalSubsetSum(nums, total)==res;
}