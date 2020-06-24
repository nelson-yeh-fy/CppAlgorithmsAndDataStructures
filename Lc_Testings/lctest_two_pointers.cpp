#include "pch.h"
#include "../LcSolutions/lc_sample20.h"
#include "../LcSolutions/lc_two_pointers.h"
namespace {
    TEST(TwoPointers, lc_q005_Longest_Palindromic_Substring) {
        Solution_q5_d q;
        EXPECT_EQ(q.longestPalindrome(""), "");
        EXPECT_EQ(q.longestPalindrome("babad"), "bab");
        EXPECT_EQ(q.longestPalindrome("cbbd"), "bb");
        EXPECT_EQ(q.longestPalindrome("a"), "a");
        EXPECT_EQ(q.longestPalindrome("ac"), "a");
        EXPECT_EQ(q.longestPalindrome("ccd"), "cc");
        EXPECT_EQ(q.longestPalindrome("abaqweewq"), "qweewq");
        EXPECT_EQ(q.longestPalindrome("abaqwejewq"), "qwejewq");
        EXPECT_EQ(q.longestPalindrome("aaa"), "aaa");
        EXPECT_EQ(q.longestPalindrome("aaaa"), "aaaa");
        EXPECT_EQ(q.longestPalindrome("aaaaa"), "aaaaa");
        EXPECT_EQ(q.longestPalindrome("aaaaaa"), "aaaaaa");
    }
    TEST(TwoPointers, lc_q15_threeSum) {
        Solution_q15_a q;
        std::vector<std::vector<int>> result;
        result.push_back(std::vector<int>{-3, 0, 3});
        EXPECT_EQ(q.threeSum(std::vector<int>{1, 0, 3, -3}), result);
    }
    TEST(TwoPointers, lc_q214_Shortest_Palindrome) {
        Solution_q214_b q;
        EXPECT_EQ(q.shortestPalindrome(""), "");
        EXPECT_EQ(q.shortestPalindrome("aacecaaa"), "aaacecaaa");
        EXPECT_EQ(q.shortestPalindrome("abcd"), "dcbabcd");
    }
    TEST(TwoPointers, lc_q125_isPalindrome) {
        Solution_q125 q;
        EXPECT_EQ(q.isPalindrome("A man, a plan, a canal: Panama"), true);
        EXPECT_EQ(q.isPalindrome("race a car"), false);
        EXPECT_EQ(q.isPalindrome("ab, c"), false);
        EXPECT_EQ(q.isPalindrome("ab, a"), true);
        EXPECT_EQ(q.isPalindrome(".,"), true);
        EXPECT_EQ(q.isPalindrome("..."), true);
    }
    TEST(TwoPointers, lc_q259_threeSumSmaller) {
        Solution_q259_c q;
        EXPECT_EQ(q.threeSumSmaller(std::vector<int>{ -2, 0, 1, 3 }, 2), 2);
        EXPECT_EQ(q.threeSumSmaller(std::vector<int>{ -3, 0, 1, 5 }, 4), 3);
        EXPECT_EQ(q.threeSumSmaller(std::vector<int>{ 1, 2, 3, 4 }, 3), 0);
    }

};