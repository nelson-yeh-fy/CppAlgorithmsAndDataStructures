#ifndef LE_DFS_H
#define LE_DFS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "lc_BFS.h"

//In-order traversal (BST's in-order traversal is a sorted list)

//230. Kth Smallest Element in a BST [Med]
class Solution_q230 {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) return -1;

        //left
        int res = kthSmallest(root->left, k);
        if (!k) return res;

        //current
        if (!--k) return root->val;

        //right
        return kthSmallest(root->right, k);
    }
};
//200. Number of Islands [Med]
class Solution_q200_a {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        //pre-req. check if grid is empty or boundary test cases.
        if (grid.size() < 1) return 0;
        int res = 0;
        std::stack<std::pair<int, int>> s;

        //step1. find island's land first and then do DFS-like search.
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {

                //step2. if this position is water, mark it as checked.
                if (grid[i][j] == '0') {
                    grid[i][j] = '8';
                    //step3. if this position is island, we entend and mark the whole island checked(2).
                }
                else if (grid[i][j] == '1') {
                    s.push({ i, j });
                    ++res;
                    while (!s.empty()) {
                        int pi = s.top().first;
                        int pj = s.top().second;
                        s.pop();
                        grid[pi][pj] = '9';

                        if (pi > 0 && grid[pi - 1][pj] == '1') {
                            s.push({ pi - 1, pj });
                            grid[pi - 1][pj] = '9';
                        }
                        if (pi < grid.size() - 1 && grid[pi + 1][pj] == '1') {
                            s.push({ pi + 1, pj });
                            grid[pi + 1][pj] = '9';
                        }
                        if (pj > 0 && grid[pi][pj - 1] == '1') {
                            s.push({ pi, pj - 1 });
                            grid[pi][pj - 1] = '9';
                        }
                        if (pj < grid[0].size() - 1 && grid[pi][pj + 1] == '1') {
                            s.push({ pi, pj + 1 });
                            grid[pi][pj + 1] = '9';
                        }
                    }
                }//end-of-if(grid[i][j] == '1')
            }
        }
        return res;
    }
};
class Solution_q200_b {
public:
    void markIslandVisited(std::vector<std::vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        markIslandVisited(grid, i - 1, j);
        markIslandVisited(grid, i + 1, j);
        markIslandVisited(grid, i, j - 1);
        markIslandVisited(grid, i, j + 1);
        return;
    }
    int numIslands(std::vector<std::vector<char>>& grid) {
        //pre-req. check if grid is empty or boundary test cases.
        if (grid.empty()) return 0;
        int res = 0;

        //step1. find island's land first and then do DFS-like search.
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                //step2. if this position is water, mark it as checked.
                if (grid[i][j] == '1') {
                    ++res;
                    markIslandVisited(grid, i, j);
                }
            }
        }
        return res;
    }
};
void ldemo_q200();
//305. Number of Islands II [Hard]
class Solution_q305 {
public:
    bool isValidPos(int i, int j, std::vector<std::vector<int>>& grid) {
        if (i < 0 || j < 0 || i > grid.size() || j > grid[0].size())
            return false;
        return true;
    }
    std::vector<int> numIslands(int m, int n, std::vector<std::pair<int, int>> ops) {
        //step1. check boundaries
        if (!m && !n || ops.empty()) return {};
        std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
        std::vector<int> res;

        //step2. Each step adds one land, that may connect the other islands.
        for (int i = 0; i < ops.size(); ++i) {
            int x = ops[i].first, y = ops[i].second;
            //step3. check the given pos is an valid postition.
            if (isValidPos(x, y, grid)) {
                if (grid[x][y] == 0) { //if it's already a land, ignore this operation.
                    int c = res.empty() ? 1 : res.back() + 1; //current island.
                    //step4. check 4 dirctions
                    if (isValidPos(x - 1, y, grid) && grid[x - 1][y] == 1)
                        --c;
                    if (isValidPos(x + 1, y, grid) && grid[x + 1][y] == 1)
                        --c;
                    if (isValidPos(x, y - 1, grid) && grid[x][y - 1] == 1)
                        --c;
                    if (isValidPos(x, y + 1, grid) && grid[x][y + 1] == 1)
                        --c;
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
void ldemo_q305();
#endif