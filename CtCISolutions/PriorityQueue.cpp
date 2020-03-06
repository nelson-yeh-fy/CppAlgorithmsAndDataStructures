#include <iostream>
#include "PriorityQueue.h"
using namespace std;

void demo_pq() {
	PriorityQueue pq1(10);
	pq1.push(1);
	pq1.push(4);
	pq1.push(2);
	pq1.push(7);
	pq1.printPQ();

	cout << "top():" << pq1.top() << endl;
}

void PriorityQueue::push(int val) {
	MaxHeap::insertKey(val);
}

void PriorityQueue::pop() {
	MaxHeap::extractMax();
}

void PriorityQueue::printPQ()
{
	MaxHeap::printArr();
}