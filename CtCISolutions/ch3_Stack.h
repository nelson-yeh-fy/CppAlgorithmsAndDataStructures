#ifndef CH3_STACK_H
#define CH3_STACK_H
#include <iostream>
#include "ch3_Node.h"

template <typename K=int>
class ch3_Stack {
private:
	ch3_Node<K>* Top;
	K value;
	unsigned short int size;
public:
	const ch3_Node<K>* pop() {
		if (Top == NULL)
			return NULL;

		ch3_Node<K>* tmp = Top;
		Top = Top->next;
		size--;
		return tmp;
	}
	void push(ch3_Node<K>* new_node) {
		new_node->next = Top;
		Top = new_node;
		size++;
	}
	void push(const K& new_value) {
		ch3_Node<K>* new_node = new ch3_Node<K>(new_value);
		new_node->next = Top;
		Top = new_node;
		size++;
	}
	void printStack() {
		ch3_Node<K>* temp = Top;
		while (temp != NULL) {
			std::cout << temp->data << ",";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	const unsigned short int Size() {
		return size;
	}
	void setValue(const K& new_value)
	{
		value = new_value;
	}
	const K& getValue() const
	{
		return value;
	}

	ch3_Stack()
		:Top(nullptr), value(NULL) {
		std::cout << "ch3_Stack constructor is invoked" << std::endl;
	};

	//ch3_Stack(const K& ini_value)
	//	:value(ini_value), Top(NULL) {
	//	std::cout << "ch3_Stack constructor is invoked" << std::endl;
	//};

	~ch3_Stack() {
		std::cout << "ch3_Stack destructor is invoked" << std::endl;
		if (Top != nullptr) {
			delete Top;
		}
		if (value != NULL) {
			std::cout << "destructor(if value!=NULL) is invoked" << std::endl;
			value = 0;
		}
	}
};

void ch3_stack_demo1();
#endif //CH3_STACK_H