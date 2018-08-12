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
	std::vector<int> a{ 3, 1, 5, 8 };
	//which order ballons should be bursted to maximize value
	// value= left* element * right ; of no left/right, use 1
	// if 3 bursted, we get 1 X 3 X 1=3, if 5 bursted, we get 3 X 1 X 5=15

	int n = a.size();

	std::vector<std::vector<int>> total(n, std::vector<int>(n, 0)); // total value
	std::vector<std::vector<int>> last(n, std::vector<int>(n, 0)); //last ballon bursted

	
	for (int len = 1; len <= n; ++len){
		for (int i = 0; i+len <= n; ++i){
			int j = i + len - 1;

			for (int k = i; k <= j; ++k){
				int temp = a[k];
				if (i > 0){
					temp *= a[i - 1];
				}

				if (j < n - 1){
					temp *= a[j + 1];
				}

				if (k-1>=i){
					temp += total[i][k-1];
				}

				if (k + 1 <= j){
					temp += total[k + 1][j];
				}

				if (temp > total[i][j]){
					total[i][j] = temp;
					last[i][j] = k;
				}
			}
		}
	}

	printMatrix(total,last);

	getchar();
	return 0;
}

