#include <iostream>
#include <vector>
#include "ch1_myVectorChar.h"
using namespace std;

void myVectorChar::doubleSize()
{
	m_capacity *= 2;
	char* temp = new char[m_capacity];
	for (int i = 0; i < m_capacity /2; i++) {
		temp[i] = m_items[i];
	}
	m_items = temp;
	return;
}

bool myVectorChar::resize(int nsize) {
	if (nsize < 0 || nsize > INT_MAX)
		return false;

	if (nsize > m_capacity) {
		char* temp = new char[nsize];
		for (int i = 0; i < nsize; i++) {
			temp[i] = m_items[i];
		}
		m_items = temp;
		m_size = m_capacity = nsize;
	}
	else if (nsize < m_size) {
		// removing those beyond (and destroying them).
		m_size = nsize;
	}
	else if (nsize > m_size) {
		//  the content is expanded by inserting at the end as many elements as needed to reach a size of n. 
		m_size = nsize;
	}
	return true;
}

void myVectorChar::reserve(int nsize)
{
	if (nsize > m_capacity) {
		resize(nsize);
	}
}

void myVectorChar::shrink_to_fit(int nsize)
{
	if (nsize < 0 || nsize > m_capacity || nsize > INT_MAX)
		return;

	if (nsize < m_capacity) {
		char* temp = new char[nsize];
		for (int i = 0; i < nsize; i++) {
			temp[i] = m_items[i];
		}
		m_items = temp;
		m_size = m_capacity = nsize;
	}
}

int myVectorChar::begin()
{
	return 0;
}

int myVectorChar::end()
{
	return 0;
}

void myVectorChar::push_back(char c)
{
	if (m_size >= m_capacity) {
		doubleSize();
		cout << "#doubleSize() is invoked" << endl;
	}

	m_items[m_size++] = c;
	return;
}

void myVectorChar::insert()
{
}

void myVectorChar::print()
{
	cout << "Capacity:" << m_capacity << " ,Current size:" << m_size << endl;
	for (int i = 0; i < m_size; i++)
		cout << m_items[i] << " ";
	cout << endl;
}

void demoMyVectorChar1() {

	myVectorChar my;
	my.push_back('a');
	my.print();
	my.push_back('b');
	my.print();
	my.push_back('c');
	my.print();
}