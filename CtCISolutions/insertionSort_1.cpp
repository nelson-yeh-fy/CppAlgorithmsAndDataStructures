#include <iostream>
#include "insertionSort_1.h"
using namespace std;

void demo_is1() {
	/*int items[6] = { 6,7,2,9,1,3 };*/
	/*int items[6] = { 4,1,8,3,2,7 };*/
	int items[6] = { 1,3,2,4,8,7 };
	unsigned int size = sizeof(items) / sizeof(items[0]);

	IS1 is;
	is.print(items, size);
	is.insertionSort(items, size);
	is.print(items, size);
}

void IS1::insertionSort(int* items, int size) {
	int key = 0, j = 0;
	for (int k = 1; k < size; k++) {
		key = items[k];
		j = k-1;

		while (j >= 0 && items[j] > key) {
			items[j + 1] = items[j];
			j--;
		}
		items[j+1] = key;
	}
	return;
}

void IS1::insertionSort_obselte(int *items, int size) {
	if (size <= 1)
		return;

	for (int k = 1; k < size; k++) {
		//items[k]
		for (int j = 0; j < k; j++) {
			//items[j]
			if (items[k] < items[j]) {
				insert(items, k, j);
				break;
			}
		}
	}
	return;
}

void IS1::insert(int* items, int k, int j) {

	int tmp = items[k];
	for (int i = k; i > j; i--) {
		items[i] = items[i - 1];
	}
	items[j] = tmp;
	return;
}

void IS1::print(int* items, int size) {
	for (int i = 0; i < size; i++)
		cout << items[i];

	cout << endl;
}
