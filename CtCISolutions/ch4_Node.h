#ifndef CH4_NODE_H
#define CH4_NODE_H
#include <list>
#include <deque>

template <typename T=int>
class ch4_Node {
public:
	T data;
	bool visited = false;
	std::list<ch4_Node<T>*> adjacents;

	ch4_Node(T value)
		:data(value) {}
	ch4_Node(T value, std::list<ch4_Node<T>*> nodes)
		:data(value), adjacents(nodes) {}


	void printNode();
	void addAdj(ch4_Node<T>* node);
};


void DFS_traversal(ch4_Node<int>* root);
bool DFS_search(ch4_Node<int>* root, int target);

void BFS_traversal(ch4_Node<int>* root);

void ch4_graph_demo1();
#endif

