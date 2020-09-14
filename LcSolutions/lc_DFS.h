#ifndef LE_DFS_H
#define LE_DFS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include "ds.h"
using namespace std;

struct ValidBSTRange {
    TreeNode* node;
    TreeNode* minNode;
    TreeNode* maxNode;
};
//98. Validate Binary Search Tree [Med], using BFS
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
    bool isValidBST(TreeNode* node, TreeNode*& prev) {
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

//230. Kth Smallest Element in a BST [Med]
class Solution_q230 {
public:
    //In-order traversal (BST's in-order traversal is a sorted list)
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


//22. Generate Parentheses [Med]
class Solution_q22_a {
public:
    void addParenthesis(std::vector<std::string>& res, std::string s,
        int stackCounter, int left, int right) {
        if (stackCounter < 0)
            return;
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        //two decision, either add another '(' or ')', depends on remaining left/right can be used
        if (left) {
            addParenthesis(res, s + "(", stackCounter + 1, left - 1, right);
        }
        if (left < right) {
            addParenthesis(res, s + ")", stackCounter - 1, left, right - 1);
        }
    }
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        addParenthesis(res, "", 0, n, n); //number of chars to be added: 2*n
        return res;
    }
};
class Solution_q22_b {
public:
    void addParenthesis(std::vector<std::string>& res, std::string& s,
        int stackCounter, int left, int right) {
        if (stackCounter < 0)
            return;
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        //two decision, either add another '(' or ')', depends on remaining left/right can be used
        if (left) {
            s.push_back('(');
            addParenthesis(res, s, stackCounter + 1, left - 1, right);
            s.pop_back();
        }
        if (left < right) {
            s.push_back(')');
            addParenthesis(res, s, stackCounter - 1, left, right - 1);
            s.pop_back();
        }
    }
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string strdancing;
        addParenthesis(res, strdancing, 0, n, n); //number of chars to be added (left and right): n
        return res;
    }
};
void ldemo_q22();

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

//301. Remove Invalid Parentheses
class Solution_q301 {
public:
    void dfs(string& s, size_t idx, int unpair, int l, int r, string path, unordered_set<string>& res) {
        if (r < 0 || r < 0 || unpair < 0) // Eliminate unnecessary generations.
            return;

        if (idx == s.size()) {
            if (l == 0 && r == 0 && unpair == 0) res.insert(path);
            return;
        }
        else {
            if (s[idx] == '(') {
                //2 choices: one is is to add '(',')'; the other is not to add them
                dfs(s, idx + 1, unpair + 1, l, r, path + s[idx], res);
                dfs(s, idx + 1, unpair, l - 1, r, path, res);
            }
            else if (s[idx] == ')') {
                dfs(s, idx + 1, unpair - 1, l, r, path + s[idx], res);
                dfs(s, idx + 1, unpair, l, r - 1, path, res);
            }
            else { //for characters not '(' nor ')'
                dfs(s, idx + 1, unpair, l, r, path + s[idx], res);
            }
        }
        return;
    }

    vector<string> removeInvalidParentheses(string s) {
        // Step 0. remove prefixing ')' and postfixing '(';
        /*size_t p1 = s.find_first_not_of(')');
        size_t p2 = s.find_last_not_of('(');
        cout << "P1:" << p1 << ", P2:" << p2 << endl;
        if(p1 > s.size() || p2 > s.size()) return {""};
        s = s.substr(p1, p2-p1+1); cout << s; //s = s.substr(p1, (s.size()-p1)-(s.size()-p2)+1 );*/

        // Step 1. count unclosing '(' and ')', so we know how many and what to remove.
        int l = 0; // l: number of '(' to be removed 
        int r = 0; // r: number of ')' to be removed
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') ++l;
            else if (s[i] == ')' && l > 0) --l;
            else if (s[i] == ')' && l == 0) ++r;
        }

        // Step 2. recursively generate parentheses,
        // two choices: remove/not add '(' / ')', or append the characters.
        unordered_set<string> set;
        dfs(s, 0, 0, l, r, "", set);
        return vector<string>(set.cbegin(), set.cend());
    }
};

//199. Binary Tree Right Side View [Med]
class Solution_q199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> curlv, nextlv;
        nextlv.push(root);

        while (!nextlv.empty()) {
            // Step 1. swap all items in nextlv into curlv, and then we process all items in curlv.
            curlv.swap(nextlv);

            // Step 2. add child items into nextlv, the last one will be the right most item
            while (!curlv.empty()) {
                TreeNode* tmp = curlv.front(); curlv.pop();
                if (tmp->left)  nextlv.push(tmp->left);
                if (tmp->right) nextlv.push(tmp->right);
                if (curlv.empty()) res.push_back(tmp->val);
            }
        }
        return res;
    }
};
void ldemo_q199();
#endif