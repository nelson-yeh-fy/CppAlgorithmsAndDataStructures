// CtCISolutions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
//#include "Node.h"
//#include "MinHeap.h"
//#include "MaxHeap.h"
//#include "PriorityQueue.h"
//#include "bubblesort_1_ptr.h"
//#include "bubblesort_2_vector.h"
//#include "reverseprint.h"
//#include "reversestring_1_ptr.h"
//#include "reverseString_2_linkedlist.h"
//#include "quickSort_1.h"
//#include "mergeSort_1.h"
//#include "insertionSort_1.h"
//#include "insertionSort_2.h"
#include "ch1_myVectorChar.h"

using namespace std;

void ch1_test1() {
	int ascii_set[128];
	
	int img[4][4] = { {0,0,0,0}, {1,1,1,1}, {2,2,2,2}, {3,3,3,3} };
	std::cout << "." << 'A' % 128 << "." << std::endl;

	std::vector<int> v1(5, 1); //vector with 5 items, all of them are 7,
	for (int i : v1) {
		std::cout << i << ",";
	}
	std::cout << std::endl;

	std::vector<vector<int>> vv2(5, v1);
	for (vector<int> v : vv2) {
		for (int i : v) {
			std::cout << i << ",";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}
int main()
{
	//bubbleSort_1_main();
	//demo_BS2();
	//demo_LL();
	//demo_qs();
	//demo_ms();
	//demo_is1();
	//demo_is2();
	//demo_minHeap();
	//demo_maxHeap();
	//demo_pq();
	//demoMyVectorChar1();
	ch1_test1();
}

