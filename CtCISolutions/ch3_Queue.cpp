#include <iostream>
#include "ch3_Queue.h"
using namespace std;

void ch3_queue_demo1()
{
	ch3_Queue<int> Queue1;
	ch3_Node<int>* new_node = new ch3_Node<int>(10);
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
