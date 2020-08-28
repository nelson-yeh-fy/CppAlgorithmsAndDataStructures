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

#endif