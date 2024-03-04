#pragma once
#include<assert.h>

enum clour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreenode
{
	RBTreenode* _left;
	RBTreenode* _right;
	RBTreenode* _parent;
	pair<K, V> _kv;
	clour _clr;

	RBTreenode(const pair<K, V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_clr(RED)
	{}
};


template<class K, class V>
class RBTree
{
	typedef RBTreenode<K, V> node;
public:
	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBTree<K, V>& t)
	{
		_root = _copy(t._root);
	}

	RBTree<K, V>& operator==(const RBTree<K, V> t)
	{
		swap(_root, t->_root);
		return *this;
	}

	~RBTree()
	{
		_Destroyed(_root);
		_root = nullptr;
	}

	bool Insert(const pair<K, V>& kv)
	{
		node* newnode = new node(make_pair(kv.first, kv.second));

		if (_root == nullptr)
		{
			_root = newnode;
			_root->_clr = BLACK;
			return true;
		}

		node* cur = _root;
		node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first > newnode->_kv.first)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < newnode->_kv.first)
			{
				cur = cur->_right;
			}
			else
			{
				delete newnode;
				return false;
			}
		}
		//插入
		if (parent->_kv.first > newnode->_kv.first)
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
		if (cur->_kv.first == 32)
			int x = 1;

		if (parent->_clr == BLACK)
		{
			return true;
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

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}


	void RotateR(node* parent)
	{

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
			if (pparent->_kv.first > leftson->_kv.first)
				pparent->_left = leftson;
			else
				pparent->_right = leftson;
		}
		parent->_parent = leftson;
	}

	void RotateL(node* parent)
	{

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
			if (pparent->_kv.first > rightson->_kv.first)
				pparent->_left = rightson;
			else
				pparent->_right = rightson;
		}
		parent->_parent = rightson;
	}


private:
	node* _root;
};

