std::vector<int> longestIncreasingSubsequence(std::vector<int>& nums){
	int n = nums.size();
	std::vector<int> lens(n, 1),positions(n,-1),result;
	int max_length = 0, max_pos = -1;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (nums[j] < nums[i] && lens[j]+1>lens[i]){
				lens[i] = lens[j] + 1;
				positions[i] = j;
			}
		}
		if (lens[i]>max_length){
			max_length = lens[i];
			max_pos = i;
		}
	}

	while (max_pos != -1){
		result.push_back(nums[max_pos]);
		max_pos = positions[max_pos];
	}
	std::reverse(result.begin(), result.end());

	return result;
}

bool test1_longestIncreasingSubsequence(){
	std::vector<int> nums{ 3,4,-1,0,6,2,3,1 };
	nums = longestIncreasingSubsequence(nums);
	std::vector<int> res{ -1,0,2,3};

	return nums == res;
}

bool test2_longestIncreasingSubsequence(){
	std::vector<int> nums{ 2,5,1,8,3};
	nums = longestIncreasingSubsequence(nums);
	std::vector<int> res{ 2, 5,8 };

	return nums == res;
}