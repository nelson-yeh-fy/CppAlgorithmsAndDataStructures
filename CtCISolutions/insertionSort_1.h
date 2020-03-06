#ifndef INSERTIONSORT_1_H
#define INSERTIONSORT_1_H
class IS1 {
public:
	void insert(int* items, int k, int j);
	void insertionSort(int *items, int size);
	void insertionSort_obselte(int* items, int size);
	void print(int* items, int size);
};
void demo_is1();
#endif // !INSERTIONSORT_1_H
