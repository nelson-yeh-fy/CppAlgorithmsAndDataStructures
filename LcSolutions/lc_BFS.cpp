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
void ldemo_q994() {
	Solution_q994 s;
	std::vector<std::vector<int>> oranges = { {2,1,1},{1,1,0},{0,1,1} };
	oranges = { {1,2} };
	int round = s.orangesRotting(oranges);
	std::cout << "round: " << round;
	return;
}