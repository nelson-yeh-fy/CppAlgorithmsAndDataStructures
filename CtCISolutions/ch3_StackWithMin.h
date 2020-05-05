#ifndef CH3_STACK_WITH_MIN_H
#define CH3_STACK_WITH_MIN_H
#include "ch3_Stack.h"

template <typename K = int>
class ch3_StackWithMin : public ch3_Stack<K> {
private:
	ch3_Node<K>* Min;

public:
	ch3_StackWithMin()
		:Min(nullptr), ch3_Stack<K>(){
		std::cout << "ch3_StackWithMin constructor is invoked" << std::endl;
	}
	const ch3_Node<K>* pop() {
		const ch3_Node<K>* popedNode = ch3_Stack<K>::pop();
		K value = popedNode->data;
		if (Min == nullptr) {
			std::cout << "min is null, it's abnormal" << std::endl;
		}else if (value <= Min->data) {
			ch3_Node<K>* temp = Min;
			Min = Min->next;
			delete temp;
		}
		return popedNode;
	}

	void push(const K& new_value) {
		if (Min == nullptr) {
			ch3_Node<K>* new_min_node = new ch3_Node<K>(new_value);
			Min = new_min_node;
		}else if (new_value < Min->data) {
			ch3_Node<K>* new_min_node = new ch3_Node<K>(new_value);
			new_min_node->next = Min;
			Min = new_min_node;
		}
		ch3_Stack<K>::push(new_value);
	}

	const K& peekMin() {
		return Min->data;
	}

	void printStack() {
		ch3_Stack<K>::printStack();
	}
};

void ch3_stack_with_min_demo1();
#endif //CH3_STACK_WITH_MIN_H