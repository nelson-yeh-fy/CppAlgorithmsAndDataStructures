#ifndef CH3_Queue_H
#define CH3_Queue_H
#include "ch3_Node.h"

template <typename K = int>
class ch3_Queue {
private:
	ch3_Node<K>* top;
	K value;
public:
	//ch3_Queue() {
	//	top = NULL;
	//}
	//~ch3_Queue() {
	//	if (top != NULL)
	//		delete top;
	//}

	const ch3_Node<K>* pop() {
		if (top == NULL)
			return NULL;

		ch3_Node<K>* last = top;
		while (last->next != NULL) {
			last = last->next;
		}

		ch3_Node<K>* toBeRemoved = new ch3_Node<K>;
		toBeRemoved->data = last->data;
		toBeRemoved->next = last->next;
		last = NULL;
		return toBeRemoved;
	}

	void push(ch3_Node<K>* new_node) {
		new_node->next = top;
		top = new_node;
	}

	void push(const K& new_value) {
		ch3_Node<K>* new_node = new ch3_Node<K>;
		new_node->data = new_value;
		new_node->next = top;
		top = new_node;
	}

	void printQueue() {
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

	ch3_Queue(const K& ini_value)
		:value(ini_value), top(NULL) {
		std::cout << "constructor is invoked" << std::endl;
	};

	~ch3_Queue() {
		std::cout << "destructor is invoked" << std::endl;
		if (value != NULL) {
			std::cout << "destructor(if value!=NULL) is invoked" << std::endl;
			value = 0;
		}
	}

};

void ch3_queue_demo1();
#endif //CH3_Queue_H