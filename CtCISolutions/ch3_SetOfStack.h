#ifndef CH3_SET_OF_STACK_H
#define CH3_SET_OF_STACK_H
#include "ch3_Node.h";
#include "ch3_StackNode.h"

template <typename K = int>
class ch3_SetOfStack {
public:
	ch3_Stack_Node<K>* TopStack;
	const int threshold = 3;

	ch3_Node<K>* pop() {
		if (TopStack == nullptr) {
			return nullptr;
		}
		ch3_Node<K>* node = (TopStack->TheStack).pop();

		if ((TopStack->TheStack).Size() == 0) {
			TopStack = TopStack->nextStack;
		}

		return node;
	}

	void push(const K& new_value) {
		if (TopStack == nullptr) {
			TopStack = new ch3_Stack_Node<K>();
		};
		if ((TopStack->TheStack).Size() >= threshold) {
			ch3_Stack_Node<K>* tmp = new ch3_Stack_Node<K>();
			tmp->nextStack = TopStack;
			tmp->TheStack.push(new_value);
			TopStack = tmp;
		}
		else {
			(TopStack->TheStack).push(new_value);
		}
		return;
	}

	void printStack() {
		ch3_Stack_Node<int>* tmp = TopStack;
		while (tmp != NULL) {
			(tmp->TheStack).printStack();
			tmp = tmp->nextStack;
			std::cout << " >> ";
		}
		std::cout << " >> END " << std::endl;
	}
	//ch3_SetOfStack() {
	//	TopStack = new ch3_Stack_Node<K>();
	//}
};

void ch3_SetOfStack_demo1();
#endif //CH3_SET_OF_STACK_H