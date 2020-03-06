#ifndef BUBBLESORT_VECTOR_H
#define BUBBLESORT_VECTOR_H
class BS2 {
public:
	//int num;
	std::vector<int> items;
	//BS2() {};
	void bubbleSort(std::vector<int>& items);
	void print(std::vector<int>& items);
};

void demo_BS2();
#endif