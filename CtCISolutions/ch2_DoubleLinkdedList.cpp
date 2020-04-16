#include <iostream>
#include "ch2_DoubleLinkdedList.h"
using namespace std;

void ch2_DoubleLinkdedList::pushNode(ch2_DoubleNode** head, int data)
{
	ch2_DoubleNode* new_node = new ch2_DoubleNode();
	new_node->data = data;
	new_node->next = (*head);
	new_node->prev = NULL;

	if (*head != NULL) {
		(*head)->prev = new_node;
	}
	(*head) = new_node;
}

void ch2_DoubleLinkdedList::insertNode(ch2_DoubleNode* ptr, int data)
{
	if (ptr == NULL)
		return;

	ch2_DoubleNode* new_node = new ch2_DoubleNode();
	new_node->data = data;
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void ch2_DoubleLinkdedList::appendNode(ch2_DoubleNode** head, int data)
{
	if (*head == NULL)
		return;

	ch2_DoubleNode* last = *head;
	while (last->next != NULL) {
		last = last->next;
	}

	ch2_DoubleNode* new_node = new ch2_DoubleNode();
	new_node->data = data;
	new_node->next = NULL;
	last->next = new_node;
	last = new_node;
}

void ch2_DoubleLinkdedList::popNode(ch2_DoubleNode** head)
{
	ch2_DoubleNode* temp = *head;
	if (*head != NULL) {
		*head = (*head)->next;
		free(temp);
	}
	return;
}

void ch2_DoubleLinkdedList::printCh2Node(ch2_DoubleNode* ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->data;
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

void ch2_DoubleDemo1()
{
	ch2_DoubleLinkdedList ll;
	ll.pushNode(&ll.head, 5);
	ll.pushNode(&ll.head, 4);
	ch2_DoubleNode* tmp = ll.head;
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