#include <iostream>
#include "reversePrint.h";
using namespace std;

void reverse_demo() {
	char str[] = "abcde";
	cout << str << "\n";

	reversePrint(&str[0]);
	return;
}

void reversePrint(char* ptr) {
	if (*ptr == '\0')
		return;

	reversePrint(ptr + 1);
	cout << *ptr;
	return;
}