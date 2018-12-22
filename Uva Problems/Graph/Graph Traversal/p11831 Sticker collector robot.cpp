// UvaJudge.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include <fstream>
#include<list>
#include<unordered_set>


int main(){

	int n,m,t;
	std::cin >> n >> m >> t;

	//very strange directions
	std::vector<int> xdir{ -1,0,1,0}, ydir{ 0,1,0,-1}; //{N,L,S,O}

	while(n||m||t){
		int res=0;

		std::vector<std::string> Map(n);

		for(int i=0;i<n;++i){
			std::cin >> Map[i];
		}

		//starting position and direction (index)
		int xpos = 0, ypos = 0, dir=-1;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (Map[i][j] == 'N'){
					dir = 0;
					xpos = i;
					ypos = j;
					break;
				}
				else if (Map[i][j] == 'L'){
					dir = 1;
					xpos = i;
					ypos = j;
					break;
				}
				else if (Map[i][j] == 'S'){
					dir = 2;
					xpos = i;
					ypos = j;
					break;
				}
				else if (Map[i][j] == 'O'){
					dir = 3;
					xpos = i;
					ypos = j;
					break;
				}
			}
		}

		//following directions
		std::string directions;
		std::cin >> directions;

		for (char ch : directions){
			if (ch == 'D'){
				//left
				dir = (dir + 1) % 4;
			}
			else if (ch == 'E'){
				//right
				dir = (dir - 1 + 4) % 4;
			}
			else{
				int tempx = xpos;
				int tempy = ypos;
				xpos+=xdir[dir];
				ypos += ydir[dir];

				if (xpos < 0 || xpos >= n || ypos < 0 || ypos >= m || Map[xpos][ypos] == '#'){
					xpos = tempx;
					ypos = tempy;
					continue;
				}
				if (Map[xpos][ypos] == '*'){
					++res;
					Map[xpos][ypos] = '.';
				}
			}
			
		}

		std::cout<<res<<'\n';
		std::cin >>n>>m>>t; 
	}

	
	return 0;
}
