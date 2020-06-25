#include <iostream>
#include "lc_two_pointers.h"

void ldemo_q5() {
    Solution_q5_d q;
    std::string s = "babad";
    //s = "cbbd";
    //s = "abbava";
    //s = "abbavakqweiewqk";
    //s = "ccd";
    //s = "cc";
    //s = "ccc";
    //s = "cccc";
    //s = "ac";
    //s = "a";
    //s = "aaaa";
    std::cout << q.longestPalindrome(s);
}
void ldemo_q15() {
    Solution_q15_a q;
    std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    nums = { 0, 0, 0, 0 };
    std::vector<std::vector<int>> results = q.threeSum(nums);
}
void ldemo_q16() {
    Solution_q16 q;
    std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    nums = { 0, 0, 0, 0 };
    int target = 2;
    std::cout << q.threeSumClosest(nums, target);
}
void ldemo_q214() {
    Solution_q214_b q;
    std::string s = "aabaaa";
    //s = "abcd";
    //s = "abbava";
    //s = "aaaa";
    std::cout << q.shortestPalindrome(s);
}
void ldemo_q125() {
    Solution_q125 q;
    std::string s = "aabaaa";
    s = "A man, a plan, a canal: Panama";
    //s = "race a car";
    s = "...";
    std::cout << q.isPalindrome(s);
}
void ldemo_q259() {
    Solution_q259_c q;
    std::vector<int> nums = { -2, 0, 1, 3 };

    int target = 2;
    std::cout << q.threeSumSmaller(nums, target);
}