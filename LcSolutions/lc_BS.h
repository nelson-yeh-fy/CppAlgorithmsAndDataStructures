#ifndef LE_BS_H
#define LE_BS_H
#include <iostream>
#include <vector>

//33. Search in Rotated Sorted Array [Med]
class Solution_q33_a {
public:
    //nums[0] > target && nums[0] > nums[mid], or nums[0] <= target && nums[0] <= nums[mid]
    //means target and nums[mid] are in the same side (in terms of separting from pivot)
    //https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
    //https://leetcode.wang/leetCode-33-Search-in-Rotated-Sorted-Array.html
    int search(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            double num = (nums[mid] < nums[0]) == (target < nums[0])
                ? nums[mid]
                : target < nums[0] ? -INFINITY : INFINITY;

            if (num < target)
                lo = mid + 1;
            else if (num > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};
class Solution_q33_b {
public:
    //https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
    //https://leetcode.wang/leetCode-33-Search-in-Rotated-Sorted-Array.html
    int search(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target == nums[mid]) return mid;

            //if nums[lo..mid] are accessdending, means pivot is not in this section.
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};
void ldemo_q33();

//34. Find First and Last Position of Element in Sorted Array [Med]
class Solution_q34 {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        //step1. since it's a sorted array, we can use binary search to find the target.
        int seed = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                seed = mid;
                break;
            }
            if (nums[lo] <= target && target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        //step2. once we found the target, extend it until the value is different.
        int seed_l = seed, seed_r = seed;
        while (seed_l > 0 && nums[seed_l - 1] == target)
            --seed_l;
        while (seed_r >= 0 && seed_r < nums.size() - 1 && nums[seed_r + 1] == target)
            ++seed_r;
        return { seed_l, seed_r };
    }
};
#endif