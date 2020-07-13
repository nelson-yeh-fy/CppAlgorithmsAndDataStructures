#ifndef LE_BFS_H
#define LE_BFS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "ds.h"

//104. Maximum Depth of Binary Tree [Easy]
class Solution_q104 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//994. Rotting Oranges [Med]
struct Pos {
    int x;
    int y;
};
class Solution_q994 {
public:
    //step1. define 4-directions
    Pos left(Pos p) { return Pos{ p.x, p.y - 1 }; }
    Pos right(Pos p) { return  Pos{ p.x, p.y + 1 }; }
    Pos top(Pos p) { return Pos{p.x - 1, p.y };}
    Pos bottom(Pos p) { return Pos{ p.x + 1, p.y }; }

    void rotting(Pos c, int& numOfFresh, std::vector<std::vector<int>>& grid, std::queue<Pos>& newRotted){
        int max_x = grid.size();
        int max_y = grid[0].size();
        if (c.x > -1 && c.y > -1 && c.x < max_x && c.y < max_y) {
            if (grid[c.x][c.y] == 1) {
                newRotted.push(c);
                grid[c.x][c.y] = 2;
                --numOfFresh;
            }
        }
    }

    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.size() < 1) return 0;
        int numOfFresh = 0;
        //step2. screen all oranges to find rotted (2) items, put them into a queue.
        std::queue<Pos> rotted, newRotted;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) newRotted.push(Pos{ i, j });
                if (grid[i][j] == 1) ++numOfFresh;
            }
        }
        //step3. check fresh count, there is never a fresh orange, just 0;
        if (numOfFresh == 0) return 0;

        //step4. BFS-like search, each round we start from rotted oragnges, put infected into newRotted.
        int round = -1;
        while (!newRotted.empty()) {
            ++round;
            rotted.swap(newRotted);
            //step5. checking 4-directions.
            while (!rotted.empty()) {
                Pos current = rotted.front();
                rotted.pop();
                rotting(left(current), numOfFresh, grid, newRotted);
                rotting(right(current), numOfFresh, grid, newRotted);
                rotting(top(current), numOfFresh, grid, newRotted);
                rotting(bottom(current), numOfFresh, grid, newRotted);
            }
        }
        //After all rounds of rotting, if there is still a fresh orange, then return -1; otherwise return rounds
        return numOfFresh>0 ? -1: round;
    }
};
void ldemo_q994();
#endif