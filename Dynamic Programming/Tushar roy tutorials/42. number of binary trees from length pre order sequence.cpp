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
	int n = 5;

	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;

	//pure dp technique
	/*for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= i - 1; ++j){
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}*/

	//using properties of catalan numbers
	for (int i = 1; i <= n; ++i){
		dp[i] = (2 * (2 * i - 1)*dp[i - 1]) / (i + 1);
	}

	printVector(dp);

	getchar();
	return 0;
}

