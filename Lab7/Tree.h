#pragma once
#include <iostream>
using namespace std;
template <typename T>
int compara(T firstinfo, T secondinfo)
{
	if (firstinfo < secondinfo)
		return -1;
	else if (firstinfo > secondinfo)
		return 1;
	else
		return 0;
}

template <typename T>
struct Node
{
	T info;
	Node** children;
	unsigned int nrChildren;
};

template <class T>
class Tree
{
public:
	Node<T>* root;

	Tree() {
		root = nullptr;
	}

	void printTree(Node<T>* parent, const string& prefix = "", bool isLast = true) {
		if (parent == nullptr) return;

		cout << prefix;

		if (isLast) cout << "'-- ";
		else cout << "|-- ";

		cout << parent->info << endl;
		for (int i = 0; i < parent->nrChildren; i++) {
			printTree(parent->children[i], prefix + (isLast ? "    " : "|   "), i == parent->nrChildren - 1);
		}
	}


	void add_node(Node<T>* parent, T info)
	{
		if (parent == nullptr) {
			root = new Node<T>;
			root->info = info;
			root->nrChildren = 0;
			root->children = new Node<T>*[10];
			cout << "am adaugat nodul root " << root->info << endl;
		}
		else {
			parent->children[parent->nrChildren] = new Node<T>;
			parent->children[parent->nrChildren]->info = info;
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T>*[10];
			parent->nrChildren++;
			cout << "am adaugat nodul " << parent->children[parent->nrChildren - 1]->info << " la parintele " << parent->info << endl;
		}

	}
	void get_node(Node<T>* parent, int index) {
		if (index<0 || index> parent->nrChildren)
			return root->info;
		return parent->children[index]->info;
	}
	void delete_rec(Node<T>* parent) {
		for (int i = 0; i < parent->nrChildren; i++)
			delete_rec(parent->children[i]);
		delete parent;
	}
	void delete_node(Node<T>* parent) {
		delete_rec(parent);
	}
	T find_rec(Node<T>* parent, T info) {
		if (parent == nullptr)
			return 0;			//valoare implicita
		if (parent->info == info)
			return info;
		for (int i = 0; i < parent->nrChildren; i++)
		{
			T gasit = find_rec(parent->children[i], info);
			if (gasit != 0)
				return gasit;
		}
		return 0;
	}


	void find(T info) {
		if (find_rec(root, info) == 0) cout << "nodul " << info << " nu a fost gasit :(" << endl;
		else cout << "nodul " << info << " a fost gasit!" << endl;
	}

	Node<T>* find_node_rec(Node<T>* parent, T info) {
		if (parent == nullptr)
			return nullptr;

		if (parent->info == info)
			return parent;

		for (int i = 0; i < parent->nrChildren; i++) {
			Node<T>* found = find_node_rec(parent->children[i], info);
			if (found != nullptr)
				return found;
		}
		return nullptr;
	}
	Node<T>* find_node(T info) {
		return find_node_rec(root, info);
	}

	void insert(Node<T>* parent, int index, Node<T>* newNode) {
		parent->nrChildren++;
		for (int i = parent->nrChildren - 1; i > index; i--)
			parent->children[i] = parent->children[i - 1];
		parent->children[index] = newNode;
	}
	void printChildren(Node<T>* parent) {
		if (parent == nullptr) { cout << "null parent" << endl; return; }
		unsigned int i;
		for (i = 0; i < parent->nrChildren; i++)
			cout << parent->children[i]->info << " ";
		cout << "sunt copiii nodului " << parent->info << endl;
	}

	void sort(Node<T>* parent, int (*compara)(T, T)) {
		unsigned int i, j;
		for (i = 0;i < parent->nrChildren - 1;i++)
			for (j = i + 1; j < parent->nrChildren; j++)
			{
				if (compara(parent->children[i]->info, parent->children[j]->info) > 0)
				{
					T aux;
					aux = parent->children[i]->info;
					parent->children[i]->info = parent->children[j]->info;
					parent->children[j]->info = aux;
				}
			}
	}
	int count_rec(Node<T>* parent) {
		int cnt = 0;
		for (int i = 0; i < parent->nrChildren; i++)
			cnt = cnt + count_rec(parent->children[i]);
		return cnt + 1;
	}
	int count(Node<T>* parent) {
		return count_rec(parent);
	}
};