#ifndef LE_MERGE_K_WAYS_H
#define LE_MERGE_K_WAYS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "ds.h"

//21. Merge Two Sorted Lists [Easy]
class Solution_q21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* res = head;
        //step1. traverse l1 and l2. compare values until one of them reaches the end.
        while (l1 && l2) {
            if ((l1->val <= l2->val)) {
                res->next = l1;
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        res->next = (l1) ? l1 : l2;
        return head->next;
    }
};
void ldemo_q21();

//23. Merge k sorted list [Hard] 
class Solution_q23_a {
    // using priority queue (min heap), Time:O(kLogN), Space:O(k), 
    // better than std:min_elements 
public:
    ListNode* mergeKLists(std::vector<ListNode*> lists) {
        ListNode* head = new ListNode();
        ListNode* current = head;

        //step1. push all lists' first item into priority queue; smaller to be on the top.
        auto cmp = [](ListNode* left, ListNode* right) { return (left->val) > (right->val); };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);
        for (auto it = lists.cbegin(); it != lists.cend(); ++it) {
            if (*it) q.push(*it);
        }

        //step2. pop(add) the smallest to our list, add smallest->next to the priority queue. 
        while (!q.empty()) {
            ListNode* smallest = q.top();
            q.pop();
            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                smallest = smallest->next;
                q.push(smallest);
            }
        }
        return head->next;
    }
};
class Solution_q23_b {
    //Merge 2 list everytime, until there is only one left.
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
        ListNode* current = head;
        while (a && b) {
            if (a->val <= b->val) {
                current->next = a; 
                a = a->next;
            }
            else {
                current->next = b;
                b = b->next;
            }
            current = current->next;
        }
        current->next = (a) ? a : b;
        return head->next;
    }

    ListNode* mergeKLists(std::vector<ListNode*> lists) {
        ListNode* head = new ListNode();
        ListNode* current = head;

        //step1. push all lists' first item into queue;
        std::queue<ListNode*> q;
        for (auto it = lists.cbegin(); it != lists.cend(); ++it) {
            if (*it) q.push(*it);
        }

        while (q.size()>1) {
            ListNode* a = q.front(); q.pop();
            ListNode* b = q.front(); q.pop();
            q.push(merge2Lists(a,b));
        }
        
        return q.front()->next;
    }
};
void ldemo_q23();

//56. Merge Intervals [Med]
class Solution_q56_a {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& vals) {

        if (vals.size() < 1) return {};
        //step1. sort the given internvals (by its first number)
        std::sort(vals.begin(), vals.end(),
            [](std::vector<int> a, std::vector<int> b) { return a[0] < b[0]; });

        std::vector<std::vector<int>> res;
        res.push_back(vals[0]);
        //step2. traverse all interval, use each one as a base to compare.
        for (auto it = vals.cbegin() + 1; it != vals.cend(); ++it) {
            //step3. check if runner pointer's first num is within res.back()[0]. res.back()[1].
            if (res.back()[1] >= (*it)[0]) {
                res.back()[1] = std::max(res.back()[1], (*it)[1]);
            }
            else {
                res.push_back(*it);
            }
        }
        return res;
    }
};
void ldemo_q56();

#endif