#include <iostream>
#include <string.h>
#include "reverseString_1_ptr.h"
using namespace std;

void reverseString_demo() {
	char str[] = "abcde";
	size_t len = strlen(str);
	char strTBR[5];
	reverse(&strTBR[0], &str[0], len);

	cout << str << "\n";
	cout << strTBR << "\n";
	return;
}

void reverse(char* ptrTBR, char* ptr, size_t len) {
	if (*ptr == '\0')
		return;

	reverse(ptrTBR, ptr + 1, len - 1);
	*(ptrTBR + len) = *ptr;
	return;
}