#include <iostream>
#include "lc_BFS.h"

void ldemo_q98() {
	Solution_q98_a s;
	TreeNode* n2 = new TreeNode(5, nullptr, nullptr);
	TreeNode* n3 = new TreeNode(15, nullptr, nullptr);
	TreeNode* n1 = new TreeNode(10, n2, n3);
	std::cout << s.isValidBST(n1);
	return;
}
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
	for(auto it=res1.cbegin(); it!=res1.cend(); ++it)
	std::cout << *it << ",";
}
void ldemo_q994() {
	Solution_q994 s;
	std::vector<std::vector<int>> oranges = { {2,1,1},{1,1,0},{0,1,1} };
	oranges = { {1,2} };
	int round = s.orangesRotting(oranges);
	std::cout << "round: " << round;
	return;
}