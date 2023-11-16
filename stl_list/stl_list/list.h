#pragma once
#include <iostream>
#include <list>
#include <assert.h>
using namespace std;

namespace kele
{
	template<class T>
	struct list_node
	{
		typedef list_node<T> node;

		node* _next;
		node* _prev;
		T _date;

		list_node(const T& val = T())
		{
			_date = val;
			_next = this;
			_prev = this;
		}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _it;

		__list_iterator(node* x)
			:_it(x)
		{}

		Ref operator*()
		{
			return _it->_date;
		}

		Ptr operator->()
		{
			return &_it->_date;
		}

		self operator++()
		{
			_it = _it->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			_it = _it->_next;
			return tmp;
		}

		self operator--()
		{
			_it = _it->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			_it = _it->_prev;
			return tmp;
		}

		bool operator!=(const self& x) const
		{
			return _it != x._it;
		}

		bool operator==(const self& x) const
		{
			return _it == x._it;
		}

	};


	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		list()
		{
			_head = new node;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);// const node* const _head 的 _head可不可以解引用
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void push_back(const T& val)
		{
			node* tail = _head->_prev;
			node* newnode = new node(val);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			//insert(--end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(const iterator& pos, const T& val)
		{
			node* prev = pos._it->_prev;
			node* next = pos._it;
			node* newnode = new node(val);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
		}

		void erase(const iterator& pos)
		{
			assert(pos != end());

			node* prev = pos._it->_prev;
			node* next = pos._it->_next;
			delete pos._it;

			prev->_next = next;
			next->_prev = prev;
		}

	private:
		node* _head;
	};

}