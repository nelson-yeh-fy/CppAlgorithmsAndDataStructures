#ifndef CH2_DOUBLELINKEDLIST_H
#define CH2_DOUBLELINKEDLIST_H
#include <cstddef>
#include "ch2_DoubleNode.h"

class ch2_DoubleLinkdedList {
public:
	ch2_DoubleNode* head;
	ch2_DoubleNode* tail;

	ch2_DoubleLinkdedList() {
		head = NULL;
		tail = NULL;
	}
	void pushNode(ch2_DoubleNode** head, int data);
	void insertNode(ch2_DoubleNode* ptr, int data);
	void appendNode(ch2_DoubleNode** head, int data);
	void popNode(ch2_DoubleNode** head);
	void printCh2Node(ch2_DoubleNode* ptr);
};
void ch2_DoubleDemo1();
#endif