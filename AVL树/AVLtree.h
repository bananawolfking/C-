#pragma once
#include<assert.h>

template<class K, class V>
struct AVLtreeNode
{
	AVLtreeNode* _left;
	AVLtreeNode* _right;
	AVLtreeNode* _parent;
	pair<K, V> _kv;
	int _df;

	AVLtreeNode(const K& key, const V& val)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(key, val),
		_df(0)
	{}
};

template<class K, class V>
class AVLtree
{
public:
	typedef AVLtreeNode<K, V> Node;
	AVLtree() :_root(nullptr){}

	bool insert(const K& key, const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, val);
			return true;
		}
		// 找插入位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first > key)
				cur = cur->_left;
			else if (cur->_kv.first < key)
				cur = cur->_right;
			else
				return false;
		}
		// 插入
		if (parent->_kv.first > key)
		{
			parent->_left = new Node(key, val);
			cur = parent->_left;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = new Node(key, val);
			cur = parent->_right;
			cur->_parent = parent;
		}
		// 更新_df平衡因子
		while (parent)
		{
			if (cur == parent->_left)
				parent->_df--;
			else
				parent->_df++;

			if (parent->_df >= -1 && parent->_df <= 1)
			{
				//继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_df == 0)
			{
				//无需继续更新
				break;
			}
			else if (parent->_df == -2 || parent->_df == 2)
			{
				//不平衡，要旋转
				if (parent->_df > 0 && cur->_df > 0)
					RotateL(parent);
				else if (parent->_df < 0 && cur->_df < 0)
					RotateR(parent);
				else if (parent->_df > 0 && cur->_df < 0)
					RotateRL(parent);
				else
					RotateLR(parent);
				
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

private:
	void RotateL(Node* parent)//左单旋
	{
		Node* Rightson = parent->_right;

		//旋转节点之间的链接
		parent->_right = Rightson->_left;
		if (parent->_right)
			parent->_right->_parent = parent;
		Rightson->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = Rightson;
		
		//更新祖先的链接
		if (pparent == nullptr)
		{
			Rightson->_parent = nullptr;
			_root = Rightson;
		}
		else
		{
			if (pparent->_kv.first > Rightson->_kv.first)
				pparent->_left = Rightson;
			else
				pparent->_right = Rightson;
			Rightson->_parent = pparent;
		}
		parent->_df = Rightson->_df = 0;
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* Leftson = parent->_left;

		//旋转节点之间的链接
		parent->_left = Leftson->_right;
		if (parent->_left)
			parent->_left->_parent = parent;
		Leftson->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = Leftson;

		//更新祖先的链接
		if (pparent == nullptr)
		{
			Leftson->_parent = nullptr;
			_root = Leftson;
		}
		else
		{
			if (pparent->_kv.first > Leftson->_kv.first)
				pparent->_left = Leftson;
			else
				pparent->_right = Leftson;
			Leftson->_parent = pparent;
		}
		parent->_df = Leftson->_df = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* Leftson = parent->_left;
		Node* LRightsson = Leftson->_right;
		int df = LRightsson->_df;

		RotateL(Leftson);
		RotateR(parent);

		//平衡因子更新
		if (df == 1)
		{
			Leftson->_df = -1;
		}
		else if (df == -1)
		{
			parent->_df = 1;
		}
		else if (df == 0) {}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* Rightson = parent->_right;
		Node* RLeftsson = Rightson->_left;
		int df = RLeftsson->_df;

		RotateR(Rightson);
		RotateL(parent);

		//平衡因子更新
		if (df == 1)
		{
			parent->_df = -1;
		}
		else if (df == -1)
		{
			Rightson->_df = 1;
		}
		else if(df == 0){}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root;
};