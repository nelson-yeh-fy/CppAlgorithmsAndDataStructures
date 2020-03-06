#include <iostream>
#include "insertionSort_2.h"
using namespace std;

void demo_is2() {
	/*int items[6] = { 6,7,2,9,1,3 };*/
	/*int items[6] = { 4,1,8,3,2,7 };*/
	int items[6] = { 1,3,2,4,8,7 };
	unsigned int size = sizeof(items) / sizeof(items[0]);

	IS2 is;
	is.print(items, size);
	Node<int>* LL = is.arrayToLL(items, size);
	is.print(LL);

	Node<int>* sortedLL = is.insertionSort(LL, size);
	is.print(sortedLL);
}

Node<int>* IS2::arrayToLL(int* items, int size) {
	Node<int>* ptrH = NULL, * ptr = NULL;
	ptrH = new Node<int>();
	ptr = ptrH;

	for (int i = 0; i < size; i++) {
		Node<int>* tmp = NULL;
		tmp = new Node<int>();
		tmp->val = items[i];
		tmp->next = NULL;
		ptr->next = tmp;
		ptr = ptr->next;
	}
	return ptrH->next;
}

Node<int>* IS2::insertionSort(Node<int>* ll, int size) {
	if (size <= 1)
		return ll;

	Node<int>* ptrH = NULL, * ptrK = NULL, * ptrJ = NULL;
	ptrH = new Node<int>();
	ptrH->next = ll;
	for (int k = 1; k < size; k++) {
		ptrK = traverse(ll, k);
		for (int j = 0; j < k; j++) {
			ptrJ = traverse(ptrH, j);
			if (ptrK->val < ptrJ->next->val) {
				insert(ptrJ, ptrK);
				break;
			}
		}
	}
	return ptrH->next;
}

void IS2::insert(Node<int>* nodePriorToN, Node<int>* nodeTBI) {

	nodePriorToN->next->next = nodeTBI->next;
	nodeTBI->next = nodePriorToN->next;
	nodePriorToN->next = nodeTBI;
	return;
}

Node<int>* IS2::traverse(Node<int>* n, int steps) {
	for (int i = 0; i < steps; i++) {
		if (n == NULL)
			return NULL;

		n = n->next;
	}
	return n;
}
void IS2::print(int* items, int size) {
	for (int i = 0; i < size; i++)
		cout << items[i];

	cout << endl;
}

void IS2::print(Node<int>* ptr) {
	while (ptr != NULL) {
		cout << ptr->val;
		ptr = ptr->next;
	}
	cout << endl;
}