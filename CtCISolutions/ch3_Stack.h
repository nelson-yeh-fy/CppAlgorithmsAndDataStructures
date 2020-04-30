#ifndef CH3_STACK_H
#define CH3_STACK_H
#include "ch3_Node.h"

template <typename K=int>
class ch3_Stack {
private:
	ch3_Node<K>* top;
	K value;
public:
	//ch3_Stack() {
	//	top = NULL;
	//}
	//~ch3_Stack() {
	//	if (top != NULL)
	//		delete top;
	//}
	
	const ch3_Node<K>* pop() {
		if (top == NULL)
			return NULL;

		ch3_Node<K>* tmp = top;
		top = top->next;
		return tmp;
	}

	void push(ch3_Node<K>* new_node) {
		new_node->next = top;
		top = new_node;
	}

	void push(const K& new_value) {
		ch3_Node<K>* new_node = new ch3_Node<K>(new_value);
		top = new_node;
	}

	void printStack() {
		ch3_Node<K>* temp = top;
		while (temp != NULL) {
			std::cout << temp->data << ",";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void setValue(const K& new_value) {
		value = new_value;
	}

	const K& getValue() const {
		return value;
	}

	ch3_Stack(const K& ini_value)
		:value(ini_value), top(NULL) {
		std::cout << "constructor is invoked" << std::endl;
	};

	~ch3_Stack() {
		std::cout << "destructor is invoked" << std::endl;
		if (value != NULL) {
			std::cout << "destructor(if value!=NULL) is invoked" << std::endl;
			value = 0;
		}
	}

};

void ch3_stack_demo1();
#endif //CH3_STACK_H