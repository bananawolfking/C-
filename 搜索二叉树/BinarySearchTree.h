#pragma once

template<class K>
struct BSTreeNode
{
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _data;

	BSTreeNode(const K& data)
		:_left(nullptr),
		_right(nullptr),
		_data(data)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> node;
public:
	BSTree() :_root(nullptr){}

	BSTree(const BSTree<int>& t)
	{
		_root = Creat(t._root);
	}

	BSTree<int>& operator=(const BSTree<int> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{
		Destroy(_root);
	}

	bool Insert(const K& data)
	{
		if (_root == nullptr)
		{
			_root = new node(data);
			return true;
		}

		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else if (data > cur->_data)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		if (data < parent->_data)
		{
			parent->_left = new node(data);
		}
		else
		{
			parent->_right = new node(data);
		}
	}

	bool Find(const K& data)
	{
		if (_root == nullptr)
			return false;

		node* cur = _root;
		while (cur)
		{
			if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else if (data > cur->_data)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& data)
	{
		node* parent = nullptr;
		node* cur = _root;
		while (cur && cur->_data != data)//找要删除的位置
		{
			parent = cur;
			if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}

		if (cur == nullptr)
			return false;

		if (cur->_left == nullptr)//托孤给父母
		{
			if (parent == nullptr)//考虑特殊
			{
				_root = cur->_right;
			}
			else
			{
				if (cur->_data < parent->_data)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			delete cur;
		}
		else if (cur->_right == nullptr)//托孤给父母
		{
			if (parent == nullptr)
			{
				_root = cur->_left;
			}
			else
			{
				if (cur->_data < parent->_data)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;
		}
		else//找月嫂替代（合适 且只有一个娃或者没有）
		{
			node* maxleft = cur->_left;
			node* maxparent = cur;
			while (maxleft->_right)
			{
				maxparent = maxleft;
				maxleft = maxleft->_right;
			}
			cur->_data = maxleft->_data;
/*			maxparent->_right = maxleft->_left;*///月嫂托孤
			if (maxparent->_left == maxleft)
			{
				maxparent->_left = maxleft->_left;
			}
			else
			{
				maxparent->_right = maxleft->_left;
			}

			delete maxleft;
		}
		return true;
	}

	bool InsertR(const K& data)
	{
		 return _InsertR(_root, data);
	}

	bool FindR(const K& data)
	{
		return _FindR(_root, data);
	}

	bool EraseR(const K& data)
	{
		return _EraseR(_root, data);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

protected:
	node* Creat(node* root)
	{
		if (root == nullptr)
			return nullptr;

		node* newroot = new node(root->_data);
		newroot->_left = Creat(root->_left);
		newroot->_right = Creat(root->_right);
		return newroot;
	}

	void Destroy(node*& root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}


	bool _EraseR(node*& root, const K& data)
	{
		if (root == nullptr)
			return false;

		if (data < root->_data)
			return _EraseR(root->_left, data);
		else if (data > root->_data)
			return _EraseR(root->_right, data);
		else
		{
			node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
				delete del;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
				delete del;
			}
			else
			{
				node* maxleft = root->_left;
				while (maxleft->_right)
					maxleft = maxleft->_right;
				del = maxleft;
				swap(root->_data, maxleft->_data);
				_EraseR(root->_left, data);
			}
			return true;
		}
	}

	bool _FindR(node* root, const K& data)
	{
		if (root == nullptr)
			return false;

		if (data < root->_data)
			return _FindR(root->_left, data);
		else if (data > root->_data)
			return _FindR(root->_right, data);
		else
			return true;
	}

	bool _InsertR(node*& root, const K& data)
	{
		if (root == nullptr)
		{
			root = new node(data);
			return true;
		}

		if (data < root->_data)
			return _InsertR(root->_left, data);
		else if (data > root->_data)
			return _InsertR(root->_right, data);
		else
			return false;
	}

	void _InOrder(node* pnode)
	{
		if (pnode == nullptr)
		{
			return;
		}

		_InOrder(pnode->_left);
		cout << pnode->_data << " ";
		_InOrder(pnode->_right);
	}


private:
	node* _root = nullptr;
};
