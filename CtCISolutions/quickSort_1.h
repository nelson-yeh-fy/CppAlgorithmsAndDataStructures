#ifndef QUICKSORT_1_H
#define QUICKSORT_1_H
class QS1 {
public:	
	int partition(int* items, int head, int tail);
	void quickSort(int *items, int i, int j);
	void quickSort_1(int* items, int head, int tail);
	void print(int *items, int size);
};
void demo_qs();
#endif // ! QUICKSORT_1_H
