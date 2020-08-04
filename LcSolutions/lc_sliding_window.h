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

//76. Minimum Window Substring [Hard]
class Solution_q76_a {
public:
    bool specialCompare(std::vector<int>& sv, std::vector<int>& pv) {
        if (sv.size() < pv.size()) return false;
        //if any of sv's count is smaller than pv's count, 
        //means it doesn't cover all chars in pv, return false;
        int pn = pv.size();
        for (int i = 0; i < pn; ++i) {
            if (sv[i] < pv[i])
                return false;
        }
        return true;
    }
    std::string minWindow(std::string s, std::string p) {
        //pre-req:
        if (s.size() < p.size()) return "";
        int sn = s.size(), pn = p.size();
        std::string res, min_res = s;

        //step1: assume s,p only contain a-z here. build vector to store its count.
        std::vector<int> sv(58, 0), pv(58, 0);
        for (int i = 0; i < pn; ++i) {
            ++sv[s[i] - 'A'];
            ++pv[p[i] - 'A'];
        }
        if (sv == pv) return(s.substr(0, pn));

        //step2: traverse s, find windows fulfill the condition.
        for (int l = 0, r = pn; r < sn; ++r) {
            //sliding window extend one char to the right.
            ++sv[s[r] - 'A'];
            //since both vectors are of fixed size 58. Total complexity O(n)*O(1) = O(n)
            //if sv covers all pv chars, we try to shrink the window:
            if (specialCompare(sv, pv)) {
                do {
                    res = s.substr(l, r - l + 1);
                    min_res = (min_res.size() < res.size()) ? min_res : res;
                    //sliding window remove one char from the left.
                    --sv[s[l] - 'A'];
                    ++l;
                } while (l < sn && sv[s[l - 1] - 'A'] >= pv[s[l - 1] - 'A']);
            }
            /*while (specialCompare(sv, pv)) {
                res = s.substr(l, r - l + 1);
                min_res = (min_res.size() < res.size()) ? min_res : res;
                if(min_res.size() == p.size()) return min_res;
                //sliding window remove one char from the left.
                --sv[s[l] - 'A'];
                ++l;
            }*/
        }
        return res.empty() ? "" : min_res;
    }
};
class Solution_q76_b {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        int sn = s.size(), tn = t.size();
        std::vector<int> tv(128, 0);

        //step1: count chars in string t, get total chars count
        int required = t.size();
        for (int i = 0; i < tn; ++i) ++tv[t[i]];

        //step2: compare chars in s and t, decrease remaining count if matches.
        int min = INT32_MAX;
        int l = 0, lslide = 0, r = 0;
        while (l < sn && r < sn + 1) {
            if (required > 0) {
                if (r == sn) break;
                //decrease one, if the count is still >=0, means it was required
                --tv[s[r]];
                if (tv[s[r]] >= 0) --required;
                ++r;
            }
            else {
                if (r - lslide < min) {
                    l = lslide;
                    min = r - l;
                }
                //increase one, if the count becomes > 0, 
                //means we s[l] is required but we slided and removed it.
                ++tv[s[lslide]];
                if (tv[s[lslide]] > 0) ++required;
                ++lslide;
            }
        }
        return (min == INT32_MAX) ? "" : s.substr(l, min);
    }
};
void ldemo_q76();

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