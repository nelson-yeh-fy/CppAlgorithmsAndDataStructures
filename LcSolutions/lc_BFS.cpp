#include <iostream>
#include "lc_BFS.h"

void ldemo_q994() {
	Solution_q994 s;
	std::vector<std::vector<int>> oranges = { {2,1,1},{1,1,0},{0,1,1} };

	int round = s.orangesRotting(oranges);
	std::cout << "round: " << round;
	return;
}