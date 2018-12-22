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

class unionFind {
	std::vector<int> roots;
	std::vector<int> sizes;

public:
	unionFind(int n);
	int find(int val);
	void unionSets(int val1, int val2);
	int getSize(int val);
};


int main()
{
	int t;
	std::string str;
	std::getline(std::cin, str);
	t = std::stoi(str);
	std::getline(std::cin, str);

	for (int test = 1; test <= t; ++test) {
		int res = 0;

		std::vector<std::string> grid;

		while (true) {
			std::getline(std::cin, str);
			if (std::isdigit(str[0])) {
				break;
			}
			grid.push_back(str);
		}

		int row = grid.size();
		int col = grid[0].size();
		unionFind lakes(row*col);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == 'L') {
					continue;
				}

				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if ((dx || dy) && i + dx >= 0 && i + dx < row && j + dy >= 0 && j + dy < col && grid[i + dx][j + dy] == 'W') {
							lakes.unionSets(i*col + j, (i + dx)*col + j + dy);
						}
					}
				}

			}
		}

		while (true) {
			int pos = str.find(' ');
			int r = std::stoi(str.substr(0, pos))-1;
			int c = std::stoi(str.substr(pos + 1))-1;
			std::cout << lakes.getSize(r*col + c) << std::endl;

			std::getline(std::cin, str);
			if (str.length() == 0 || !std::isdigit(str[0])) {
				break;
			}
		}
		//std::cout << "Case " << test << ": " << even<< ' ' << odd << std::endl;
		if(test!=t)
			std::cout << std::endl;

	}
    return 0;
}

unionFind::unionFind(int n) {
	roots = std::vector<int>(n, -1);
	sizes = std::vector<int>(n, 1);
}

int unionFind::find(int val) {
	if (roots[val] < 0) {
		return val;
	}
	return roots[val] = find(roots[val]);
}

void unionFind::unionSets(int val1, int val2) {
	int root1 = find(val1);
	int root2 = find(val2);

	if (root1 != root2) {
		roots[root1] = root2;
		sizes[root2] += sizes[root1];
	}
}

int unionFind::getSize(int val) {
	return sizes[find(val)];
}