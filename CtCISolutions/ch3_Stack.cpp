#include <iostream>
#include "ch3_Stack.h"
using namespace std;

void ch3_stack_demo1()
{
	ch3_Stack<int> stack1;
	std::cout << "Value:" << stack1.getValue() << std::endl;
	stack1.setValue(2);
	std::cout << "Value:" << stack1.getValue() << std::endl;

	//Stack push and pop below:
	ch3_Node<int>* new_node = new ch3_Node<int>(10);
	stack1.push(new_node);
	stack1.push(11);
	stack1.push(12);
	stack1.printStack();
	stack1.pop();
	stack1.printStack();
	stack1.push(15);
	stack1.push(16);
	stack1.printStack();
}
