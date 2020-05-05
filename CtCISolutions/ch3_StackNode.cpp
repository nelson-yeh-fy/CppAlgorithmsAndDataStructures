#ifndef CH3_STACK_NODE_H
#define CH3_STACK_NODE_H
#include "ch3_Stack.h"

template <typename K = int>
class ch3_Stack_Node {
public:
	ch3_Stack<K> TheStack;
	ch3_Stack_Node* nextStack;
	ch3_Stack_Node() {
		TheStack = new ch3_Stack<K>;
		nextStack = nullptr;
	}
};

#endif //CH3_STACK_NODE_H