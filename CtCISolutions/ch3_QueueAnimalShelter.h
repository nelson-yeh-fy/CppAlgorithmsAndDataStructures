#ifndef CH3_QUEUE_ANIMAL_SHELTER_H
#define CH3_QUEUE_ANIMAL_SHELTER_H
class ch3_Node_as {
public:
	int data;
	bool isDog;
	ch3_Node_as* next;
	ch3_Node_as(int value, bool isDog)
		:data(value), isDog(isDog), next(nullptr) {}
};

class ch3_Queue {
public:
	ch3_Node_as* Front;
	ch3_Node_as* Rear;
	void enqueue(int value, bool isDog);
	ch3_Node_as* dequeue();
	ch3_Node_as* peek();
	ch3_Queue()
		:Front(nullptr), Rear(nullptr) {}
};

class ch3_Queue_as : public ch3_Queue {
public:
	void enqueue(int value, bool isDog);
	ch3_Node_as* dequeueAny();
	ch3_Node_as* dequeueAny(bool isDog);
	ch3_Node_as* dequeueDog();
	ch3_Node_as* dequeueCat();
};
#endif //CH3_QUEUE_ANIMAL_SHELTER_H