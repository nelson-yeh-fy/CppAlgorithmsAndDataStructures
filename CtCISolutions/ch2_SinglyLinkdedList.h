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
	void appendNode(ch2_SinglyNode** head, ch2_SinglyNode *node);
	void popNode(ch2_SinglyNode** head);
	void printCh2Node(ch2_SinglyNode* ptr);
};
void ch2_SinglyDemo1();
void ch2_SinglyDemo2();
void ch2_SinglyDemo3();
bool isPalindrome(ch2_SinglyNode* head);
void isPalindrome(ch2_SinglyNode** head, ch2_SinglyNode* runnerPtr, bool &resultVerified, bool &result);
ch2_SinglyNode* findIntersectedNode(ch2_SinglyNode* aHead, ch2_SinglyNode* bHead);
ch2_SinglyNode* findLastAndLength(ch2_SinglyNode* head, int& length);
#endif