#ifndef LE_SLIDING_WINDOW_H
#define LE_SLIDING_WINDOW_H
#include <iostream>
#include <vector>
#include <algorithm>

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

class Solution_q28_b {
    //KMP: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    //https://www.youtube.com/watch?v=BXCEFAzhxGY
public:
    std::vector<int> computeLPS(std::string pat) {
        int n = pat.size();
        std::vector<int> lps(n, 0);

        int len = 0, i = 1;
        while (i<n) {
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
            if (j==n) { //matched length == pat.size(), we found one fully matched.
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
                    i = i + 1;
                else
                    j = lps[j - 1];
            }
        }
        return -1;
    }
};
void ldemo_q28();

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

        int i = 0;
        for (i; i < lps.size(); ++i) {
            if (lps[i] == 1) break;
        }

        int j = 1;
        while (i < lps.size()) {
            if (lps[i] == j) {
                ++i;
                ++j;
             }
            else {
                return false;
            }
        }
        return true;
    }
};
void ldemo_q459();
#endif