#include <iostream>
#include "mergeSort_1.h"
using namespace std;

void demo_ms() {
	/*int items[6] = { 6,7,2,9,1,3 };*/
	/*int items[6] = { 4,1,8,3,2,7 };*/
	int items[6] = { 1,3,2,4,8,7 };
	/*int items[6] = { 7,2,1,3,6,5 };*/
	unsigned int size = sizeof(items) / sizeof(items[0]);

	MS1 ms;
	ms.print(items, size);
	Node<int>*sorted = ms.mergeSort(items, 0, size - 1);
	printNode(sorted);
}


Node<int>* MS1::mergeSort(int* items, int i, int j) {

	if (i < j) {
		// Find the middle point;
		int middle = (i + j) / 2;

		// Merge sort for the first halve of items
		Node<int>*n1 = mergeSort(items, i, middle);

		// Merge sort for the second halve of items
		Node<int>*n2 = mergeSort(items, middle + 1, j);

		return merge(n1, n2);
	};
	Node<int>*n = NULL;
	n = new Node<int>();
	n->val = items[i];
	n->next = NULL;
	return n;
}

Node<int>* MS1::merge(Node<int>* n1, Node<int>* n2) {

	Node<int> *ptrHead = NULL, *ptr = NULL;
	ptr = new Node<int>();
	ptrHead = ptr;

	while (n1 != NULL || n2 != NULL) {
		if (n1 != NULL && n2 != NULL) {
			if (n1->val < n2->val) {
				ptr->next = n1;
				n1 = n1->next;
			} else {
				ptr->next = n2;
				n2 = n2->next;
			}
			ptr = ptr->next;
			continue;
		}
		if (n1 != NULL) {
			ptr->next = n1;
			n1 = n1->next;
			ptr = ptr->next;
			continue;
		}
		if (n2 != NULL) {
			ptr->next = n2;
			n2 = n2->next;
			ptr = ptr->next;
			continue;
		}
	}
	// Return the merged nodes, truncate the first one, which is just a header.
	return ptrHead->next;
}

void MS1::print(int* items, int size) {
	for (int i = 0; i < size; i++)
		cout << items[i];

	cout << endl;
}