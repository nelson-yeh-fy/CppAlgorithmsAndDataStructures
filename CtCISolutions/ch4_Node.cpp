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

bool BFS_areTwoNodesConnected(ch4_Node<int>* nA, ch4_Node<int>* nB)
{
	if (nA == nullptr || nB == nullptr)
		return false;
	if (nA == nB)
		return true;

	std::deque<ch4_Node<int>*> q;
	q.push_back(nA);

	while(q.empty() != true) {

		ch4_Node<int>* node = q.front();
		q.pop_front();
		node->visited = true;

		if (node == nB) {
			return true;
		}

		for (auto it = node->adjacents.begin(); it != node->adjacents.end(); it++) {
			if ((*it)->visited != true) {
				q.push_back(*it);
			}
		}
	}

	return false;
}

bool BidirectionalBFS_areTwoNodesConnected(ch4_Node<int>* nA, ch4_Node<int>* nB)
{
	if (nA == nullptr || nB == nullptr)
		return false;
	if (nA == nB)
		return true;

	std::deque<ch4_Node<int>*> q;
	std::deque<ch4_Node<int>*> q2; //q2 is the search target that we'll use it to compare.
	q.push_back(nA); //push nA (start point1)
	q.push_back(nB); //push nB (start point2)
	q2.push_back(nB); //nA nodes need to check if it matches nB.
	q2.push_back(nA);


	while (q.empty() != true) {
		ch4_Node<int>* node = q.front();
		q.pop_front();
		node->visited = true;
		ch4_Node<int>* target = q2.front();
		q2.pop_front();

		if (node == target) {
			return true;
		}

		for (auto it = node->adjacents.begin(); it != node->adjacents.end(); it++) {
			if ((*it)->visited != true) {
				q.push_back(*it);
				q2.push_back(target);
			}
		}
	}

	return false;
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

	ch4_Node<int>* n99 = new ch4_Node<int>(99);
	//DFS_traversal(n10); //remember to clean .visited
	//BFS_traversal(n10); //remember to clean .visited
	
	//std::cout << "DFS Result for 211:" << DFS_search(n10, 211);
	//std::cout << "BFS nodes connected?" << BFS_areTwoNodesConnected(n10, n99) << std::endl;
	std::cout << "BFS nodes connected?" << BidirectionalBFS_areTwoNodesConnected(n10, n23) << std::endl;
}


void ch4_graph_demo2()
{
	//Write an algorithm to build a binary search tree from a sorted arrary (small to big, unique integer)
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	//Brute Force
	//Since BST means all left descendents <= n < all right descendents, we can simply separate it.
	//Top node would be in arr[arr.length/2-1]
}