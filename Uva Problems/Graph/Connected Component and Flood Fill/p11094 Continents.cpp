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


int dfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited, int posx, int posy, std::vector<int>& dx, std::vector<int>& dy,char water);

int main()
{
	//int t;
	int m, n;

	while (std::cin >> m) {
	
		std::cin >> n;
		std::vector<std::string> grid(m); // m x n grid, m rows, n cols
		std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

		for (int i = 0; i < m; ++i) {
			std::cin >> grid[i];
		}

		int posx;
		int posy;
		std::cin >> posx>>posy;
		char water = grid[posx][posy];
		std::vector<int> dx{ -1,0,1,0 }, dy{ 0,-1,0,1 };

		dfs(grid, visited, posx, posy, dx, dy,water);

		int res = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res = std::max(res, dfs(grid, visited, i, j, dx, dy,water));
			}
		}

		std::cout << res << std::endl;

	}
    return 0;
}

int dfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited, int posx, int posy, std::vector<int>& dx, std::vector<int>& dy,char water) {
	if (posx < 0 || posx >= grid.size() ||  visited[posx][posy] || grid[posx][posy]!=water) {
		return 0;
	}
	int count = 1;
	visited[posx][posy] = true;

	for (int i = 0; i < dx.size(); ++i) {
		count += dfs(grid, visited, posx + dx[i], (posy + dy[i]+ grid[0].size())%grid[0].size(), dx, dy,water);
	}

	return count;
}