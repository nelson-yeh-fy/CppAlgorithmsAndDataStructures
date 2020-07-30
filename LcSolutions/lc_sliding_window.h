#ifndef LE_SLIDING_WINDOW_H
#define LE_SLIDING_WINDOW_H
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

//3. Longest Substring Without Repeating Characters [Med]
class Solution_q3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> set;
        int l = 0, max = 0, n = s.size();
        for (int r = 0; r < n; ++r) {
            if (!set.count(s[r])) {
                set.insert(s[r]);
            }
            else {
                //Slide the window [l++..r], remove s[l] from set
                while (s[l] != s[r] && l != r) {
                    set.erase(s[l++]);
                }
                set.erase(s[l++]);
                set.insert(s[r]);
            }
            max = std::max(max, r - l + 1);
        }
        return max;
    }
};
void ldemo_q3();

//to-do:
//209. Minimum Size Subarray Sum

//28. Implement strStr() [Easy]
class Solution_q28_a {
    //Naive solution
public:
    int strStr(std::string haystack, std::string pat) {
        //pre-req:
        int m = haystack.size();
        int n = pat.size();
        if (n == 0) return 0;
        if (m == 0 || m < n) return -1;

        //step1. traverse the string, check needle string
        for (int i = 0; i < m - n + 1; ++i) {
            //step2. check needle string
            for (int j = 0; j < n; ++j) {
                if (haystack[i + j] == pat[j] && j == n - 1)
                    return i;
                else if (haystack[i + j] != pat[j])
                    break;
            }
        }
        return -1;
    }
};

#endif