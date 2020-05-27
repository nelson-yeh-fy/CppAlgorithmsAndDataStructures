#include <iostream>
#include <vector>
#include "bubbleSort_2_vector.h";

using namespace std;

void demo_BS2() {
	BS2 bs2;
	bs2.items = { 2,5,7,1,4 };
	bs2.print(bs2.items);
	bs2.bubbleSort(bs2.items);
	bs2.print(bs2.items);
	return;
}

void BS2::bubbleSort(vector<int>& items) {

	//for (int i = 0; i < items.size(); i++) {
	//	for (int j = 0; j < items.size(); j++) {
	//		int tmp = 0;
	//		if (items[i] < items[j]) {
	//			tmp = items[i];
	//			items[i] = items[j];
	//			items[j] = tmp;
	//		}
	//	}
	//}
	for (auto i = items.begin(); i < items.end() - 1; ++i) {
		for (auto j = items.begin(); j < items.end() - 1; ++j) {
			int tmp = 0;
			if (*i < *j) {
				tmp = *i;
				*i = *j;
				*j = tmp;
			}
		}
	}
	return;
}

void BS2::print(std::vector<int>& items) {
	for (auto i = items.begin(); i != items.end(); ++i) {
		cout << *i;
	}
	cout << endl;
	return;
}