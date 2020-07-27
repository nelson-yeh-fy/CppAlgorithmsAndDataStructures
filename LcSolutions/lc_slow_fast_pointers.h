#ifndef LE_SLOW_FAST_POINTERS_H
#define LE_SLOW_FAST_POINTERS_H
#include <iostream>
#include <vector>
#include "ds.h"

//2. Add Two Numbers [Med]
class Solution_q2_a {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode();
        ListNode* head = result;
        int sum = 0;

        //traverse l1 and l2 at the same time, the order start from the beginging.
        while (l1 != nullptr || l2 != nullptr) {

            sum = sum / 10;
            if (l1 == nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            else {
                sum += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            ListNode* n = new ListNode(sum % 10);
            head->next = n;
            head = head->next;
        }

        if (sum / 10 > 0) {
            ListNode* n = new ListNode(sum / 10);
            head->next = n;
            head = head->next;
        }

        return result->next;
    }
};
//concise version but worse performance
class Solution_q2_b {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode(0), * ptr = result;
        int carry = 0;

        //traverse l1 and l2 at the same time, the order start from the beginging.
        while (l1 || l2 || carry != 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode* n = new ListNode(sum % 10);
            ptr->next = n;
            ptr = n;

            l1 = (l1 ? l1->next : nullptr); //check nullptr again, drag performance
            l2 = (l2 ? l2->next : nullptr);
        }
        return result->next;
    }
};
//19. Remove Nth Node From End of List [Med]
class Solution_q19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //pre-req:
        if (n <= 0) return head;
        if (!head) return nullptr;

        //step1. Setup a runner pointer (slow) to chase (fast) pointer, 
        //when fast pointer hit the end, the slow pointer is where we're looking for.
        //in other word, fast pointer moves n times first.
        ListNode* slow = head, * fast = head;
        for (int i = 0; i < n; ++i) {
            if (fast) fast = fast->next;
        }

        //check boundary
        if (!fast) return head->next;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* toBeDeleted = slow->next;
        slow->next = slow->next->next;
        delete toBeDeleted;
        return head;
    }
};
void ldemo_q19();

//27. Remove Element [Easy]
class Solution_q27 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

//31. Next Permutation [Med]
class Solution_q31 {
public:
    /*
    1.Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    2.Find the largest index k < l such that nums[k] < nums[l].
    3.Swap nums[k] and nums[l].
    4.Reverse the sub-array nums[k + 1:]. */
    std::vector<int> nextPermutation(std::vector<int>& nums) {
        int n = nums.size(), k = 0, l = 0;
        if (n < 2) return nums;
        for (k = n - 2; k >= 0; --k) {
            if (nums[k] < nums[k + 1]) break;
        }

        if (k < 0)
            std::reverse(nums.begin(), nums.end());
        else {
            for (l = n - 1; k < l; --l) {
                if (nums[k] < nums[l])
                    break;
            }
            std::swap(nums[l], nums[k]);
            std::reverse(nums.begin() + k + 1, nums.end());
        }
        return nums;
    }
};
void ldemo_q31();

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
#endif