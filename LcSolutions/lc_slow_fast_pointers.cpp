#include <iostream>
#include "lc_slow_fast_pointers.h"

using namespace std;

void print(ListNode* head) {
	while (head) {
		std::cout << head->val << ",";
		head = head->next;
	}
}
void ldemo_q19()
{
	Solution_q19 s;
	ListNode* n5 = new ListNode(5);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(2, n3);
	ListNode* n1 = new ListNode(1, n2);
	ListNode* res = s.removeNthFromEnd(n1, 6);
	print(res);
}
