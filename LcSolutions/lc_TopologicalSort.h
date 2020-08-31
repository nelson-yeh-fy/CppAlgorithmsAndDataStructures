#ifndef LE_TS_H
#define LE_TS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "ds.h"
using namespace std;

//269. Alien Dictionary [Hard]
class Solution_q269 {
public:
    unordered_map<char, list<char>*> adj;
    unordered_map<char, int> visited;
    string sorted;

    void topologicalSortUtil(char c) {
        // Mark the current node as visited. 
        visited[c] = 1; //1: visiting

        // Recur for all the vertices adjacent to this vertex 
        for (auto it = adj[c]->cbegin(); it != adj[c]->cend(); ++it) {
            if (visited[*it] == 1) return; //visiting itself, cyclic
            if (visited[*it] == 0)
                topologicalSortUtil((*it));
        }

        // Push current vertex to stack which stores result 
        visited[c] = 2;
        sorted.push_back(c);
        return;
    }

    string alienOrder(vector<string>& words) {
        // Step 0: Put all unique letters into adj as keys.
        for (string word : words) {
            for (char c : word) {
                if (!visited.count(c)) {
                    adj[c] = new list<char>;
                    visited[c] = 0;
                }
            }
        }

        // Step 1: Find all edges, e.g.: w(w-'a')->e, e(e-'a')->r
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];

            // Check that word2 is not word1's prefix, e.g.: 1: "abcd", 2: "ab"
            if (word1.size() > word2.size() && word1.rfind(word2, 0) == 0)
                return "";

            // Find the first non-match, insert the relationship into adjacent list
            for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
                if (word1[j] != word2[j]) {
                    adj[word1[j]]->push_back(word2[j]);
                    break;
                }
            }
        }

        // Step3. All unique characters need to be in topological sort
        for (auto kv : visited) {
            if (visited[kv.first] == 0)
                topologicalSortUtil(kv.first);
        }

        cout << sorted.size() << ", " << adj.size() << ", " << visited.size();
        reverse(sorted.begin(), sorted.end());
        return (sorted.size() == visited.size()) ? sorted : "";
    }
};
void ldemo_q269();

//207. Course Schedule [Med]
class Solution_q207 {
public:
    unordered_map<int, list<int>*> adj;
    unordered_map<int, int> visited;

    // step3. during the topological sort, we check if there is any cylic condition.
    bool topologicalSort(int i) {
        visited[i] = 1; // 1: visisting
        for (auto it = adj[i]->cbegin(); it != adj[i]->cend(); ++it) {
            if (visited[*it] == 1)
                return false; //cylic condition, dead lock
            if (visited[*it] == 0)
                if (!topologicalSort(*it))
                    return false;
        }
        visited[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // step1. transform prerequisites into edges
        for (vector<int>& r : prerequisites) {
            if (visited.count(r[0]) == 0) {
                visited[r[0]] = 0;
                adj[r[0]] = new list<int>;
            }
            if (visited.count(r[1]) == 0) {
                visited[r[1]] = 0;
                adj[r[1]] = new list<int>;
            }
            adj[r[0]]->push_back(r[1]);
        }

        // step2. take all the unique keys to do topological sort
        for (auto kv : visited) {
            if (visited[kv.first] == 0) {
                if (!topologicalSort(kv.first)) return false;
            }
        }
        return true;
    }
};
void ldemo_q207();

//210. Course Schedule II [Med] //Using BFS with indegree
class Solution_q210 {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // step0. initialize adjacent list, and indegree for doing bfs topological sort
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);

        // step1. fill adj lists, r[1]: key, r[0]: to vertex node
        for (vector<int>& r : prerequisites) {
            adj[r[1]].push_back(r[0]);
            ++indegree[r[0]];
        }

        // step2. for every unique keys, do topological sort.
        queue<int> q; vector<int> sorted;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop(); --n; sorted.push_back(cur);
            for (int next : adj[cur]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
        if (n != 0) return {};
        return sorted;
    }
};

class Solution_q210_dfs {
public:
    unordered_map<int, list<int>*> adj;
    unordered_map<int, int> visited;
    vector<int> sorted;
    bool topologicalSort(int i) {
        visited[i] = 1; //1: visiting
        for (auto it = adj[i]->cbegin(); it != adj[i]->cend(); ++it) {
            if (visited[*it] == 1) return false; //cylic
            if (visited[*it] == 0)
                if (!topologicalSort(*it)) return false;
        }
        visited[i] = 2;
        sorted.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // step0. initialize adjacent list, and visited map for doing dfs
        for (int i = 0; i < numCourses; ++i) {
            visited[i] == 0;
            adj[i] = new list<int>;
        }
        // step1. fill adj lists
        for (vector<int>& r : prerequisites) {
            adj[r[1]]->push_back(r[0]);
        }

        // step2. for every unique keys, do topological sort.
        for (auto kv : visited) {
            if (visited[kv.first] == 0)
                if (!topologicalSort(kv.first)) return {};
        }
        std::reverse(sorted.begin(), sorted.end());
        return sorted;
    }
};
void ldemo_q210();
#endif