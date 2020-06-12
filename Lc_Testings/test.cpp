#include "pch.h"
#include "../CtCISolutions/lc_sample20.h"

TEST(lc_q5_test, emptyString) {
    Solution_q5_b q;
    EXPECT_EQ(q.longestPalindrome(""), "");
    EXPECT_TRUE(true);
}
TEST(lc_q5_test, normalStrings) {
    Solution_q5_b q;
    EXPECT_EQ(q.longestPalindrome("babad"), "bab");
    EXPECT_EQ(q.longestPalindrome("cbbd"), "bb");
    EXPECT_EQ(q.longestPalindrome("a"), "a");
    EXPECT_EQ(q.longestPalindrome("ac"), "a");
    EXPECT_EQ(q.longestPalindrome("ccd"), "cc");
    EXPECT_EQ(q.longestPalindrome("abaqweewq"), "qweewq");
    EXPECT_EQ(q.longestPalindrome("abaqwejewq"), "qwejewq");
    EXPECT_TRUE(true);
}
TEST(lc_q5_test, SameCharStrings) {
    Solution_q5_b q;
    EXPECT_EQ(q.longestPalindrome("aaa"), "aaa");
    EXPECT_EQ(q.longestPalindrome("aaaa"), "aaaa");
    EXPECT_EQ(q.longestPalindrome("aaaaa"), "aaaaa");
    EXPECT_EQ(q.longestPalindrome("aaaaaa"), "aaaaaa");
    EXPECT_TRUE(true);
}
