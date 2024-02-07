#pragma once
#include<assert.h>

template<class K, class V>
struct AVLtreeNode
{
	AVLtreeNode* _left;
	AVLtreeNode* _right;
	AVLtreeNode* _parent;
	pair<K, V> _kv;
	int _bf;

	AVLtreeNode(const K& key, const V& val)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(key, val),
		_bf(0)
	{}
};

template<class K, class V>
class AVLtree
{
public:
	typedef AVLtreeNode<K, V> Node;
	typedef pair<K, V> value_type;
	AVLtree() :_root(nullptr){}

	bool insert(const value_type& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val.first, val.second);
			return true;
		}
		// 找插入位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first > val.first)
				cur = cur->_left;
			else if (cur->_kv.first < val.first)
				cur = cur->_right;
			else
				return false;
		}
		// 插入
		if (parent->_kv.first > val.first)
		{
			parent->_left = new Node(val.first, val.second);
			cur = parent->_left;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = new Node(val.first, val.second);
			cur = parent->_right;
			cur->_parent = parent;
		}
		// 更新_bf平衡因子
		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == -1 || parent->_bf == 1)
			{
				//继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 0)
			{
				//无需继续更新
				break;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				//不平衡，要旋转
				if (parent->_bf > 0 && cur->_bf > 0)
					RotateL(parent);
				else if (parent->_bf < 0 && cur->_bf < 0)
					RotateR(parent);
				else if (parent->_bf > 0 && cur->_bf < 0)
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

	bool erase(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
		
		//找key
		Node* cur = _root;
		while(cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else//找到了
			{
				if (cur->_left == nullptr && cur->_right == nullptr)//删除的节点是叶子节点
				{
					cur = DeleteNode(cur);
				}
				else if (cur->_left == nullptr)
				{
					Node* del = cur->_right;
					cur->_kv = del->_kv;
					cur = DeleteNode(del);
				}
				else if (cur->_right == nullptr)
				{
					Node* del = cur->_left;
					cur->_kv = del->_kv;
					cur = DeleteNode(del);
				}
				else
				{
					//找左子树的最大节点
					Node* leftmax = cur->_left;
					while (leftmax->_right)
						leftmax = leftmax->_right;

					cur->_kv = leftmax->_kv;

					//是否需要托孤
					if(leftmax->_left)
					{
						Node* del = leftmax->_left;
						leftmax->_kv = del->_kv;
						cur = DeleteNode(del);
					}
					else
					{
						Node* del = leftmax;
						cur = DeleteNode(del);
					}
				}
				if (cur == nullptr)//根节点被删除
					return true;
				if (cur->_bf == 2 || cur->_bf == -2)//删除那个节点导致不平衡
				{
					Node* parent = cur;
					cur = nullptr;
					Rotate_delete_check(parent, cur);
				}
				
				//更新平衡因子
				Node* parent = cur->_parent;
				while (parent && cur->_bf == 0)//cur的平衡因子是0才需要更新
				{
					if (parent->_left == cur)
						parent->_bf++;
					else
						parent->_bf--;

					if (parent->_bf == -1 || parent->_bf == 1)
					{
						//无需继续更新
						break;
					}
					else if (parent->_bf == 0)
					{
						//继续更新
						cur = parent;
						parent = parent->_parent;
					}
					else if (parent->_bf == -2 || parent->_bf == 2)
					{
						cout << "//////////////////////////////" << endl;
						Rotate_delete_check(parent, cur);
					}
				}
				return true;
			}
		}
		return false;
	}

	bool check_balance()
	{
		return _check_balance(_root);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:

	Node* DeleteNode(Node* cur)//删除叶子节点，并且返回其父亲
	{
		Node* del = cur;
		Node* parent = cur->_parent;
		if (parent == nullptr)//cur是根节点
		{
			_root = nullptr;
			delete del;
			return nullptr;
		}
		if (parent->_left == del)
		{
			parent->_left = nullptr;
			parent->_bf++;
		}
		else
		{
			parent->_right = nullptr;
			parent->_bf--;
		}
		delete del;
		return parent;
	}

	void Rotate_delete_check(Node*& parent, Node*& cur)
	{
		Node* uncle;
		if (parent->_left == cur)
			uncle = parent->_right;
		else
			uncle = parent->_left;

		if (parent->_bf == 2 && uncle->_bf == 1)
		{
			RotateL(parent);
			cur = uncle;
		}
		else if (parent->_bf == -2 && uncle->_bf == -1)
		{
			RotateR(parent);
			cur = uncle;
		}
		else if (parent->_bf == 2 && uncle->_bf == -1)
		{
			cur = uncle->_left;
			RotateRL(parent);
		}
		else if (parent->_bf == -2 && uncle->_bf == 1)
		{
			cur = uncle->_right;
			RotateLR(parent);
		}
		else if (parent->_bf == 2 && uncle->_bf == 0)
		{
			RotateL(parent);
			parent->_bf = 1;
			uncle->_bf = -1;
			cur = uncle;
		}
		else if (parent->_bf == -2 && uncle->_bf == 0)
		{
			RotateR(parent);
			parent->_bf = -1;
			uncle->_bf = 1;
			cur = uncle;
		}
		else assert(false);
		parent = cur->_parent;
	}

	void balence_check(Node* parent, Node* cur)
	{
		if (parent == nullptr)
			return;
		if (parent->_bf == 0)
		{
			//无需继续更新
		}
		else if (parent->_bf == -2 || parent->_bf == 2)
		{
			//不平衡，要旋转
			if (parent->_bf > 0 && cur->_bf > 0)
				RotateL(parent);
			else if (parent->_bf < 0 && cur->_bf < 0)
				RotateR(parent);
			else if (parent->_bf > 0 && cur->_bf < 0)
				RotateRL(parent);
			else
				RotateLR(parent);
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool _check_balance(Node* root)
	{
		if (root == nullptr)
			return true;

		int lefthight = TreeHight(root->_left);
		int righthight = TreeHight(root->_right);
		if (abs(lefthight - righthight) >= 2 || righthight - lefthight != root->_bf)
		{
			cout << root->_kv.first << ":" << root->_bf << endl;
			return false;
		}
		return _check_balance(root->_left) && _check_balance(root->_right);
	}

	int TreeHight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lefthight = TreeHight(root->_left);
		int righthight = TreeHight(root->_right);
		return lefthight > righthight ? lefthight + 1: righthight + 1;
	}


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
		parent->_bf = Rightson->_bf = 0;
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
		parent->_bf = Leftson->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* Leftson = parent->_left;
		Node* LRightsson = Leftson->_right;
		int bf = LRightsson->_bf;

		RotateL(Leftson);
		RotateR(parent);

		//平衡因子更新
		if (bf == 1)
		{
			Leftson->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
		}
		else if (bf == 0) {}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* Rightson = parent->_right;
		Node* RLeftsson = Rightson->_left;
		int bf = RLeftsson->_bf;

		RotateR(Rightson);
		RotateL(parent);

		//平衡因子更新
		if (bf == 1)
		{
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			Rightson->_bf = 1;
		}
		else if(bf == 0){}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root;
};