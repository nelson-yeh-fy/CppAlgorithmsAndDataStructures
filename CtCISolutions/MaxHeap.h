#ifndef MAXHEAP_H
#define MAXHEAP_H
class MaxHeap {
private:
	int* harr;
	int capacity;
	int heap_size;
public:
	MaxHeap(int cap) {
		capacity = cap;
		heap_size = 0;
		harr = new int[capacity];
	}

	//parent node: harr[(pos-1)/2]
	//current node: harr[pos]
	//child left node: harr[pos*2+1]
	//child right node: harr[pos*2+2]
	int parent(int pos) { return (pos - 1) / 2; }
	int left(int pos) { return pos * 2 + 1; }
	int right(int pos) { return pos * 2 + 2; }

	int getCapacity() { return capacity; }
	int getHeapsize() { return heap_size; }
	int getMax();
	int extractMax();
	void insertKey(int val);
	void deleteKey(int pos);
	void increaseKey(int pos, int new_val);
	void maxHeapify(int pos);
	void printArr();

	void toSortedArray();
};

void demo_maxHeap();
#endif // !MAXHEAP_H