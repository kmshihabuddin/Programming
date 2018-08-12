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
	std::string s1, s2,testStr;
	s2 = "aab";
	s1 = "axy";
	testStr = "aaxaby";//output : true 
	//testStr = "abaaxy"; //output: false
	//string interleaving problem
	// test if one string is combination of two strings with orders of characters preserved

	int n = s1.length(), m = s2.length();

	std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(m+1, false));
	dp[0][0] = true;

	for (int i = 1; i <= n; ++i){
		if (testStr[i - 1] == s1[i - 1]){
			dp[i][0] = dp[i - 1][0];
		}
		else{
			dp[i][0] = false;
		}
	}

	for (int j = 1; j <= m; ++j){
		if (testStr[j - 1] == s2[j - 1]){
			dp[0][j] = dp[0][j - 1];
		}
		else{
			dp[0][j] = false;
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (testStr[i + j - 1] == s1[i - 1]){
				dp[i][j] = dp[i][j]|dp[i - 1][j];
			}

			if (testStr[i + j - 1] == s2[j - 1]){
				dp[i][j] = dp[i][j] | dp[i][j - 1];
			}
		}
	}

	printMatrix(dp);

	getchar();
	return 0;
}

