#ifndef MINHEAP_H
#define MINHEAP_H
class MinHeap {
private:
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int cap){
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
	int getMin();
	int extractMin();
	void insertKey(int val);
	void deleteKey(int pos);
	void decreaseKey(int pos, int new_val);
	void minHeapify(int pos);
	void printArr();

	void toSortedArray();
};

void demo_minHeap();
#endif // !MINHEAP_H

