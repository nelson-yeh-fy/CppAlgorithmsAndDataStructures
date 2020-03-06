#ifndef INSERTIONSORT_2_H
#define INSERTIONSORT_2_H
#include "Node.h"
class IS2 {
public:
	Node<int>* arrayToLL(int* items, int size);
	void insert(Node<int>* n1, Node<int>* n2);
	Node<int>* insertionSort(Node<int>* ll, int size);
	Node<int>* traverse(Node<int>* n, int steps);
	void print(int* items, int size);
	void print(Node<int>* ptr);
};
void demo_is2();
#endif // !INSERTIONSORT_2_H
