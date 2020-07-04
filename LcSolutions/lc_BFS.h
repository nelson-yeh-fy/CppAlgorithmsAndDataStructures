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