#ifndef LE_DP_H
#define LE_DP_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <forward_list>
#include <queue>
#include <stack>
#include "ds.h"

//Classical

//283. Move Zeroes [Easy] Classic question to present the thinking process.
class Solution_q283 {
public:
    void moveZeroes(std::vector<int>& nums) {
        int slow = 0, fast = 0, n = nums.size();
        //step1. find the first '0' for the slow_ptr
        while (slow < n && nums[slow] != 0) ++slow;

        //step2. move all non-zero val to left.
        fast = slow + 1;
        while (fast < n) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }

        //step3. fill zero to the tail.
        while (slow < n) nums[slow++] = 0;
    }
};

//121. Best Time to Buy and Sell Stock [Easy]
class Solution_q121 {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfit(std::vector<int>& prices) {
        int T_i10 = 0, T_i11 = INT32_MIN;

        for (const int& p : prices) {
            T_i10 = std::max(T_i10, T_i11 + p);
            T_i11 = std::max(T_i11, -p);
        }
        return T_i10;
    }
    /*int maxProfit(std::vector<int>& prices) {
        int buy = INT32_MAX;
        int maxProfit = 0, n = prices.size();
        for (int p : prices) {
            maxProfit = std::max(maxProfit, p - buy);
            buy = std::min(buy, p);
        }
        return maxProfit;
    }*/
};

//122. Best Time to Buy and Sell Stock II [Easy]
class Solution_q122 {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfit(std::vector<int>& prices) {
        int T_i0 = 0, T_i1 = INT32_MIN;

        for (const int& p : prices) {
            T_i0 = std::max(T_i0, T_i1 + p);
            T_i1 = std::max(T_i1, T_i0 - p);
        }
        return T_i0;
    }
};

//123. Best Time to Buy and Sell Stock III [Hard], DP

//[MUST READ] https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/539127/Detailed-explanation-of-DP-solution-inspired-by-%40meng789987
class Solution_q123_a {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfit(std::vector<int>& prices) {
        const int K = 2;
        std::vector<int> T_i0(K + 1, 0), T_i1(K + 1, INT32_MIN);
        for (const int& p : prices) {
            for (int i = 2; i > 0; --i) {
                T_i0[i] = std::max(T_i0[i], T_i1[i] + p);
                T_i1[i] = std::max(T_i1[i], T_i0[i - 1] - p);
            }
        }
        return T_i0[K];
    }
};
class Solution_q123_b {
public:
    int maxProfit(std::vector<int>& prices) {
        int k_trans = 2;
        if (prices.empty()) return 0;
        std::vector<int> min(k_trans + 1, prices[0]);
        std::vector<int> dp(k_trans + 1, 0);
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= k_trans; ++k) {
                min[k] = std::min(min[k], prices[i] - dp[k - 1]);
                dp[k] = std::max(dp[k], prices[i] - min[k]);
            }
        }
        return dp[k_trans];
    }
};
void ldemo_q123();

//188. Best Time to Buy and Sell Stock IV [Hard] 
class Solution_q188 {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfitForLargeK(std::vector<int>& prices) {
        int T_i0 = 0, T_i1 = INT32_MIN;
        for (const int& p : prices) {
            T_i0 = std::max(T_i0, T_i1 + p);
            T_i1 = std::max(T_i1, T_i0 - p);
        }
        return T_i0;
    }

    int maxProfit(int K, std::vector<int>& prices) {
        if (K >= prices.size() / 2) return maxProfitForLargeK(prices);

        std::vector<int> T_i0(K + 1, 0), T_i1(K + 1, INT32_MIN);
        for (const int& p : prices) {
            for (int i = K; i > 0; --i) {
                T_i0[i] = std::max(T_i0[i], T_i1[i] + p);
                T_i1[i] = std::max(T_i1[i], T_i0[i - 1] - p);
            }
        }
        return T_i0[K];
    }
};

//714. Best Time to Buy and Sell Stock with Transaction Fee [Med]
class Solution_q714 {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfit(std::vector<int>& prices, int fee) {
        long T_i0 = 0, T_i1 = INT32_MIN;
        for (const int& p : prices) {
            T_i0 = std::max(T_i0, T_i1 + p - fee);
            T_i1 = std::max(T_i1, T_i0 - p);
        }
        return T_i0;
    }
};

//309. Best Time to Buy and Sell Stock with Cooldown [Med]
class Solution_q309 {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int maxProfit(std::vector<int>& prices) {
        int T_i0 = 0, T_i1 = INT32_MIN;
        int T_i0_pre = 0;
        for (const int& p : prices) {
            int T_i0_old = T_i0;
            T_i0 = std::max(T_i0, T_i1 + p);
            T_i1 = std::max(T_i1, T_i0_pre - p);
            T_i0_pre = T_i0_old;
        }
        return T_i0;
    }
};

//198. House Robber [Easu] DP, the same with Stock series.
class Solution_q198 {
public:
    //T (MaxProfit), i-th house to rob, 
    //Recurrance relation: T[i] = std::max(T[i], T[i-2] + nums[i])
    //means either do nothing, or rob this house with i-2, make it not adjacent.
    int rob(std::vector<int>& nums) {
        int T_i = 0, T_i_pre = 0;
        for (const int& p : nums) {
            int T_i_old = T_i;
            T_i = std::max(T_i, T_i_pre + p);
            T_i_pre = T_i_old; //make T_i_pre equals to i-2.
        }
        return T_i;
    }
};

class Solution_q213 {
public:
    //T (MaxProfit), i-th house to rob, 
    //Recurrance relation: T[i] = std::max(T[i], T[i-2] + nums[i])
    //means either do nothing, or rob this house with i-2, make it not adjacent.
    int rob(std::vector<int>& nums, int start, int end) {
        int T_i = 0, T_i_pre = 0;
        for (int i = start; i <= end; ++i) {
            int T_i_old = T_i;
            T_i = std::max(T_i, T_i_pre + nums[i]);
            T_i_pre = T_i_old; //make T_i_pre equals to i-2.
        }
        return T_i;
    }
    //separate this problem to rob [0..n-2] & [1..n-1]
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return std::max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};

#endif