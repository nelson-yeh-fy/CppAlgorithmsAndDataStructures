#include <iostream>
#include "ch2_LinkdedList.h"
using namespace std;

void ch2_LinkdedList::pushNode(ch2_SinglyNode** head, int data)
{
	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

void ch2_LinkdedList::insertNode(ch2_SinglyNode* ptr, int data)
{
	if (ptr == NULL)
		return;

	ch2_SinglyNode* new_node = new ch2_SinglyNode();
	new_node->data = data;
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void ch2_LinkdedList::appendNode(ch2_SinglyNode** head, int data)
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

void ch2_LinkdedList::popNode(ch2_SinglyNode** head)
{
	ch2_SinglyNode* temp = *head;
	if (*head != NULL) {
		*head = (*head)->next;
		free(temp);
	}
	return;
}

void ch2_LinkdedList::printCh2Node(ch2_SinglyNode* ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->data;
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

void ch2_demo1() 
{
	ch2_LinkdedList ll;
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