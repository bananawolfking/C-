#include"Func.h"

Slist::Slist()
{
	_head = nullptr;
	_tail = nullptr;
}

Node* Slist::BuyNode(int x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == nullptr)
	{
		perror("malloc error");
		exit(-1);
	}
	newnode->_next = nullptr;
	newnode->_val = x;
	return newnode;
}

void Slist::PushBack(int x)
{
	//Node* newnode = BuyNode(x);

	//if (!_tail)
	//{
	//	_head = _tail = newnode;
	//}
	//else
	//{
	//	_tail->_next = newnode;
	//	_tail = _tail->_next;
	//}
	Insert(_tail, x);
}

void Slist::PushFront(int x)
{
	//Node* newnode = BuyNode(x);

	//if (!_head)
	//{
	//	_head = _tail = newnode;
	//}
	//else
	//{
	//	Node* temp = _head;
	//	_head = newnode;
	//	newnode->_next = temp;
	//}
	Insert(nullptr, x);
}

bool Slist::Empty()
{
	return _head == NULL;
}

void Slist::PopBack()
{
	//assert(!Empty());

	//if (_tail == _head)
	//{
	//	free(_head);
	//	_head = _tail = nullptr;
	//}
	//else
	//{
	//	Node* cur = _head;
	//	while (cur->_next != _tail)
	//	{
	//		cur = cur->_next;
	//	}
	//	free(_tail);
	//	_tail = cur;
	//	_tail->_next = nullptr;
	//}
	Erase(_tail);

}

void Slist::PopFront()
{
	//assert(!Empty());

	//if (!_head->_next)
	//{
	//	free(_head);
	//	_head = _tail = nullptr;
	//}
	//else
	//{
	//	Node* temp = _head;
	//	_head = _head->_next;
	//	free(temp);
	//	temp = nullptr;
	//}
	Erase(_head);
}

void Slist::Insert(Node* pos, int x)
{
	Node* newnode = BuyNode(x);
	if (pos == nullptr)
	{
		if (_head == nullptr)
		{
			_head = _tail = newnode;
		}
		else
		{
			Node* temp = _head;
			_head = newnode;
			_head->_next = temp;
		}
	}
	else
	{
		Node* temp = pos->_next;
		pos->_next = newnode;
		newnode->_next = temp;
		if (temp == nullptr)
		{
			_tail = newnode;
		}
	}
}

void Slist::Erase(Node* pos)
{
	assert(!Empty());

	if (pos == nullptr)
	{
		return;
	}

	if (pos == _head)
	{
		if (_head == _tail)
		{
			free(pos);
			_head = _tail = nullptr;
		}
		else
		{
			Node* temp = pos->_next;
			free(pos);
			_head = temp;
		}
	}
	else
	{
		Node* temp = pos->_next;
		Node* cur = _head;
		while (cur->_next != pos)
		{
			cur = cur->_next;
		}
		free(pos);
		cur->_next = temp;
		if (temp == nullptr)
		{
			_tail = cur;
		}
	}
}

Node* Slist::Find(int x)
{
	Node* cur = _head;
	while (cur && cur->_val != x)
	{
		cur = cur->_next;
	}
	if (cur)
	{
		return cur;
	}
}

void Slist::Destroy()
{
	Node* cur = _head;
	while (cur)
	{
		Node* temp = cur->_next;
		free(cur);
		cur = temp;
	}
	_head = _tail = nullptr;
}

void Slist::Print()
{
	Node* cur = _head;

	while (cur)
	{
		cout << cur->_val << "->";
		cur = cur->_next;
	}
	cout << "nullptr" << endl;
}
