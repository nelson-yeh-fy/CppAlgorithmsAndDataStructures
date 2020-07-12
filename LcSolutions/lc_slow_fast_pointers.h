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
#endif