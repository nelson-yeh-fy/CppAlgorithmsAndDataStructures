#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "MaxHeap.h"
class PriorityQueue : public MaxHeap {
public:
	PriorityQueue(int cap) : MaxHeap(cap) {}
	bool empty() { getHeapsize() <= 0 ? true : false; }
	int size() { return getHeapsize(); }
	int top() { return getMax(); }
	void push(int val);
	void pop();
	void printPQ();
};
void demo_pq();
#endif // !PRIORITYQUEUE_H