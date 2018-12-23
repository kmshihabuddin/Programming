// UvaProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "printUtility.h"

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<string>
#include<cctype>

int dfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited, int x, int y, std::vector<int>& dx, std::vector<int>& dy);

int main()
{
	int t;
	std::cin >> t;

	for(int test=1;test<=t;++test) {
		
		int n;
		std::cin >> n;
		std::vector<std::string> grid(n); //n x n grid
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

		for (int i = 0; i < n; ++i) {
			std::cin >> grid[i];
		}
		
		std::vector<int> dx{ -1,0,1,0 }, dy{ 0,-1,0,1 };

		int res = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j]=='x' && dfs(grid, visited, i, j, dx, dy)) {
					++res;
				}
			}
		}

		std::cout <<"Case "<<test<<": "<< res << std::endl;

	}
    return 0;
}


int dfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited, int x, int y, std::vector<int>& dx, std::vector<int>& dy) {
	if (x < 0 || x >= grid.size() || y<0 || y>=grid[0].size() || visited[x][y] || grid[x][y] == '.') {
		return 0;
	}
	int count = 1;
	visited[x][y] = true;

	for (int i = 0; i < dx.size(); ++i) {
		count+=dfs(grid, visited, x + dx[i], y + dy[i], dx, dy);
	}

	return count;
}
