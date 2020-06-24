#include "pch.h"
#include "../LcSolutions/lc_sample20.h"
#include "../LcSolutions/lc_two_pointers.h"
namespace {
    TEST(lc_q7_test, NumsTest) {
        Solution_q7_b q;
        EXPECT_EQ(q.reverse(123), 321);
        EXPECT_EQ(q.reverse(-123), -321);
        EXPECT_EQ(q.reverse(2147483647), 0);
    }
    TEST(lc_q8_test, NumsTest) {
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
    TEST(lc_q9_test, isPalindrome) {
        Solution_q9_a q;
        EXPECT_EQ(q.isPalindrome(121), true);
        EXPECT_EQ(q.isPalindrome(-121), false);
        EXPECT_EQ(q.isPalindrome(10), false);
    }

};