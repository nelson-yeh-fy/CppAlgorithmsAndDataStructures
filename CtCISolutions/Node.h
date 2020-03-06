#ifndef NODE_H
#define NODE_H
template <typename T>
class Node{
public:
	T val;
	Node* next;
};

template <class E>
static void printNode(E* ptr) {
	while (ptr != NULL) {
		std::cout << ptr->val;
		ptr = ptr->next;
	}
}
#endif // !NODE_H
