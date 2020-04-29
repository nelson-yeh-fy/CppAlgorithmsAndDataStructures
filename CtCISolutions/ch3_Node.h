#ifndef CH3_NODE_H
#define CH3_NODE_H
template <typename T=int>
class ch3_Node {
public:
	T data;
	ch3_Node* next;
};
#endif //CH3_NODE_H