
std::string  longest_palindromic_subsequence(std::string& s){
	int n = s.length();
	std::string res = "";
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

	//length 1 strings
	for (int i = 0; i < n; ++i){
		dp[i][i] = 1;
	}

	//dp
	for (int len = 1; len < n;++len){ //len=string_length-1
		for (int i = 0; i + len < n; ++i){
			int j = i + len;
			if (s[i] == s[j]){
				dp[i][j] = 2 + dp[i + 1][j - 1];
			}
			else{
				dp[i][j] = std::max(dp[i + 1][j - 1],std::max(dp[i][j-1],dp[i+1][j]));
			}
		}
	}

	std::list<int> first, last;
	int start = 0, end = n - 1;
	while (start < end){
		if (dp[start][end] == dp[start + 1][end - 1]){
			++start;
			--end;
		}
		else if (dp[start][end] == dp[start + 1][end]){
			++start;
		}
		else if (dp[start][end] == dp[start][end - 1]){
			--end;
		}
		else{
			first.push_back(start);
			last.push_front(end);
			++start;
			--end;
		}
	}

	for (int index : first){
		res += s[index];
	}
	if (start == end){
		res += s[start];
	}
	for (int index : last){
		res += s[index];
	}

	return res;
}

bool test1_longest_palindromic_subsequence(){
	std::string s = "agbdba";
	return longest_palindromic_subsequence(s) == "abdba";
}