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
	std::vector<int> a{ 3,9,1,2};
	//maximum value for player 1 if taking values only from both ends are allowed
	//player 1 starts

	int n = a.size();

	std::vector<std::vector<int>> player1(n,std::vector<int>(n,0));
	std::vector<std::vector<int>> player2(n, std::vector<int>(n, 0));

	for (int i = 0; i < n; ++i){
		player1[i][i] = a[i];
	}

	for (int len = 2; len <= n; ++len){
		for (int i = 0; i + len <= n; ++i){
			int j = i + len - 1;

			if (a[i] + player2[i + 1][j]>player1[i][j]){
				player1[i][j] = a[i] + player2[i + 1][j];
				player2[i][j] = player1[i + 1][j]; 
			}

			if (player2[i][j - 1] + a[j] > player1[i][j]){
				player1[i][j] = player2[i][j - 1] + a[j];
				player2[i][j] = player1[i][j - 1];
			}

		}
	}

	printMatrix(player1,player2);

	getchar();
	return 0;
}

