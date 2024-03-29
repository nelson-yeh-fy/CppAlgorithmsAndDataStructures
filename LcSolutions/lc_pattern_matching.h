#ifndef LE_PATTERN_MATCHING_H
#define LE_PATTERN_MATCHING_H
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Solution_q28_b {
    //KMP: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    //https://www.youtube.com/watch?v=BXCEFAzhxGY
public:
    std::vector<int> computeLPS(std::string pat) {
        int n = pat.size();
        std::vector<int> lps(n, 0);

        int len = 0, i = 1;
        while (i < n) {
            if (pat[len] == pat[i]) {
                lps[i++] = ++len;
            }
            else { //(pat[len] != pat[i])
                // Consider the example. 
                // AAACAAAA and i = 7. The idea is similar to search step. 
                if (len != 0) {
                    len = lps[len - 1]; //reset the longest proper prefix length
                    //note that we do not increment i here 
                }
                else { // if (len == 0) 
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int strStr(std::string haystack, std::string pat) {
        //pre-req:
        int m = haystack.size();
        int n = pat.size();
        if (n == 0) return 0;

        std::vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == pat[j]) {
                i++; j++;
            }
            if (j == n) { //matched length == pat.size(), we found one fully matched.
                //print or return here.
                //for strStr, return i-j;
                return i - j;
                //for printing all, j=lps[j-1], print.
                //std::cout << i - j << ",";
                //j = lps[j - 1];
            }
            if (i < m && haystack[i] != pat[j]) { // mismatch after j matches 
                // Do not match lps[0..lps[j-1]] characters, they will match anyway 
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return -1;
    }
};
void ldemo_q28();

//KMP for q214: check this https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation

//459. Repeated Substring Pattern [Easy]: Using KMP
class Solution_q459 {
public:
    //Computer LPS using KMP
    std::vector<int> computeLPS(std::string s) {
        std::vector<int> lps(s.size(), 0);
        int len = 0, i = 1;
        while (i < s.size()) {
            if (s[len] == s[i]) {
                lps[i++] = ++len;
            }
            else {
                if (len) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(std::string s) {
        std::vector<int> lps = computeLPS(s);
        int n = s.size();
        int val = lps[n - 1];
        //check lps[] if the last entry is not zero, 
        //and val % s.size()-val == 0, means it repreats
        if (val > 0 && val % (n - val) == 0)
            return true;
        else
            return false;
    }
};
void ldemo_q459();

//686. Repeated String Match [Easy]
class Solution_q686 {
public:
    std::vector<int> computeLPS(std::string s) {
        int n = s.size();
        std::vector<int> lps(n, 0);
        int len = 0, i = 1;
        while (i < n) {
            if (s[len] == s[i]) {
                lps[i++] = ++len;
            }
            else if (len) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }
    bool KMP(std::string txt, std::string pat) {
        int m = txt.size();
        int n = pat.size();
        std::vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;
        while (i < m) {
            if (txt[i] == pat[j]) {
                ++i; ++j;
            }
            if (j == n)
                return true;

            if (i < m && txt[i] != pat[j]) {
                if (j) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return false;
    }
    int repeatedStringMatch(std::string A, std::string B) {
        if (A.size() == 0 && B.size() == 0) return 1;
        if (A.size() == 0) return -1;

        std::string sb = A;
        while (sb.size() < B.size())
            sb.append(A);

        if (KMP(sb, B))
            return sb.size() / A.size();

        sb.append(A);
        if (KMP(sb, B))
            return sb.size() / A.size();
        else
            return -1;
    }
};
#endif