#include <iostream>
#include "ch4_Node.h"

using namespace std;

template<typename T>
void ch4_Node<T>::DFS(ch4_Node<T>* rootNode)
{
	if (rootNode == nullptr)
		return;

	rootNode.visited = true;
	//VISIT();
	for (auto & element : rootNode.adjacent) {
		DFS(element);
	}
	return;
}

template<typename T>
void ch4_Node<T>::BFS(ch4_Node<T>* rootNode)
{
	return;
}
