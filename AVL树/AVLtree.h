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
		// �Ҳ���λ��
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
		// ����
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
		// ����_dfƽ������
		while (parent)
		{
			if (cur == parent->_left)
				parent->_df--;
			else
				parent->_df++;

			if (parent->_df >= -1 && parent->_df <= 1)
			{
				//��������
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_df == 0)
			{
				//�����������
				break;
			}
			else if (parent->_df == -2 || parent->_df == 2)
			{
				//��ƽ�⣬Ҫ��ת
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
	void RotateL(Node* parent)//����
	{
		Node* Rightson = parent->_right;

		//��ת�ڵ�֮�������
		parent->_right = Rightson->_left;
		if (parent->_right)
			parent->_right->_parent = parent;
		Rightson->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = Rightson;
		
		//�������ȵ�����
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

	void RotateR(Node* parent)//�ҵ���
	{
		Node* Leftson = parent->_left;

		//��ת�ڵ�֮�������
		parent->_left = Leftson->_right;
		if (parent->_left)
			parent->_left->_parent = parent;
		Leftson->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = Leftson;

		//�������ȵ�����
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

		//ƽ�����Ӹ���
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

		//ƽ�����Ӹ���
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