#ifndef LE_BFS_H
#define LE_BFS_H
#include <iostream>
#include <vector>
#include <queue>

//98. Validate Binary Search Tree [Med]
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution_q98 {
public:
    bool isValidBST(TreeNode* root) {

        //step1. check root
        if (root == nullptr) return true;
        std::queue<TreeNode*> q;
        q.push(root);

        //step2. BFS search
        while (!q.empty()) {

            TreeNode* t = q.front();
            q.pop();
            if (t->left != nullptr) {
                q.push(t->left);
                if (t->left->val >= t->val) return false;
            }

            if (t->right != nullptr) {
                q.push(t->right);
                if (t->val >= t->right->val) return false;
            }
        }
        return true;
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

    //step3. BFS-like search by checking 4-directions.
    void rotting(std::queue<Pos>& rotted, std::queue<Pos>& newRotted, 
        const int max_x, const int max_y, const std::vector<std::vector<int>>& grid) {
        while (!rotted.empty()) {
            Pos current = rotted.front();
            Pos l = left(current);
            Pos r = right(current);
            Pos t = top(current);
            Pos b = bottom(current);
            rotted.pop();

            if (l.x > -1 && l.y > -1 && l.x < max_x && l.y < max_y) {
                if (grid[l.x][l.y] == 1) {
                    newRotted.push(l);
                }
            }
            if (r.x > -1 && r.y > -1 && r.x < max_x && r.y < max_y) {
                if (grid[r.x][r.y] == 1) {
                    newRotted.push(r);
                }
            }
            if (t.x > -1 && t.y > -1 && t.x < max_x && t.y < max_y) {
                if (grid[t.x][t.y] == 1) {
                    newRotted.push(t);
                }
            }
            if (b.x > -1 && b.y > -1 && b.x < max_x && b.y < max_y) {
                if (grid[b.x][b.y] == 1) {
                    newRotted.push(b);
                }
            }
        }
        return;
    }

    int orangesRotting(std::vector<std::vector<int>>& grid) {

        if (grid.size() < 1) return 0;
        int max_x = grid[0].size();
        int max_y = grid.size();
        //step2. screen all oranges to find rotted (2) items, put them into a queue.
        std::queue<Pos> rotted, newRotted;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) newRotted.push(Pos{ i, j });
            }
        }

        //step4. each round we check all rotted oragnges, put infected into newRotted.
        int round = 0;
        while (!newRotted.empty()) {
            ++round;
            rotted.swap(newRotted);
            rotting(rotted, newRotted, max_x, max_y, grid);
        }

        return round;
    }
};
void ldemo_q994();
#endif