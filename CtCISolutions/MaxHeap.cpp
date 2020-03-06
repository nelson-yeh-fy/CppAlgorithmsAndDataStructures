#include <iostream>
#include "MaxHeap.h"
#include "swap.h"
using namespace std;

void demo_maxHeap() {
	MaxHeap mp2(10);
	mp2.insertKey(4);
	mp2.insertKey(10);
	mp2.insertKey(3);
	mp2.insertKey(5);
	mp2.insertKey(1);
	mp2.printArr();

	cout << "heapify" << endl;
	mp2.maxHeapify(0);
	mp2.printArr();

	cout << "max:" << mp2.getMax() << endl;

	cout << "extract max" << endl;
	mp2.extractMax();
	mp2.printArr();

	cout << "increase key at pos:3, make it 8" << endl;
	mp2.increaseKey(3, 8);
	mp2.printArr();

	cout << "insert key at pos:3, make it 9" << endl;
	mp2.insertKey(9);
	mp2.printArr();

	cout << "Demo of Heap sort (ascending)" << endl;
	//while (mp2.getHeapsize() > 0) {
	//	cout << mp2.extractMax() << " ";
	//}
	//cout << endl;
	mp2.toSortedArray();
	mp2.printArr();
}

int MaxHeap::getMax() {
	if (heap_size > 0)
		return harr[0];
	else
		return INT_MIN;
}

int MaxHeap::extractMax() {
	if (heap_size <= 0)
		return INT_MIN;

	if (heap_size == 1) {
		return harr[--heap_size];
	}

	int max = harr[0];
	harr[0] = harr[--heap_size];
	maxHeapify(0);
	return max;
}

void MaxHeap::insertKey(int val) {
	if (heap_size + 1 > capacity) {
		//allocate size
	}
	else {
		int pos = heap_size;
		harr[heap_size++] = val;
		while (pos >= 0 && harr[pos] > harr[parent(pos)]) {
			swap(&harr[pos], &harr[parent(pos)]);
			pos = parent(pos);
		}
	}
}

void MaxHeap::deleteKey(int pos) {
	if (pos > heap_size)
		return;

	increaseKey(pos, INT_MAX);
	extractMax();
}

void MaxHeap::increaseKey(int pos, int new_val) {
	if (pos > heap_size)
		return;

	harr[pos] = new_val;
	while (parent(pos) >= 0 && harr[pos] > harr[parent(pos)]) {
		swap(&harr[pos], &harr[parent(pos)]);
		pos = parent(pos);
	}
}

void MaxHeap::maxHeapify(int pos) {
	if (left(pos) > heap_size || right(pos) > heap_size)
		return;

	//heapify child node recursively, 
	//after reaching to the bottom, move the bigger value to its parentNode
	maxHeapify(left(pos));
	if (harr[pos] < harr[left(pos)])
		swap(&harr[pos], &harr[left(pos)]);

	maxHeapify(right(pos));
	if (harr[pos] < harr[right(pos)])
		swap(&harr[pos], &harr[right(pos)]);
}

void MaxHeap::printArr() {
	for (int i = 0; i < heap_size; i++)
		cout << harr[i] << ' ';
	cout << endl;
}

void MaxHeap::toSortedArray() {
	int org_heap_size = heap_size;
	while (heap_size > 0) {
		harr[heap_size] = extractMax();
	}
	heap_size = org_heap_size;
}