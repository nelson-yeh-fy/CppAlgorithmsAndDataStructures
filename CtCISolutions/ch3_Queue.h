#ifndef CH3_Queue_H
#define CH3_Queue_H
#include "ch3_Node.h"

template <typename K = int>
class ch3_Queue {
private:
	ch3_Node<K>* front;
	ch3_Node<K>* rear;
	int size;
	K value;
public:
	const ch3_Node<K>* pop() {
		if (front == NULL)
			return NULL;

		ch3_Node<K>* temp = front;
		front = front->next;

		if (front == NULL)
			rear == NULL;

		size--;
		return temp;
	}

	void push(ch3_Node<K>* new_node) {
		if (rear == NULL)
		{
			front = rear = new_node;
			return;
		}

		rear->next = new_node;
		rear = new_node;
		size++;
		return;
	}

	void push(const K& new_value) {
		ch3_Node<K>* new_node = new ch3_Node<K>(new_value);
		if (rear == NULL)
		{
			front = rear = new_node;
			return;
		}

		rear->next = new_node;
		rear = new_node;
		size++;
		return;
	}

	void printQueue() {
		ch3_Node<K>* temp = front;
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
		:value(ini_value), front(NULL), rear(NULL), size(0) {
		std::cout << "constructor is invoked" << std::endl;
	};

	~ch3_Queue() {
		std::cout << "destructor is invoked" << std::endl;
		if (value != NULL) {
			std::cout << "destructor(if value!=NULL) is invoked" << std::endl;
			value = 0;
		}
		if (front != NULL) {
			std::cout << "destructor(if front!=NULL) is invoked" << std::endl;
			delete front;
		}
		if (rear != NULL) {
			std::cout << "destructor(if rear!=NULL) is invoked" << std::endl;
			delete rear;
		}
	}

};

void ch3_queue_demo1();
#endif //CH3_Queue_H