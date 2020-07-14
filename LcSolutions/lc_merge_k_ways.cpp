#include <iostream>
#include "lc_merge_k_ways.h"
#include "ds.h"
using namespace std;

void ldemo_q21()
{
    Solution_q21 s;
    ListNode* n5 = new ListNode(5);
    ListNode* n3 = new ListNode(3, n5);
    ListNode* n1 = new ListNode(1, n3);

    ListNode* n6 = new ListNode(6);
    ListNode* n4 = new ListNode(4, n6);
    ListNode* n2 = new ListNode(2, n4);

    ListNode* m = s.mergeTwoLists(n1, n2);
    while (m) {
        std::cout << m->val << ",";
        m = m->next;
    }
}

void ldemo_q23()
{
    Solution_q23_b s;
    std::vector<ListNode*> input;
    ListNode* a5 = new ListNode(5);
    ListNode* a4 = new ListNode(4, a5);
    ListNode* a1 = new ListNode(1, a4);

    ListNode* b4 = new ListNode(4);
    ListNode* b3 = new ListNode(3, b4);
    ListNode* b1 = new ListNode(1, b3);

    ListNode* c6 = new ListNode(6);
    ListNode* c2 = new ListNode(2, c6);
    input.push_back(a1);
    input.push_back(b1);
    input.push_back(c2);
    ListNode* res = s.mergeKLists(input);
    while (res) {
        std::cout << res->val << ",";
        res = res->next;
    }
}

void ldemo_q56() {
    Solution_q56_a q;
    std::vector<std::vector<int>> input = { {1,3},{2,6},{8,10},{15,18} };
    input = { {1,4},{4,5} };
    input = { {1, 4},{0, 2},{3, 5} };
    std::vector<vector<int>> res = q.merge(input);
    for (auto it = res.cbegin(); it != res.cend(); ++it) {
        cout << "[" << (*it)[0] << "," << (*it)[1] << "], ";
    }
}

