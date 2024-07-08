#pragma once
#include <cassert>

namespace kele
{
	template<class T>
	struct list_node
	{
		list_node* _prev;
		list_node* _next;
		T _val;

		list_node(T val = T()) :_prev(nullptr), _next(nullptr), _val(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr> Self;
		node* _it;

		list_iterator(node* it) :_it(it) 
		{}

		list_iterator(const list_iterator<T, T&, T*>& iterator) :_it(iterator._it)
		{}

		Ptr operator->() {return &(_it->_val);}
		Ref operator*() {return _it->_val; }
		Self operator++() {return _it = _it->_next; }
		Self operator--() {return _it = _it->_prev; }
		bool operator!=(const Self& iterator) const {return _it != iterator._it; }
	};

	template<class T>
	struct list
	{
		typedef list_node<T> node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	public:
		iterator begin() { return iterator(_head->_next); }
		const_iterator begin() const { return const_iterator(_head->_next); }
		iterator end() { return iterator(_head); }
		const_iterator end() const { return const_iterator(_head); }

		list():_head(new node)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			while (!empty())
			{
				pop_front();
			}
			delete _head;
		}

		void insert(iterator pos, const T& val)
		{
			node* next = pos._it;
			node* prev = next->_prev;
			node* newnode = new node(val);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;

			_size++;
		}

		void erase(iterator pos)
		{
			assert(pos._it != _head);
			node* next = pos._it->_next;
			node* prev = pos._it->_prev;
			delete pos._it;
			next->_prev = prev;
			prev->_next = next;

			_size--;
		}

		void push_back(const T& val) { insert(end(), val);  }
		void push_front(const T& val) { insert(begin(), val); }

		void pop_back(){erase(_head->_prev); }
		void pop_front(){erase(begin()); }

		T& back() { return _head->_prev->_val; }
		const T& back() const { return _head->_prev->_val; }
		T& front() { return _head->_next->_val; }
		const T& front() const { return _head->_next->_val; }

		bool empty() const
		{
			return _size == 0;
		}
	private:
		list_node<T>* _head;
		size_t _size = 0;
	};

}