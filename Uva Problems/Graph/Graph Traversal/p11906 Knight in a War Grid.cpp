// UvaProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "printUtility.h"

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>

void dfs(std::vector<std::vector<bool>>& grid, std::vector<std::vector<bool>>& water, int posx, int posy, std::set<std::vector<int>>& moves);
int even = 0;
int odd = 0;

int main()
{
	int t;
	std::cin >> t;
	for (int test = 1; test <= t; ++test) {
		int r, c, m, n,w,u,v;
		std::cin >> r >> c >> m >> n;
		std::vector<std::vector<bool>> grid(r, std::vector<bool>(c, false));
		std::vector<std::vector<bool>> water(r, std::vector<bool>(c, false));

		std::cin >> w;
		while (w--) {
			std::cin >> u >> v;
			water[u][v] = true;
		}

		std::set<std::vector<int>> moves;
		for (int i = -1; i <= 1; i += 2) {
			for (int j = -1; j <= 1; j += 2) {
				moves.insert({ m*i , n*j });
				moves.insert({ n*i , m*j });
			}
		}

		odd = 0;
		even = 0;
		dfs(grid,water, 0, 0, moves);

		std::cout << "Case " << test << ": " << even<< ' ' << odd << std::endl;

	}
    return 0;
}

void dfs(std::vector<std::vector<bool>>& grid, std::vector<std::vector<bool>>& water, int posx, int posy, std::set<std::vector<int>>& moves) {
	int count = 0;

	grid[posx][posy] = true;
	for (auto& move : moves) {
		if (posx + move[0] >= 0 && posx + move[0] < grid.size() && posy + move[1]>=0 && posy + move[1] < grid[0].size() && !water[posx + move[0]][posy + move[1]]) {
			++count;
			if(!grid[posx + move[0]][posy + move[1]])
				dfs(grid,water, posx + move[0], posy + move[1], moves);
		}
	}
	

	if (count % 2) {
		++odd;
	}
	else {
		++even;
	}
}