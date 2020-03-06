#include <iostream>
#include "MinHeap.h"
#include "swap.h"
using namespace std;

void demo_minHeap() {
	MinHeap mp1(10);
	mp1.insertKey(4);
	mp1.insertKey(10);
	mp1.insertKey(3);
	mp1.insertKey(5);
	mp1.insertKey(1);
	mp1.printArr();

	cout << "heapify" << endl;
	mp1.minHeapify(0);
	mp1.printArr();

	cout << "min:" << mp1.getMin() << endl;

	cout << "extract min" << endl;
	mp1.extractMin();
	mp1.printArr();

	cout << "decrease key at pos:3 (10 as example), make it 1" << endl;
	mp1.decreaseKey(3, 1);
	mp1.printArr();

	cout << "insert key at pos:3, make it 2" << endl;
	mp1.insertKey(2);
	mp1.printArr();

	cout << "Demo of Heap sort (descending)" << endl;
	//while (mp1.getHeapsize() > 0) {
	//	cout << mp1.extractMin() << " ";
	//}
	//cout << endl;
	mp1.toSortedArray();
	mp1.printArr();
}

int MinHeap::getMin() {
	if (heap_size > 0)
		return harr[0];
	else
		return INT_MAX;
}

int MinHeap::extractMin() {
	if (heap_size <= 0)
		return INT_MAX;

	if (heap_size == 1) {
		return harr[--heap_size];
	}

	int min = harr[0];
	harr[0] = harr[--heap_size];
	minHeapify(0);
	return min;
}

void MinHeap::insertKey(int val) {
	if (heap_size + 1 > capacity) {
		//allocate more capacity
		//capacity *= 2;
		//resize harr
	}
	else {
		int pos = heap_size;
		harr[heap_size++] = val;
		while (pos >= 0 && harr[pos] < harr[parent(pos)]) {
			swap(&harr[pos], &harr[parent(pos)]);
			pos = parent(pos);
		}
	}
}

void MinHeap::deleteKey(int pos) {
	if (pos > heap_size)
		return;

	decreaseKey(pos, INT_MIN);
	extractMin();
}

void MinHeap::decreaseKey(int pos, int new_val) {
	if (pos > heap_size)
		return;

	harr[pos] = new_val;
	while (parent(pos) >= 0 && harr[pos] < harr[parent(pos)]) {
		swap(&harr[pos], &harr[parent(pos)]);
		pos = parent(pos);
	}
}

void MinHeap::minHeapify(int pos) {
	if (left(pos) > heap_size || right(pos) > heap_size)
		return;

	//heapify child node recursively, 
	//after reaching to the bottom, move the smaller value to its parentNode
	minHeapify(left(pos));
	if (harr[left(pos)] < harr[pos])
		swap(&harr[left(pos)], &harr[pos]);

	minHeapify(right(pos));
	if (harr[right(pos)] < harr[pos])
		swap(&harr[right(pos)], &harr[pos]);
}

void MinHeap::printArr() {
	for (int i = 0; i < heap_size; i++)
		cout << harr[i] << ' ';
	cout << endl;
}

void MinHeap::toSortedArray() {
	int org_heap_size = heap_size;
	while (heap_size > 0) {
		harr[heap_size] = extractMin();
	}
	heap_size = org_heap_size;
}