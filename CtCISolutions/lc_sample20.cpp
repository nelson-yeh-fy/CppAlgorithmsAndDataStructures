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