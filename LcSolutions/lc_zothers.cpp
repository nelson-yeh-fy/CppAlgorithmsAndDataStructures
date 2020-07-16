#include <iostream>
#include "lc_zothers.h"
#include "ds.h"
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

void ldemo_q4() {
    Solution_q4_b q4;
    std::list<int> n1 = { 1,3 };
    std::list<int> n2 = { 2,4 };
    std::cout << q4.findMedianSortedArrays(n1, n2);
}

void ldemo_q6() {
    Solution_q6_b q;
    std::string s = "PAYPALISHIRING";
    //s = "cbbd";
    std::cout << q.convert(s, 3);
}

void ldemo_q7() {
    Solution_q7_b q;
    int t = 123;
    t = 2147483647;
    std::cout << "Original:" << t << ",Rev:" << q.reverse(t);
}

void ldemo_q8() {
    Solution_q8_b q;
    std::string s = "-123";
    s = "+123";
    s = "2147483646";
    std::cout << "Original:" << s << ",atoi:" << q.myAtoi(s);
}

void ldemo_q9() {
    Solution_q9_b q;
    int i = INT32_MAX;
    std::cout << "Original:" << i << ", isPalindrome?:" << q.isPalindrome(i);
}

void ldemo_q17() {
    Solution_q17_a s;
    std::vector<std::string> words = s.letterCombinations("23");
    for (const string& word : words) {
        cout << "{" << word << "},";
    }
}

void ldemo_q20()
{
    Solution_q20 s;
    std::string str = "{[]()[()]}";
    std::cout << s.isValid(str);
}

void ldemo_q24()
{
    Solution_q24 s;
    ListNode* a4 = new ListNode(4);
    ListNode* a3 = new ListNode(3, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    ListNode* res = s.swapPairs(a1);
    while (res) {
        std::cout << res->val << ",";
    }
}


