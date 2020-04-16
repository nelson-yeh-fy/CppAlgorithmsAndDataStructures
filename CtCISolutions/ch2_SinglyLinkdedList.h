#ifndef CH2_SINGLYLINKEDLIST_H
#define CH2_SINGLYLINKEDLIST_H
#include <cstddef>
#include "ch2_SinglyNode.h"

class ch2_SinglyLinkdedList {
public:
	ch2_SinglyNode* head;
	ch2_SinglyNode* tail;

	ch2_SinglyLinkdedList() {
		head = NULL;
		tail = NULL;
	}
	void pushNode(ch2_SinglyNode** head, int data);
	void insertNode(ch2_SinglyNode* ptr, int data);
	void appendNode(ch2_SinglyNode** head, int data);
	void popNode(ch2_SinglyNode** head);
	void printCh2Node(ch2_SinglyNode* ptr);
};
void ch2_SinglyDemo1();
#endif