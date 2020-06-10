#include <iostream>
#include "quickSort_1.h"
#include "swap.h"
using namespace std;

void demo_qs() {
	/*int items[6] = { 6,7,2,9,1,3 };*/
	/*int items[6] = { 4,1,8,3,2,7 };*/
	//int items[6] = { 1,3,2,4,8,7 };
	int items[6] = { 7,2,1,3,6,5 };
	unsigned int size = sizeof(items) / sizeof(items[0]);

	QS1 qs;
	qs.print(items, size);
	qs.quickSort(items, 0, size-1);
}

int QS1::partition(int* items, int i, int j) {
	int k = i;
	while (i < j) {
		// if items[j] is smaller than items[k] (base number), and
		// if items[i] is bigger than items[k] (base number),
		// we're gonna switch items[j] with item[i].
		if (items[j] < items[k]) {
			if (items[i] > items[k]) {
				swap(&items[i], &items[j]);
			}
			else {
				i++;
			}
		}
		else {
			j--;
		}
		//Another way:
		/*while (i < j) {
			if (nums[j] > privot_value) {
				j--;
			}
			else if (nums[i] < privot_value) {
				i++;
			}
			else {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}*/
	}
	// Swap k (base number) with items[j], so everything on k's left is now smaller than k.
	// and everthing on k's right is bigger than k.
	swap(&items[k], &items[j]);
	print(items, 6);
	cout << "--end of one iteration--" << endl;

	return j;
}

void QS1::quickSort(int* items, int head, int tail) {
	int k = partition(items, head, tail);

	if (head < k-1) {
		quickSort(items, head, k - 1);
	}
	if (k+1 < tail) {
		quickSort(items, k + 1, tail);
	}
}

void QS1::quickSort_1(int *items, int head, int tail) {
	int k = head;
	int i = head, j = tail;

	if (i >= j)
		return;

	while (i != j) {
		// if items[j] (tail) is smaller than k(base number), 
		// we're gonna switch it with item[i] if items[i] is bigger than k.
		if (items[j] < items[k]) {
			if (items[i] > items[k]) {
				swap(&items[i], &items[j]);
			}
			else {
				i++;
			}
		}
		else {
			j--;
		}
	}
	// Swap k (base number) with items[j], so everything on k's left is now smaller than k.
	// and everthing on k's right is bigger than k.
	swap(&items[k], &items[j]);
	print(items, 6);
	cout << "--end of one iteration--" << endl;
	
	if (head < j) {
		quickSort(items, head, j - 1);
	}

	if (j < tail) {
		quickSort(items, j + 1, tail);
	}
}

void QS1::print(int *items, int size) {
	for (int i = 0; i < size; i++)
		cout << items[i];

	cout << endl;
}