#include <iostream>
#include "Node.h"
#include "reverseString_2_linkedlist.h"
using namespace std;

void demo_LL() {
	Node<char>* head = NULL;
	Node<char>* second = NULL;
	Node<char>* tail = NULL;

	head = new Node<char>();
	second = new Node<char>();
	tail = new Node<char>();

	head->val = 'a';
	head->next = second;
	second->val = 'b';
	second->next = tail;
	tail->val = 'c';
	tail->next = NULL;
	printNode(head);
	cout << endl;

	//reverse string
	char str[] = "abcde";
	Node<char>* reversedStr = NULL;
	reversedStr = reverseString(&str[0], NULL);
	printNode(reversedStr);
}

Node<char>* reverseString(char* ptr, Node<char>* reversedStr) {
	Node<char> *RS_tail, *RS_current = NULL;
	RS_tail = new Node<char>();
	RS_tail->val = *ptr;
	RS_tail->next = NULL;
	RS_current = RS_tail;

	while (*(ptr+1) != '\0') {
		Node<char>* tmp = NULL;
		tmp = new Node<char>();
		tmp->val = *(ptr+1);
		tmp->next = RS_current;
		RS_current = tmp;
		ptr = ptr + 1;
		if (*(ptr + 1) == '\0')
			return tmp;
	}
	return NULL;
}