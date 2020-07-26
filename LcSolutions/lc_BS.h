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

//to-do:
//62. Unique Paths [Med]
//658. Find K Closest Elements [Med]
//718. Maximum Length of Repeated Subarray [Med]
//782. Transform to Chessboard [Hard]




/*
 * Below questions are too easy, the only takeaway is to find the lower bound.
 */
//35. Search Insert Position [Easy] (find lower bound)
class Solution_q35 {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else if (nums[mid] > target)
                hi = mid - 1;
        }
        return lo;
    }
};

//278. First Bad Version [Easy] (find lower bound)
class Solution_q278 {
public:
    bool isBadVersion(int version) {
        return true; //fake here, leetcode has real api.
    }
    int firstBadVersion(int n) {
        //Use BS to find the first bad version, get the lower bound
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; //(lo+hi)/2 also works in normal case, but overflow when int is not enough (e.g.: 2126753390 + 2126753390)
            if (isBadVersion(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

//374. Guess Number Higher or Lower [Easy]
class Solution_q374 {
public:
    int guess(int) {
        return 0; //fake API, leetcode has working API.
    }
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            switch (guess(mid)) {
            case 0:
                return mid;
            case -1:
                hi = mid - 1;
                break;
            case 1:
                lo = mid + 1;
                break;
            }
        }
        return (lo <= n) ? lo : n;
    }
};
//375. Guess Number Higher or Lower II [Med]: requirement not clear, pass this one.
#endif