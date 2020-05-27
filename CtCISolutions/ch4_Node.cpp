#include <iostream>
#include "ch4_Node.h"

using namespace std;

void DFS_traversal(ch4_Node<int>* root)
{
	if (root == nullptr)
		return;

	root->visited = true;
	root->printNode();
	for (auto it = root->adjacents.begin(); it != root->adjacents.end(); it++) {
		if ((*it)->visited == false) {
			DFS_traversal(*it);
		}
	}
	return;
}

bool DFS_search(ch4_Node<int>* root, int target)
{
	//if (root == nullptr)
	//	return false;

	//root->visited = true;
	//if (root->data == target) {
	//	return true;
	//}

	//for (auto it = root->adjacents.begin(); it != root->adjacents.end(); it++) {
	//	if ((*it)->visited == false) {
	//		return DFS_search(*it, target);
	//	}
	//}
	return false;
}

void BFS_traversal(ch4_Node<int>* root)
{
	if (root == nullptr)
		return;

	std::deque<ch4_Node<int>*> q;
	q.push_back(root);

	while (q.empty() != true) {
		ch4_Node<int>* node = q.at(0);
		q.pop_front();
		node->visited = true;
		node->printNode();

		for (auto it = node->adjacents.begin(); it != node->adjacents.end(); it++) {
			if ((*it)->visited == false) {
				q.push_back(*it);
			}
		}
	}
	return;
}


template<typename T>
void ch4_Node<T>::printNode()
{
	std::cout << this->data << ",";
}

template<typename T>
void ch4_Node<T>::addAdj(ch4_Node<T>* node)
{
	this->adjacents.push_back(node);
}

void ch4_graph_demo1()
{
	ch4_Node<int>* n21 = new ch4_Node<int>(21);
	n21->addAdj(new ch4_Node<int>(211));

	ch4_Node<int>* n23 = new ch4_Node<int>(23);
	n23->addAdj(new ch4_Node<int>(233));

	ch4_Node<int>* n10 = new ch4_Node<int>(10);
	n10->addAdj(n21);
	n10->addAdj(new ch4_Node<int>(22));
	n10->addAdj(n23);

	DFS_traversal(n10); //remember to clean .visited
	//BFS_traversal(n10); //remember to clean .visited
	//std::cout << "DFS Result for 211:" << DFS_search(n10, 211);
}