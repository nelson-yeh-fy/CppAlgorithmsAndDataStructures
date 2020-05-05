#ifndef CH3_Queue_H
#define CH3_Queue_H
#include "ch3_Node.h"

template <typename K = int>
class ch3_Queue {
private:
	ch3_Node<K>* front;
	ch3_Node<K>* rear;
	int size;
public:
	const ch3_Node<K>* pop() {
		if (front == NULL)
			return NULL;

		ch3_Node<K>* temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

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

	ch3_Queue()
		:front(NULL), rear(NULL), size(0) {
		std::cout << "constructor is invoked" << std::endl;
	};

	~ch3_Queue() {
		std::cout << "destructor is invoked" << std::endl;
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