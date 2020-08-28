#ifndef LE_TS_H
#define LE_TS_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "ds.h"


//269. Alien Dictionary [Hard]
class Solution_q269 {
public:
    void topologicalSortUtil(int idx, std::list<char>* adj, std::stack<char> &sorted, std::vector<bool> &visited) {
        // Mark the current node as visited. 
        visited[idx] = true;
        // Recur for all the vertices adjacent to this vertex 
        for (auto it = adj[idx].cbegin(); it != adj[idx].cend(); ++it) {
            if (visited[(*it) - 'a'] == false)
                topologicalSortUtil((*it) - 'a', adj, sorted, visited);
        }
        // Push current vertex to stack which stores result 
        sorted.push(idx + 'a');
        return;
    }
    std::string alienOrder(std::vector<std::string>& words) {
        if (words.empty()) return "";
        std::string ret;
        std::list<char>* adj = new std::list<char>[26];
        std::vector<bool> visited (26, false);
        std::stack<char> sorted;

        //break all words into edges, e.g.: wrt: w(w-'a')->r, r(r-'a')->t
        for (std::string& word : words) {
            for (int i = 0; i < word.size() - 1; ++i)
                adj[word[i] - 'a'].push_back(word[i + 1]);
        }

        //all characters in words need topological sort
        for (std::string& word : words){
            for (char& c : word) {
                if (visited[c-'a'] == false)
                    topologicalSortUtil(c-'a', adj, sorted, visited);
            }
        }

        while (!sorted.empty()) {
            ret.push_back(sorted.top());
            sorted.pop();
        }
        return ret;
    }
};
void ldemo_q269();

#endif