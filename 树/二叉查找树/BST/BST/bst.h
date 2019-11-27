#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>

template<class T>
class BST
{
protected:
	class Node
	{
	public:
		T el;
		Node * left;
		Node * right;
		Node() :left(0), right(0){}
		Node(const T & e, Node *l = 0, Node *r = 0) :el(e), left(l), right(r){}
	};
	Node *root;
	//void clear(Node *pn);
	T * search(Node *pn, const T & t)const;
	void preorder(Node *pn);
	void inorder(Node *pn);
	void postorder(Node *pn);
	virtual void visit(Node * pn){ std::cout << pn->el << std::endl; }

public:
	BST(){ root = 0; }
	//~BST(){ clear(); }
	//void clear(){ clear(root); root = 0; }
	bool isEmpty()const{ return root == 0; }
	void preorder(){ preorder(root); }
	void inorder(){ inorder(root); }
	void postorder(){ postorder(root); }
	T * search(const T & t)const{ search(root, t); }
	void breadthFirst();
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void MorrisInorder();
	void insert(const T & t);
	void deleteByMerging(Node *pn);
	void findAndDeleteByMerging(const T & t);
	void deleteBycopying(Node *pn);
	void balance(T* pt, int, int);
};


template<class T>
T* BST<T>::search(Node *pn, const T & t)const
{
	while (pn != 0)
	{
		if (t == pn->el)
			return &pn->el;
		else if (t < pn->el)
			pn = pn->left;
		else
			pn = pn->right;
	}
	return 0;
}

template<class T>
void BST<T>::breadthFirst()
{
	std::queue<T> q;
	Node *pn = root;
	while (pn != 0)
	{
		q.push(pn);
		while (!q.empty())
		{
			pn = q.front();
			q.pop();
			visit(pn);
			if (pn->left != 0)
				q.push(pn->left);
			if (pn->right != 0)
				q.push(pn->right);
		}
	}
}






#endif