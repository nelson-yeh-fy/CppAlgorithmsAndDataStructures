#include <iostream>
#include <vector>
#include "bubbleSort_1_ptr.h";
using namespace std;

void bubbleSort_1_main() {
	const int size = 5;
	int items[size] = {2,5,7,1,4};
	print2(items, size);
	bubbleSort(items, size);
	print2(items, size);
	//print1(&items[0]);

	return;
}

void bubbleSort(int* items, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int tmp = 0;
			if (items[i] < items[j]) {
				tmp = items[i];
				items[i] = items[j];
				items[j] = tmp;
			}
		}
	}
	return;
}

void print1(int* ptr) {
	while (*ptr != '\0') { //having a '\0' in the array is a pre-requisite.
		cout << *ptr;
		ptr++;
	}
	cout << endl;
	return;
}

void print2(int* ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i];
	}
	cout << endl;
	return;
}