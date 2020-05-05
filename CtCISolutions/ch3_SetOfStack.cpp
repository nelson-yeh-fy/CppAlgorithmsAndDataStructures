#ifndef CH3_SET_OF_STACK_H
#define CH3_SET_OF_STACK_H
#include "ch3_Node.h";
#include "ch3_StackNode.cpp"

template <typename K = int>
class ch3_SetOfStack {
private:
	ch3_Stack_Node<K>* TopStack;
	const int threshold = 3;
public:
	ch3_Node<K>* pop() {
		if (TopStack == nullptr) {
			return nullptr;
		}
		ch3_Node<K>* node = TopStack->TheStack.pop();

		if (TopStack->TheStack.size() == 0) {
			TopStack = TopStack->nextStack;
		}

		return node;
	}

	void push(const K& new_value) {
		if (TopStack == nullptr) {
			TopStack = new ch3_Stack_Node<K>();
		}
		if (TopStack->TheStack.size() >= threshold) {
			ch3_Stack_Node<K>* tmp = new ch3_Stack_Node<K>();
			tmp->nextStack = TopStack;
			tmp->TheStack.push(new_value);
		}
		return;
	}

};

//void ch3_SetOfStack_demo1() {
//	return;
//}
#endif //CH3_SET_OF_STACK_H