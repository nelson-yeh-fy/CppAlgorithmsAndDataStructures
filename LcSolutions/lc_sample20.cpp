#include <iostream>
#include "lc_sample20.h"

using namespace std;

void ldemo_q1() {
    Solution_q1_c s;
    //vector<int> nums = { 23,5,2,1,8,12,16 };
    //int target = 7;

    //vector<int> nums = { 3, 3 };
    //int target = 6;

    //vector<int> nums = { -3,4,3,90 };
    //int target = 0;

    vector<int> nums = { 0, 3, -3, 4, -1 };
    int target = 0;

    vector<int> indices = s.twoSum(nums, target);
}

void ldemo_q3() {
    Solution_q4_a q4;
    std::vector<int> n1 = { 1,3 };
    std::vector<int> n2 = { 2,4 };
    std::cout << q4.findMedianSortedArrays(n1, n2);
}

void ldemo_q4(){
    Solution_q4_b q4;
    std::list<int> n1 = { 1,3 };
    std::list<int> n2 = { 2,4 };
    std::cout << q4.findMedianSortedArrays(n1, n2);
}

void ldemo_q5(){
    Solution_q5_b q;
    std::string s = "babad";
    s = "cbbd";
    s = "abbava";
    s = "abbavakqweiewqk";
    s = "ccd";
    s = "cc";
    s = "ccc";
    s = "cccc";
    s = "ac";
    s = "a";
    std::cout << q.longestPalindrome(s);
}

