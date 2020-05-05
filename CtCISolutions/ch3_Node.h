#ifndef CH3_NODE_H
#define CH3_NODE_H
template <typename T=int>
class ch3_Node {
public:
	T data;
	ch3_Node* next;
	ch3_Node(T value) 
		:data(value), next(nullptr) {}
};
#endif //CH3_NODE_H