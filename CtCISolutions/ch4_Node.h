#ifndef CH4_NODE_H
#define CH4_NODE_H
#include <vector>

template <typename T=int>
class ch4_Node {
public:
	T data;
	bool visisted = false;
	std::vector<ch4_Node<T>*> adjacentNodes;

	ch4_Node(T value)
		:data(value) {}
	ch4_Node(T value, std::vector<ch4_Node<T>*> nodes)
		:data(value), adjacentNodes(nodes){}

	void DFS(ch4_Node<T>* rootNode);
	void BFS(ch4_Node<T>* rootNode);
};
#endif

