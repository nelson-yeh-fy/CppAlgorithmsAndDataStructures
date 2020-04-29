#include <iostream>
#include "ch3_Queue.h"
using namespace std;

void ch3_queue_demo1()
{
	const int DEFAULT = 1;
	ch3_Queue<int> Queue1(DEFAULT);
	std::cout << "Value:" << Queue1.getValue() << std::endl;
	Queue1.setValue(2);
	std::cout << "Value:" << Queue1.getValue() << std::endl;

	//Queue push and pop below:
	ch3_Node<int>* new_node = new ch3_Node<int>;
	new_node->data = 10;
	new_node->next = NULL;
	Queue1.push(new_node);
	Queue1.push(11);
	Queue1.push(12);
	Queue1.printQueue();
	Queue1.pop();
	Queue1.printQueue();
	Queue1.push(15);
	Queue1.push(16);
	Queue1.printQueue();
}
