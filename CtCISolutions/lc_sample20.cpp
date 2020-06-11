#include <iostream>
#include "lc_sample20.h"

using namespace std;

void ldemo_q1_a() {

    Solution_q1_a s;
    vector<int> nums = { 23,5,2,1,8,12,16 };
    int target = 9;

    vector<int> indices = s.twoSum(nums, target);
}

void ldemo_q1_b() {

    Solution_q1_b s;
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

void ldemo_q1_c() {

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

void ldemo_q3_a() {

    Solution_q3_a s;
    std::string str = "advcdek";
    str = "pwwkew";
    str = "wkewi";
    //str = "adbcvd";
    
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
}

void ldemo_q4_a()
{
    Solution_q4_a q4;
    std::vector<int> n1 = { 1,3 };
    std::vector<int> n2 = { 2,4 };
    std::cout << q4.findMedianSortedArrays(n1, n2);
}

void ldemo_q4_b()
{
    Solution_q4_b q4;
    std::list<int> n1 = { 1,3 };
    std::list<int> n2 = { 2,4 };
    std::cout << q4.findMedianSortedArrays(n1, n2);
}

void ldemo_q5_a()
{
    Solution_q5_a q;
    std::string s = "babad";
    //s = "cbbd";
    //s = "abbava";
    //s = "abbavakqweiewqk";
    //s = "ccd";
    //s = "cc";
    //s = "ccc";
    //s = "cccc";
    s = "ac";
    std::cout << q.longestPalindrome(s);
}

