#include <iostream>
#include "ch3_QueueAnimalShelter.h"

void ch3_Queue::enqueue(int value, bool isDog)
{
	ch3_Node_as* new_node = new ch3_Node_as(value, isDog);
	if (Front == nullptr || Rear == nullptr) {
		Front = new_node;
		Rear = new_node;
		return;
	}
	Rear->next = new_node;
	Rear = new_node;
	return;
}

ch3_Node_as* ch3_Queue::dequeue()
{
	if (Front == nullptr) {
		return nullptr;
	}
	ch3_Node_as* tmp = Front;
	Front = Front->next;
	return tmp;
}

ch3_Node_as* ch3_Queue::peek()
{
	if (Front == nullptr) {
		return nullptr;
	}
	return Front;
}


void ch3_Queue_as::enqueue(int value, bool isDog)
{
	ch3_Queue::enqueue(value, isDog);
	return;
}

ch3_Node_as* ch3_Queue_as::dequeueAny()
{
	return ch3_Queue::dequeue();
}

ch3_Node_as* ch3_Queue_as::dequeueAny(bool isDog)
{
	ch3_Node_as* tmp = Front;
	while (tmp != nullptr) {
		if (tmp->isDog == isDog) {

			ch3_Node_as* NodeToReturn = new ch3_Node_as(1, true);
			NodeToReturn->data = tmp->data;
			NodeToReturn->isDog = tmp->isDog;
			NodeToReturn->next = tmp->next;

			tmp->data = tmp->next->data;
			tmp->isDog = tmp->next->isDog;
			tmp->next = tmp->next->next;
			return NodeToReturn;
		}
		else {
			tmp = tmp->next;
		}
	}
}

ch3_Node_as* ch3_Queue_as::dequeueDog()
{
	return dequeueAny(true);
}

ch3_Node_as* ch3_Queue_as::dequeueCat()
{
	return dequeueAny(false);
}
