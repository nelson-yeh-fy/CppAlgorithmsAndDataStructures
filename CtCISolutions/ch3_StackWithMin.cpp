#include "ch3_StackWithMin.h"

void ch3_stack_with_min_demo1()
{
	int min = 0;
	ch3_StackWithMin<int> stack2;
	stack2.push(5);
	stack2.push(6);
	stack2.push(4);
	stack2.push(3);
	stack2.printStack();
	min = stack2.peekMin();
	std::cout << "Min:" << min << std::endl;

	stack2.pop();
	stack2.printStack();
	min = stack2.peekMin();
	std::cout << "Min:" << min << std::endl;

	stack2.push(1);
	stack2.printStack();
	min = stack2.peekMin();
	std::cout << "Min:" << min << std::endl;
}
