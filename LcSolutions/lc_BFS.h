#ifndef LE_BFS_H
#define LE_BFS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

//98. Validate Binary Search Tree [Med]
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//using BFS
struct ValidBSTRange {
    TreeNode* node;
    TreeNode* minNode;
    TreeNode* maxNode;
};
class Solution_q98_a {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        //step1. BFS put the root node, and send nullptr as min/max boundary
        std::queue<ValidBSTRange> q;
        q.push(ValidBSTRange{ root, nullptr, nullptr });
        //step2. BFS search
        while (!q.empty()) {
            ValidBSTRange t = q.front();
            q.pop();

            if (t.maxNode && t.node->val >= t.maxNode->val)
                return false;
            if (t.minNode && t.node->val <= t.minNode->val)
                return false;

            //step3. check left (its maxBoundary is current root, means left->value should be < maxBoundary)
            if (t.node->left) q.push(ValidBSTRange{ t.node->left, t.minNode, t.node });
            //step4. check right (its minBoundary is current root, means right->value should be > minBoundary)
            if (t.node->right) q.push(ValidBSTRange{ t.node->right, t.node, t.maxNode });
        }
        return true;
    }
};
//using DFS
class Solution_q98_b {
public:
    bool isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;

        if (minNode && node->val <= minNode->val || maxNode && node->val >= maxNode->val)
            return false;

        return (isValidBST(node->left, minNode, node) && 
                isValidBST(node->right, node, maxNode));
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};
//using in-order traversal
class Solution_q98_c {
public:
    bool isValidBST(TreeNode* node, TreeNode* &prev) {
        if (!node) return true;
        //Because in-order traversal (left, root, right) for a BST will be a sorted list,
        //We can simply traverse it this way, make sure current val is bigger than pre val.
        
        //left
        if (!isValidBST(node->left, prev)) return false;
        //current
        if (prev && node->val <= prev->val) return false;
        prev = node;
        //right
        return isValidBST(node->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST(root, prev);
    }
};
void ldemo_q98();
//104. Maximum Depth of Binary Tree [Easy]
class Solution_q104 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
//230. Kth Smallest Element in a BST [Med]
//In-order traversal (BST's in-order traversal is a sorted list)
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
                            grid[pi-1][pj] = '9';
                        }
                        if (pi < grid.size() - 1 && grid[pi + 1][pj] == '1') {
                            s.push({ pi + 1, pj });
                            grid[pi+1][pj] = '9';
                        }
                        if (pj > 0 && grid[pi][pj - 1] == '1') {
                            s.push({ pi, pj - 1 });
                            grid[pi][pj-1] = '9';
                        }
                        if (pj < grid[0].size() - 1 && grid[pi][pj + 1] == '1') {
                            s.push({ pi, pj + 1 });
                            grid[pi][pj+1] = '9';
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
        if (i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
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
        std::vector<std::vector<int>> grid ( n, std::vector<int>(m, 0) );
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