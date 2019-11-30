#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>
#include <stack>

template<class T>
class BST														//二叉查找树
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
	void preorder(Node *pn);									//前序树遍历VLR(递归实现)
	void inorder(Node *pn);										//中序树遍历LVR(递归实现)
	void postorder(Node *pn);									//后序树遍历LRV(递归实现)
	virtual void visit(Node * pn){ std::cout << pn->el << std::endl; }

public:
	BST(){ root = 0; }
	//~BST(){ clear(); }
	//void clear(){ clear(root); root = 0; }
	bool isEmpty()const{ return root == 0; }
	void preorder(){ preorder(root); }
	void inorder(){ inorder(root); }
	void postorder(){ postorder(root); }
	T * search(const T & t)const{ return search(root, t); }
	void breadthFirst();										//广度优先遍历（队列实现）
	void iterativePreorder();									//前序树遍历VLR(非递归实现)
	void iterativeInorder();									//中序树遍历VLR(非递归实现)
	void iterativePostorder();									//后序树遍历VLR(非递归实现)
	void MorrisInorder();										//morris算法(不使用栈的遍历(中序))
	void insert(const T & t);
	void deleteByMerging(Node* &pn);							//合并删除
	void findAndDeleteByMerging(const T & t);
	void deleteBycopying(Node *pn);								//复制删除
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

//广度优先遍历
template<class T>
void BST<T>::breadthFirst()
{
	std::queue<Node*> q;
	Node *pn = root;
	if (pn != 0)
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

//深度优先遍历
template<class T>
void BST<T>::inorder(Node *pn)
{
	while (pn != 0)
	{
		inorder(pn->left);
		visit(pn);
		inorder(pn->right);
	}
}

template<class T>
void BST<T>::preorder(Node *pn)
{
	while (pn != 0)
	{
		visit(pn);
		preorder(pn->left);
		preorder(pn->right);
	}
}

template<class T>
void BST<T>::postorder(Node *pn)
{
	while (pn != 0)
	{
		postorder(pn->left);
		postorder(pn->right);
		visit(pn);
	}
}

template<class T>
void BST<T>::iterativePreorder()
{
	Node *p = root;
	std::stack<Node*> s;
	if (p != 0)
	{
		s.push(p);
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			visit(p);
			if (p->left != 0)
				s.push(p->left);
			if (p->right != 0)
				s.push(p->right);
		}
	}
}

template<class T>
void BST<T>::iterativeInorder()
{
	Node *p = root;
	std::stack<Node*> s;
	while ((!s.empty()) || p)
	{
		if (p != 0)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			visit(p);
			p = p->right;
		}
	}
}

template<class T>
void BST<T>::iterativePostorder()
{
	std::stack<Node*> s;
	Node *p = root, *q = root;
	while (p != 0)
	{
		for (; p->left != 0; p = p->left)
			s.push(p);
		while (p->right == 0 || p->right == q)
		{
			visit(p);
			q = p;
			if (s.empty())
				return;
			p = s.top();
			s.pop();
		}
		s.push(p);
		p = p->right;
	}
}

template<class T>
void BST<T>::MorrisInorder()
{
	Node *p = root, *temp;
	while (p != 0)
	{
		if (p->left == 0)
		{
			visit(p);
			p = p->right;
		}
		else
		{
			temp = p->left;
			while (temp->right != 0 && temp->right != p)
				temp = temp->right;
			if (temp->right == 0)
			{
				temp->right = p;
				p = p->left;
			}
			else
			{
				visit(p);
				temp->right = 0;
				p = p->right;
			}
		}
	}
}

template<class T>
void BST<T>::insert(const T & t)
{
	Node *p = root, *prev = 0;
	while (p != 0)
	{
		prev = p;
		if (t < p->el)
			p = p->left;
		else
			p = p->right;
	}
	if (root == 0)
		root = new Node(t);
	else if (t < prev->el)
		prev->left = new Node(t);
	else prev->right = new Node(t);
}

template<class T>
void BST<T>::deleteByMerging(Node*& node)//注意：此处为引用，直接操作该指针
{
	Node* tmp = node;
	if (!node->right)
		node = node->left;
	else if (!node->left)
		node = node->right;
	else//如果该节点有两个子节点
	{
		tmp = node->left;
		while (tmp->right != 0)//找到左子树的最右节点
			tmp = tmp->left;
		tmp->right = node->right;//左子树最右节点作为右子树的父节点
		tmp = node;
		node = node->left;//重新建立连接
	}
	delete tmp;
}
#endif