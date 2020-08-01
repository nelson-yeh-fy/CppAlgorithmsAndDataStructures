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

//438. Find All Anagrams in a String [Med]
class Solution_q438 {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.size() < p.size()) return {};
        std::vector<char> sv(26, 0), pv(26, 0);
        std::vector<int> res;
        int sn = s.size(), pn = p.size();
        //fill sv and pv, vector to record char counts.
        for (int i = 0; i < pn; ++i) {
            ++sv[s[i] - 'a'];
            ++pv[p[i] - 'a'];
        }
        //if sv==pv, means regardless the order they're the same (anagram)
        //this takes O(26)/O(1) to compare
        if (sv == pv) res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for (int i = p.size(); i < sn; ++i) {
            //sliding window extend one char to the right.
            ++sv[s[i] - 'a'];
            //sliding window remove one char from the left.
            --sv[s[i - p.size()] - 'a'];
            //since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
            if (sv == pv) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
void ldemo_q438();

//209. Minimum Size Subarray Sum
class Solution_q209 {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        //pre-req:
        if (nums.empty()) return {};
        int sum = 0, count = 0, min = INT32_MAX;
        int l = 0, n = nums.size();

        //step1: traverse nums, and keep adding it to Sum, O(N)
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            ++count;
            //check if sum > s, slide the window from l to r, try to minimize. O(N)
            while (sum >= s) {
                min = std::min(min, count);
                sum -= nums[l++];
                --count;
            }
        }
        return (min == INT32_MAX) ? 0 : min;
    }
};

//28. Implement strStr() [Easy] => check KMP algorithm instead.
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