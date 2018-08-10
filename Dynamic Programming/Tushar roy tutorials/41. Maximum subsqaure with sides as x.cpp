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
	std::vector<std::string> a
	{"oooox",
	 "xxxxx",
	 "xoxxx",
	 "xxxxx",
	 "xxxxx"};

	int n = a.size(), m = a[0].size();

	std::vector<std::vector<int>> cols(n+1, std::vector<int>(m+1, 0));
	std::vector<std::vector<int>> rows(n+1, std::vector<int>(m+1, 0));

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){

			if (a[i-1][j-1] == 'x'){

				if (i>0){
					rows[i][j] = rows[i - 1][j] + 1;
				}
		
				if (j>0){
					cols[i][j] = cols[i][j - 1] + 1;
				}
			}
			std::cout << cols[i][j] << ',' << rows[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	int maxwidth = 0;
	
	for (int i = n; i >= 1; --i){
		for (int j = m; j >= 1; --j){
			for (int k = std::min(rows[i][j], cols[i][j]); k > maxwidth; --k){
				if (rows[i][j-k+1] >= k && cols[i-k+1][j] >= k){
					maxwidth = k;
					break;
				}
			}
		}
	}

	std::cout << maxwidth << std::endl;

	getchar();
	return 0;
}

