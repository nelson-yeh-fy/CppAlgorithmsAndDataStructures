#ifndef MERGESORT_1_H
#define MERGESORT_1_H
#include "Node.h"

class MS1 {
public:
	Node<int>* merge(Node<int>* n1, Node<int>* n2);
	Node<int>* mergeSort(int* items, int i, int j);
	void print(int* items, int size);
};
void demo_ms();
#endif // !MERGESORT_1_H
