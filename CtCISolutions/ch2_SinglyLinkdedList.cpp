#include <iostream>
#include "ch2_SinglyLinkdedList.h"
using namespace std;

void ch2_SinglyLinkdedList::pushNode(ch2_SinglyNode** head, int data)
{
	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

void ch2_SinglyLinkdedList::insertNode(ch2_SinglyNode* ptr, int data)
{
	if (ptr == NULL)
		return;

	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void ch2_SinglyLinkdedList::appendNode(ch2_SinglyNode** head, int data)
{
	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = NULL;

	if ((*head) == NULL) {
		*head = new_node;
		return;
	}

	ch2_SinglyNode* last = (*head);
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	last = new_node;
}

void ch2_SinglyLinkdedList::appendNode(ch2_SinglyNode** head, ch2_SinglyNode* new_node)
{
	ch2_SinglyNode* last = *head;
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;
	last = new_node;
}

void ch2_SinglyLinkdedList::popNode(ch2_SinglyNode** head)
{
	ch2_SinglyNode* temp = *head;
	if (*head != NULL) {
		*head = (*head)->next;
		free(temp);
	}
	return;
}

void ch2_SinglyLinkdedList::printCh2Node(ch2_SinglyNode* ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->data;
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

void ch2_SinglyDemo1() 
{
	ch2_SinglyLinkdedList ll;
	ll.pushNode(&ll.head, 5);
	ll.pushNode(&ll.head, 4);
	ch2_SinglyNode* tmp = ll.head;
	ll.pushNode(&ll.head, 3);
	ll.pushNode(&ll.head, 2);
	ll.printCh2Node(ll.head);
	ll.insertNode(tmp, 1);
	ll.printCh2Node(ll.head);

	ll.appendNode(&ll.head, 9);
	ll.printCh2Node(ll.head);

	ll.popNode(&ll.head);
	ll.printCh2Node(ll.head);
}

void ch2_SinglyDemo2()
{
	ch2_SinglyLinkdedList ll;
	ll.pushNode(&ll.head, 1);
	ll.pushNode(&ll.head, 2);
	ll.pushNode(&ll.head, 3);
	ll.pushNode(&ll.head, 3);
	ll.pushNode(&ll.head, 2);
	ll.pushNode(&ll.head, 1);
	ll.printCh2Node(ll.head);

	bool result = isPalindrome(ll.head);
	std::cout << "isPalindrome:" << result << std::endl;
}

bool isPalindrome(ch2_SinglyNode* head)
{
	if (head == NULL)
		return false;

	bool resultVerified = false;
	bool result = false;
	isPalindrome(&head, head, resultVerified, result);
	return result;
}

void isPalindrome(ch2_SinglyNode** head, ch2_SinglyNode* runnerPtr, bool &resultVerified, bool &result)
{
	if (runnerPtr == NULL)
		return;

	isPalindrome(head, runnerPtr->next, resultVerified, result);

	if (resultVerified == true)
		return;

	if (*head == runnerPtr) {
		resultVerified = true;
		result = true;
		return;
	}

	if ((*head)->data == runnerPtr->data) {
		*head = (*head)->next;
	}
	else {
		resultVerified = true;
		result = false;
		return;
	}

	result = true;
	return;
}

ch2_SinglyNode* findIntersectedNode(ch2_SinglyNode* aHead, ch2_SinglyNode* bHead)
{
	if (aHead == NULL || bHead == NULL)
		return nullptr;

	int aLen = 0, bLen = 0;
	ch2_SinglyNode* aTail = findLastAndLength(aHead, aLen);
	ch2_SinglyNode* bTail = findLastAndLength(bHead, bLen);
	
	if (aTail != bTail)
		return NULL;

	if (aLen > bLen) {
		int forward = aLen - bLen;
		while (forward > 0) {
			aHead = aHead->next;
			forward--;
		}
	}

	if (bLen > aLen) {
		int forward = bLen - aLen;
		while (forward > 0) {
			bHead = bHead->next;
			forward--;
		}
	}

	while (aHead != NULL) {
		if (aHead == bHead)
			return aHead;

		aHead = aHead->next;
		bHead = bHead->next;
	}

	return nullptr;
}

ch2_SinglyNode* findLastAndLength(ch2_SinglyNode* head, int& length)
{
	ch2_SinglyNode* last = head;
	while (last->next != NULL) {
		last = last->next;
		length++;
	}
	return last;
}

void ch2_SinglyDemo3()
{
	//L1
	ch2_SinglyLinkdedList ll;
	ll.appendNode(&ll.head, 1);
	ll.appendNode(&ll.head, 2);
	ch2_SinglyNode* n4 = new ch2_SinglyNode();
	n4->data = 4;
	n4->next = NULL;
	ll.appendNode(&ll.head, n4);
	ch2_SinglyNode* n5 = new ch2_SinglyNode();
	n5->data = 5;
	n5->next = NULL;
	ll.appendNode(&ll.head, n5);
	ll.printCh2Node(ll.head);

	//L2
	ch2_SinglyLinkdedList ll2;
	ll2.appendNode(&ll2.head, 7);
	ll2.appendNode(&ll2.head, n4);
	ll2.printCh2Node(ll2.head);

	ch2_SinglyNode* intersectedNode = findIntersectedNode(ll.head, ll2.head);
}