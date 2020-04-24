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
	if (*head == NULL)
		return;

	ch2_SinglyNode* last = *head;
	while (last->next != NULL) {
		last = last->next;
	}

	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = NULL;
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
