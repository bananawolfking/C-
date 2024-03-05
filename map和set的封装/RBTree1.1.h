#pragma once
#include<assert.h>
#include"reverse_iterator.h"
using namespace kele;

enum clour
{
	RED,
	BLACK
};

template<class V>
struct RBTreenode
{
	RBTreenode<V>* _left;
	RBTreenode<V>* _right;
	RBTreenode<V>* _parent;
	V _value;
	clour _clr;

	RBTreenode(const V& value)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_value(value),
		_clr(RED)
	{}
};

template<class T, class Ref, class Ptr>
class __RBTree_iterator
{
public:
	typedef RBTreenode<T> Node;
	typedef T value_type;
	typedef Ref reference;
	typedef Ptr pointer;

	typedef __RBTree_iterator<T, T&, T*> iterator;
	typedef __RBTree_iterator<T, const T&, const T*> const_iterator;
	typedef __RBTree_iterator<T, Ref, Ptr> self;

	__RBTree_iterator(Node* node = nullptr, Node* root = nullptr)
		:_node(node),
		_root(root)
	{}

	//**********const_iterator和iterator迭代器的转换
	__RBTree_iterator(const iterator& it)
		:_node(it._node),
		_root(it._root)
	{}

	Ref operator*()
	{
		return _node->_value;
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	bool operator!=(const self& x) const
	{
		return _node != x._node;
	}

	bool operator==(const self& x) const
	{
		return _node == x._node;
	}

	self& operator++()
	{
		if (_node == nullptr)
		{
			assert(1);
			return *this;
		}
		Node* cur = _node;
		if (_node->_right)
		{
			cur = cur->_right;
			while (cur->_left)
				cur = cur->_left;
		}
		else
		{
			Node* parent = cur->_parent;
			while (parent && parent->_left != cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			cur = parent;
		}
		_node = cur;
		return *this;
	}

	self& operator--()
	{
		if (_node == nullptr && _root == nullptr)
		{
			assert(1);
			return *this;
		}
		else if (_node == nullptr && _root != nullptr)
		{
			Node* cur = _root;
			while (cur->_right)
				cur = cur->_right;
			_node = cur;
			return *this;
		}
		Node* cur = _node;
		if (cur->_left)
		{
			cur = cur->_left;
			while (cur && cur->_right)
				cur = cur->_right;
		}
		else
		{
			Node* parent = cur->_parent;
			while (parent && parent->_right != cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			cur = parent;
		}
		_node = cur;
		return *this;
	}

	Node* _node;
	Node* _root;
};

template<class K, class V, class KeyOfValue, class Compare>
class RBTree
{
	typedef RBTree<K, V, KeyOfValue, Compare> RBtree;
	typedef RBTreenode<V> node;
	typedef K key_type;
	typedef V value_type;

public:
	typedef __RBTree_iterator<V, V&, V*> iterator;
	typedef __RBTree_iterator<V, const V&, const V*> const_iterator;
	typedef Reverse_Iterator<iterator> reverse_iterator;
	typedef Reverse_Iterator<const_iterator> const_reverse_iterator;

	iterator begin()
	{
		node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur, _root);
	}
	iterator end()
	{
		return iterator(nullptr, _root);
	}
	const_iterator begin() const
	{
		return const_iterator(begin());
	}
	const_iterator end() const
	{
		return const_iterator(nullptr, _root);
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}


	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBtree& t)
	{
		_root = _copy(t._root);
	}

	RBtree& operator==(const RBtree t)
	{
		swap(_root, t->_root);
		return *this;
	}

	~RBTree()
	{
		_Destroyed(_root);
		_root = nullptr;
	}

	pair<iterator, bool> Insert(const value_type& v)
	{
		node* newnode = new node(v);

		if (_root == nullptr)
		{
			_root = newnode;
			_root->_clr = BLACK;
			return make_pair(iterator(_root, _root), true);
		}

		node* cur = _root;
		node* parent = nullptr;
		KeyOfValue kov;
		Compare com;
		while (cur)
		{
			key_type k_cur = kov(cur->_value);
			key_type k_newnode = kov(newnode->_value);
			parent = cur;
			if (!com(k_cur, k_newnode) && k_cur != k_newnode) //!( x < y) 等价于 (x >= y)
			{
				cur = cur->_left;
			}
			else if (com(k_cur, k_newnode))
			{
				cur = cur->_right;
			}
			else
			{
				delete newnode;
				return make_pair(iterator(cur, _root), false) ;
			}
		}
		//插入
		if (!com(kov(parent->_value), kov(newnode->_value)))
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}

		cur = newnode;
		cur->_clr = RED;

		//调整该树
		if (parent->_clr == BLACK)
		{
			return make_pair(iterator(newnode, _root), true);
		}
		else
		{
			while (parent && parent->_clr != BLACK)
			{
				node* grandfather = parent->_parent;
				if (parent == grandfather->_left)
				{
					node* uncle = grandfather->_right;
					if (uncle && uncle->_clr == RED)
					{
						uncle->_clr = parent->_clr = BLACK;
						grandfather->_clr = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_left)
						{
							//		g
							//	  p
							//	c
							//右旋
							RotateR(grandfather);
							parent->_clr = BLACK;
							grandfather->_clr = RED;
						}
						else
						{
							//		g
							//	  p
							//	   c
							//左右双旋
							RotateL(parent);
							RotateR(grandfather);
							cur->_clr = BLACK;
							grandfather->_clr = RED;
						}
						break;
					}
				}
				else
				{
					node* uncle = grandfather->_left;
					if (uncle && uncle->_clr == RED)
					{
						uncle->_clr = parent->_clr = BLACK;
						grandfather->_clr = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_right)
						{
							//	g
							//	  p
							//		c
							//左旋
							RotateL(grandfather);
							parent->_clr = BLACK;
							grandfather->_clr = RED;
						}
						else
						{
							//	g
							//	  p
							//	 c
							//右左双旋
							RotateR(parent);
							RotateL(grandfather);
							cur->_clr = BLACK;
							grandfather->_clr = RED;
						}
						break;
					}
				}
			}
		}
		_root->_clr = BLACK;
		return make_pair(iterator(newnode, _root), true);
	}

	bool Erase(const key_type& key)
	{
		if (_root == nullptr)
			return false;

		node* cur = _root;
		node* parent = nullptr;
		KeyOfValue kov;
		Compare com;
		while (cur)
		{
			key_type k_cur = kov(cur->_value);
			if (!com(k_cur, key) && k_cur != key) //!( x < y) 等价于 (x >= y)
			{
				cur = cur->_left;
			}
			else if (com(k_cur, key))
			{
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}
		if (cur == nullptr)
			return false;
		parent = cur->_parent;
		//找到
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			Delete_Leafnode(cur);
		}
		else if (cur->_left != nullptr && cur->_right == nullptr)
		{
			node* kid = cur->_left;
			node* newnode = new node(kid->_value);
			Delete_Leafnode(kid);
			if (parent == nullptr)
			{
				_root = newnode;
			}
			if (cur == parent->_left)
			{
				parent->_left = newnode;
			}
			else
			{
				parent->_right = newnode;
			}
			delete cur;
		}
		else if (cur->_left == nullptr && cur->_right != nullptr)
		{
			node* kid = cur->_right;
			node* newnode = new node(kid->_value);
			Delete_Leafnode(kid);
			if (parent == nullptr)
			{
				_root = newnode;
			}
			if (cur == parent->_left)
			{
				parent->_left = newnode;
			}
			else
			{
				parent->_right = newnode;
			}
			delete cur;
		}
		else if (cur->_left != nullptr && cur->_right != nullptr)
		{
			node* leftmax = cur->_left;
			while (leftmax->_right)
			{
				leftmax = leftmax->_right;
			}
			node* newnode = new node(leftmax->_value);
			newnode->_left = cur->_left;
			newnode->_right = cur->_right;
			newnode->_parent = parent;
			newnode->_clr = cur->_clr;
			if (parent == nullptr)
				_root = newnode;
			else
			{
				if (cur == parent->_left)
				{
					parent->_left = newnode;
				}
				else
				{
					parent->_right = newnode;
				}
			}
			cur->_right->_parent = newnode;
			cur->_left->_parent = newnode;
			delete cur;
			cur = newnode;
			if (leftmax->_left)
			{
				node* kid = leftmax->_left;
				node* newnode1 = new node(kid->_value);
				Delete_Leafnode(kid);
				if (leftmax == leftmax->_parent->_left)
				{
					delete leftmax;
					parent->_left = newnode1;
				}
				else
				{
					delete leftmax;
					parent->_right = newnode1;
				}
			}
			else
			{
				Delete_Leafnode(leftmax);
			}
		}
		return true;

	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool RBTree_Check()
	{
		if (_root == nullptr)
			return true;
		if (_root && _root->_clr != BLACK)
		{
			cout << "根节点不是黑色" << endl;
			return false;
		}
		//检查红节点的两个子节点都为红色
		//每条路径有相同数目的黑
		int count = -1;
		return _Check1(_root) && _Check2(_root, 0, count);
	}

	int TreeHightMax()
	{
		return _TreeHightMax(_root);
	}

	int TreeHightMin()
	{
		return _TreeHightMin(_root);
	}

private:
	void Delete_Leafnode(node* cur)
	{
		node* parent = cur->_parent;
		if (parent == nullptr)
		{
			delete cur;
			_root = nullptr;
			return;
		}

		//删除cur，parent的链接
		if (cur == parent->_left)
			parent->_left = nullptr;
		else
			parent->_right = nullptr;
		if (cur->_clr == RED)
		{
			delete cur;
			return;
		}
		delete cur;
		

		node* brother = parent->_left;

		if (cur == parent->_left)
			brother = parent->_right;
		if (brother == nullptr)
			int x = 1;
		//brother没有孩子
		if (brother->_left == nullptr && brother->_right == nullptr)
		{
			if (parent->_clr == RED)
			{
				brother->_clr = RED;
				parent->_clr = BLACK;
			}
			else
			{
				brother->_clr = RED;
				while (parent && parent->_clr != RED)
				{
					cur = parent;
					parent = cur->_parent;
				}
				if (parent)
					parent->_clr = BLACK;
			}
		}
		else if (brother->_left != nullptr && brother->_right != nullptr)
		{
			if (brother == parent->_right)
			{
				brother->_right->_clr = BLACK;
				RotateL(parent);
			}
			else
			{
				brother->_left->_clr = BLACK;
				RotateR(parent);
			}
			if (parent->_clr == RED)
				brother->_clr = RED;
			parent->_clr = BLACK;
		}
		else if (brother->_left == nullptr && brother->_right != nullptr)
		{
			node* kid = brother->_right;
			if (brother == parent->_right)
			{
				kid->_clr = BLACK;
				if (parent->_clr == RED)
					brother->_clr = RED;
				parent->_clr = BLACK;
				RotateL(parent);
			}
			else
			{
				if (parent->_clr == BLACK)
				{
					kid->_clr = BLACK;
				}
				parent->_clr = BLACK;
				RotateL(brother);
				RotateR(parent);
			}
		}
		else if (brother->_left != nullptr && brother->_right == nullptr)
		{
			node* kid = brother->_left;
			if (brother == parent->_left)
			{
				kid->_clr = BLACK;
				if (parent->_clr == RED)
					brother->_clr = RED;
				parent->_clr = BLACK;
				RotateR(parent);
			}
			else
			{
				if (parent->_clr == BLACK)
				{
					kid->_clr = BLACK;
				}
				parent->_clr = BLACK;
				RotateR(brother);
				RotateL(parent);
			}
		}

	}

	void _Destroyed(node* root)
	{
		if (root == nullptr)
			return;

		_Destroyed(root->_left);
		_Destroyed(root->_right);
		delete root;
	}

	node* _copy(node* root)
	{
		if (root == nullptr)
			return nullptr;

		node* newnode = new node(root->_kv);
		newnode->_clr = root->_clr;
		node* left = _copy(root->_left);
		node* right = _copy(root->_right);
		if (left)
			left->_parent = newnode;
		if (right)
			right->_parent = newnode;
		newnode->_left = left;
		newnode->_right = right;
		return newnode;
	}

	int _TreeHightMax(node* root)
	{
		if (root == nullptr)
			return 0;

		int lefthight = _TreeHightMax(root->_left);
		int righthight = _TreeHightMax(root->_right);

		return lefthight > righthight ? lefthight + 1 : righthight + 1;
	}

	int _TreeHightMin(node* root)
	{
		if (root == nullptr)
			return 0;

		int lefthight = _TreeHightMin(root->_left);
		int righthight = _TreeHightMin(root->_right);

		return lefthight < righthight ? lefthight + 1 : righthight + 1;
	}

	bool _Check1(node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_clr == RED && root->_parent && root->_parent->_clr == RED)
		{
			return false;
		}

		return _Check1(root->_left) && _Check1(root->_right);
	}

	bool _Check2(node* root, int num, int& count)
	{
		if (root == nullptr)
		{
			if (count == -1)
				count = num;
			return count == num;
		}

		if (root->_clr == BLACK)
			++num;
		return _Check2(root->_left, num, count) && _Check2(root->_right, num, count);
	}

	void _InOrder(node* root)
	{
		if (root == nullptr)
			return;

		KeyOfValue kov;
		_InOrder(root->_left);
		cout << kov(root->_value) << "->" << root->_clr << " ";
		_InOrder(root->_right);
	}

	void RotateR(node* parent)
	{
		KeyOfValue kov;
		Compare com;
		node* pparent = parent->_parent;
		node* leftson = parent->_left;

		parent->_left = leftson->_right;
		if (leftson->_right)
			leftson->_right->_parent = parent;
		leftson->_right = parent;

		leftson->_parent = pparent;
		if (pparent == nullptr)
		{
			_root = leftson;
		}
		else
		{
			if (!com(kov(pparent->_value), kov(leftson->_value)))
				pparent->_left = leftson;
			else
				pparent->_right = leftson;
		}
		parent->_parent = leftson;
	}

	void RotateL(node* parent)
	{
		KeyOfValue kov;
		Compare com;
		node* pparent = parent->_parent;
		node* rightson = parent->_right;

		parent->_right = rightson->_left;
		if (rightson->_left)
			rightson->_left->_parent = parent;
		rightson->_left = parent;

		rightson->_parent = pparent;
		if (pparent == nullptr)
		{
			_root = rightson;
		}
		else
		{
			if (!com(kov(pparent->_value), kov(rightson->_value)))
				pparent->_left = rightson;
			else
				pparent->_right = rightson;
		}
		parent->_parent = rightson;
	}


private:
	node* _root;
};

