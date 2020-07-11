#include <iostream>
#include "lc_DFS.h"

void ldemo_q200() {
	Solution_q200_b s;
	std::vector<std::vector<char>> grid1 = { {'1','1','1','1','0'},{'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'} };
	std::vector<std::vector<char>> grid2 = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
	std::cout << "islands:" << s.numIslands(grid2);
}
void ldemo_q305() {
	Solution_q305 s;
	std::vector<std::pair<int, int>> op1 = { {0, 0}, {0,1}, {1,1} };
	std::vector<std::pair<int, int>> op2 = { {0, 0}, {0,1}, {1,1} };
	std::vector<int> res1 = s.numIslands(3, 3, op1);
	for (auto it = res1.cbegin(); it != res1.cend(); ++it)
		std::cout << *it << ",";
}