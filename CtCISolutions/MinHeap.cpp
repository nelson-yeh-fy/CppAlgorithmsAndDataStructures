//#include <iostream>
//#include <queue>
//#include <list>
//#include <vector>
#include "MinHeap.h"
#include "swap.h"

using namespace std;

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

int MinHeap::getValue(int pos) {
	return harr[pos];
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

void ch4_createListsPerBTdepth_BFS()
{
	MinHeap mp1(10);
	mp1.insertKey(4);
	mp1.insertKey(9);
	mp1.insertKey(3);
	mp1.insertKey(5);
	mp1.insertKey(1);
	mp1.printArr();

	if (mp1.getHeapsize() <= 0)
		return;

	std::queue<int> q1; //q1 to store tree node's pos;
	std::queue<int> q2; //q2 to store depth;
	q1.push(0); //top node's position, its value is mp1.getValue());
	q2.push(1); //depth 1

	std::vector<std::list<int>> Lists;

	while (q1.empty() != true) {
		//Breadth First Search method
		int pos = q1.front();
		q1.pop();
		int depth = q2.front();
		q2.pop();

		//create lists as ch4 q3 requested:
		if (Lists.size() < depth) {
			std::list<int> depth_list;
			depth_list.push_back(mp1.getValue(pos));
			Lists.push_back(depth_list);
		}
		else {
			Lists.at(static_cast<size_t>(depth)- 1).push_back(mp1.getValue(pos));
		}
		
		//enqueue left node and right node, and their depth.
		if (mp1.left(pos) < mp1.getHeapsize()) {
			q1.push(mp1.left(pos));
			q2.push(depth + 1);
		}
		if (mp1.right(pos) < mp1.getHeapsize()) {
			q1.push(mp1.right(pos));
			q2.push(depth + 1);
		}
	}
	return;
}

void ch4_createListsPerBTdepth_DFS()
{
	MinHeap mp1(10);
	mp1.insertKey(4);
	mp1.insertKey(9);
	mp1.insertKey(3);
	mp1.insertKey(5);
	mp1.insertKey(1);
	mp1.printArr();

	if (mp1.getHeapsize() <= 0)
		return;

	std::vector<std::list<int>> Lists;
	ch4_createListsPerBTdepth_DFS(mp1, 0, Lists, 0);
}
void ch4_createListsPerBTdepth_DFS(MinHeap mp1,
	int rootPos,
	std::vector<std::list<int>>& Lists,
	int depth)
{
	//root
	if (Lists.size() == depth) {
		std::list<int> depth_list{ mp1.getValue(rootPos) };
		//depth_list.
		Lists.push_back(depth_list);
	}
	else {
		Lists[depth].push_back(mp1.getValue(rootPos));
	}

	if (mp1.left(rootPos) < mp1.getHeapsize()) {
		ch4_createListsPerBTdepth_DFS(mp1, mp1.left(rootPos), Lists, depth + 1);
	}
	if (mp1.left(rootPos) < mp1.getHeapsize()) {
		ch4_createListsPerBTdepth_DFS(mp1, mp1.right(rootPos), Lists, depth + 1);
	}
}
