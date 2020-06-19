#ifndef LE_TWO_POINTERS_H
#define LE_TWO_POINTERS_H
#include <iostream>

//5. Longest Palindromic Substring 
class Solution_q5 {    
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        size_t i = 0, left = 0, right = 0; //runner index, left index, right index
        std::string maxStr = "";

        while (i < s.size()) {
            //step1.find palindrome seeds:
            left = i;
            right = i;
            while (right < s.size() - 1 && s[right] == s[right + 1])
                right++;
            i = right + 1;

            //step2.extend the palindrome and find its length
            while (left > 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            //step3.get the longest palindrome
            maxStr = (maxStr.size() < right - left + 1) ? s.substr(left, right - left + 1) : maxStr;
        }
        return maxStr;
    }
};

//214. Shortest Palindrome
//a starts from far right, but will take O(N*N) time worse case for "aaaaaaaa...aaa"
class Solution_q214_a { 
public:
    std::string shortestPalindrome(std::string s) {

        if (s.size() < 2) return s;

        //Step1. Find the anchor index from far right, anchor index is for adding chars in front of string.
        int anc = s.size(), r_ptr = anc;
        bool found = false;

        while (!found && anc > 0) {
            //find possible anchors
            anc--;
            int l_ptr = 0;
            while (s[anc] != s[l_ptr]) {
                anc--;
            }
            r_ptr = anc;

            //start from anchor, check if the string is a palindrome
            while (l_ptr < r_ptr && s[l_ptr] == s[r_ptr]) {
                l_ptr++;
                r_ptr--;
            }
            found = (l_ptr < r_ptr) ? false : true;
        }

        //Step2. Fill chars started from anchor index to the string end, in front of the string to make it palindrome
        std::string tmp = s.substr(anc+1, s.size()-anc);
        std::reverse(tmp.begin(), tmp.end());
        /*for (int i = s.size() - 1; i > anc; --i) {
            tmp.push_back(s[i]);
        }*/
        return tmp.append(s);
    }
};
//b starts from far left, use lc_q5_technique
class Solution_q214_b {
public:
    std::string shortestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        int i = 0, left = 0, right = 0, max_ptr = 0;

        while (i <= s.size() / 2) {
            //Step1. find possible palidrome seeds first, [l_ptr<->r_ptr] is possible seeds.
            left = i;
            right = i;
            while (s[left] == s[right + 1])
                right++;
            i = right + 1;

            //Step2. extend the seed for a complete palindrome.
            while (left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }

            //Step3. get the shortest (l_ptr==0, r_ptr is the closest to far right)
            if (left == 0 && max_ptr < right)
                max_ptr = right;
        }

        //Step4. Fill chars started from anchor index to the string end, in front of the string to make it palindrome
        std::string tmp = s.substr(max_ptr + 1, s.size() - max_ptr);
        std::reverse(tmp.begin(), tmp.end());
        return tmp.append(s);
    }
};
void ldemo_q214();

#endif