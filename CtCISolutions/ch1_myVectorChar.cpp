#include <iostream>
#include <vector>
#include "ch1_myVectorChar.h"
using namespace std;

void myVectorChar::doubleSize()
{
	char* temp = new char[capacity*2];
	for (int i = 0; i < capacity; i++) {
		temp[i] = items[i];
	}
	items = temp;
	capacity *= 2;
	return;
}

void myVectorChar::halfSize()
{
}

int myVectorChar::begin()
{
	return 0;
}

int myVectorChar::end()
{
	return size-1;
}

void myVectorChar::push_back(char c)
{
	if (size >= capacity)
		doubleSize();

	items[size] = 'c';
	return;
}

void myVectorChar::insert()
{
}

void demoMyVectorChar1() {

	myVectorChar my;
	my.push_back(1);
}