#include "ch3_SetOfStack.h"

void ch3_SetOfStack_demo1() 
{
	ch3_SetOfStack<int> stackSet1;
	stackSet1.push(11);
	stackSet1.push(12);
	stackSet1.push(13);
	stackSet1.printStack();
	stackSet1.push(14);
	stackSet1.push(15);
	stackSet1.pop();
	stackSet1.printStack();
	stackSet1.push(17);
	stackSet1.push(18);
	stackSet1.printStack();
}