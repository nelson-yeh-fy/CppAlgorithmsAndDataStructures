#include "pch.h"
#include "../LcSolutions/lc_sample20.h"
#include "../LcSolutions/lc_two_pointers.h"
#include "../LcSolutions/lc_merge_k_ways.h"

namespace {
    TEST(lc_q007_test, NumsTest) {
        Solution_q7_b q;
        EXPECT_EQ(q.reverse(123), 321);
        EXPECT_EQ(q.reverse(-123), -321);
        EXPECT_EQ(q.reverse(2147483647), 0);
    }
    TEST(lc_q008_test, NumsTest) {
        Solution_q8_b q;
        EXPECT_EQ(q.myAtoi("123"), 123);
        EXPECT_EQ(q.myAtoi("-123"), -123);
        EXPECT_EQ(q.myAtoi(" 1 2 3 "), 1);
        EXPECT_EQ(q.myAtoi(" -123 "), -123);
        EXPECT_EQ(q.myAtoi(" -12-3 "), -12);
        EXPECT_EQ(q.myAtoi(" 123%^"), 123);
        EXPECT_EQ(q.myAtoi("   -42"), -42);
        EXPECT_EQ(q.myAtoi("21474836474"), INT_MAX);
        EXPECT_EQ(q.myAtoi("4193 with words"), 4193);
        EXPECT_EQ(q.myAtoi("words and 987"), 0);
        EXPECT_EQ(q.myAtoi("-91283472332"), INT_MIN);
        EXPECT_EQ(q.myAtoi("3.14159"), 3);
        EXPECT_EQ(q.myAtoi("+1"), 1);
        EXPECT_EQ(q.myAtoi("-1"), -1);
        EXPECT_EQ(q.myAtoi("+-1"), 0);
        EXPECT_EQ(q.myAtoi("2147483646"), 2147483646);
    }
    TEST(lc_q009_test, isPalindrome) {
        Solution_q9_a q;
        EXPECT_EQ(q.isPalindrome(121), true);
        EXPECT_EQ(q.isPalindrome(-121), false);
        EXPECT_EQ(q.isPalindrome(10), false);
    }
    TEST(lc_q014_test, longestCommonPrefix) {
        Solution_q14 s;
        std::vector<std::string> words1 = { "flower","flow","flight" };
        EXPECT_EQ(s.longestCommonPrefix(words1), "fl");
        std::vector<std::string> words2 = { "", "" };
        EXPECT_EQ(s.longestCommonPrefix(words2), "");
        std::vector<std::string> words3 = { "cat", "efft", "tt" };
        EXPECT_EQ(s.longestCommonPrefix(words3), "");
        std::vector<std::string> words4 = { "aa", "a" };
        EXPECT_EQ(s.longestCommonPrefix(words4), "a");
    }
    TEST(lc_q017_test, letterCombinations) {
        Solution_q17_a s;
        std::vector<std::string> exp1 = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
        std::vector<std::string> res1 = s.letterCombinations("23");
        std::sort(exp1.begin(), exp1.end());
        std::sort(res1.begin(), res1.end());
        EXPECT_EQ(exp1, res1);

        std::vector<std::string> exp2 = { "a","b","c" };
        std::vector<std::string> res2 = s.letterCombinations("2");
        std::sort(exp2.begin(), exp2.end());
        std::sort(res2.begin(), res2.end());
        EXPECT_EQ(exp2, res2);

        std::vector<std::string> exp3 = { "gcd","gce","gcf","gbd","gbe","gbf","gad","gae","gaf","hcd","hce","hcf","hbd","hbe","hbf","had","hae","haf","icd","ice","icf","ibd","ibe","ibf","iad","iae","iaf" };
        std::vector<std::string> res3 = s.letterCombinations("423");
        std::sort(exp3.begin(), exp3.end());
        std::sort(res3.begin(), res3.end());
        EXPECT_EQ(exp3, res3);
    }
    TEST(lc_q056_test, mergeIntervals) {
        Solution_q56_a q;
        std::vector<std::vector<int>> in1 = { {1,3},{2,6},{8,10},{15,18} };
        std::vector<std::vector<int>> in2 = { {2,6},{8,10},{1,3},{15,18} };
        std::vector<std::vector<int>> res2 = { {1,6},{8,10},{15,18} };
        EXPECT_EQ(q.merge(in1), res2);
        EXPECT_EQ(q.merge(in2), res2);
        std::vector<std::vector<int>> in3 = { {1,4},{4,5} };
        std::vector<std::vector<int>> res3 = { {1,5} };
        EXPECT_EQ(q.merge(in3), res3);
        std::vector<std::vector<int>> in4 = { {1,3} };
        std::vector<std::vector<int>> res4 = { {1,3} };
        EXPECT_EQ(q.merge(in4), res4);
        std::vector<std::vector<int>> in5 = { };
        std::vector<std::vector<int>> res5 = { };
        EXPECT_EQ(q.merge(in5), res5);
        std::vector<std::vector<int>> in6 = { {1, 4},{0, 2},{3, 5}};
        std::vector<std::vector<int>> res6 = { {0, 5} };
        EXPECT_EQ(q.merge(in6), res6);
    }

};