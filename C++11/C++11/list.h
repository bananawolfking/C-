#pragma once

#include <assert.h>

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
			:_date(val),
			_next(this),
			_prev(this)
		{}

		template<class Args>
		list_node(Args val)
			:_date(val), // 默认在初始化列表调用自定义类型的构造
			_next(this),
			_prev(this)
		{
			//cout << typeid(Args).name() << "!" << endl;
		}

		list_node(T&& val) // 移动构造
		{
			_date = forward<T>(val);
			_next = this;
			_prev = this;
		}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef T value_type;
		typedef Ref reference;
		typedef Ptr pointer;


		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _it;

		__list_iterator()
		{}
		__list_iterator(node* x)
			:_it(x)
		{}

		//template<class t, class ref, class ptr>
		//__list_iterator(const __list_iterator<t,ref,ptr>& x)//不可以，这样const就可以作为左值
		__list_iterator(const iterator& x)
			:_it(x._it)
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

		//typedef Reverse_Iterator<iterator> reverse_iterator;
		//typedef Reverse_Iterator<const_iterator> const_reverse_iterator;

		//typedef Reverse_Iterator<iterator, T&, T*> reverse_iterator;
		//typedef Reverse_Iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin() { return iterator(_head->_next); }

		//_head = _head->_next;// const node* const _head 
		const_iterator begin() const { return const_iterator(_head->_next); }

		iterator end() { return iterator(_head); }

		const_iterator end() const { return const_iterator(_head); }

		//reverse_iterator rbegin() { return reverse_iterator(end()); }

		//const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		//reverse_iterator rend() { return reverse_iterator(begin()); }

		//const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		//*******************************************************************

		list()
		{
			_head = new node;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new node;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		/*list(const list<T>& x)
		{
			_head = new node;
			for (auto e : x)
			{
				push_back(e);
			}
		}*/

		list(const list<T>& x)
		{
			_head = new node;
			list<T> tmp(x.begin(), x.end());
			swap(tmp);
		}

		list(list<T>&& x)
		{
			_head = new node;
			swap(x);
		}

		list<T>& operator=(list<T> x) // 调用的是拷贝构造
		{
			_head = new node;
			swap(x);
			return *this;
		}

		list<T>& operator=(list<T>&& x) // 利用是将亡的右值引用
		{
			_head = new node;
			swap(x);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& val)
		{
			//node* tail = _head->_prev;
			//node* newnode = new node(val);

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), val);
			//为什么可以--end()
			//因为自定义类型的临时对象具有常性，但不是真正的具有常性，可以被修改
		}

		void push_back(T&& val)
		{
			insert(end(), forward<T>(val)); // 完美转发
		}

		template<class... Args>
		void emplace_back(Args... args)
		{
			insert(end(), args...); // 可变类型参数
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

		template<class... Args>
		void insert(iterator pos, Args... args)
		{
			node* prev = pos._it->_prev;
			node* next = pos._it;
			node* newnode = new node(args...);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
		}

		void insert(iterator pos, const T& val)
		{
			node* prev = pos._it->_prev;
			node* next = pos._it;
			node* newnode = new node(val);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
		}

		void insert(iterator pos, T&& val)
		{
			node* prev = pos._it->_prev;
			node* next = pos._it;
			node* newnode = new node(forward<T>(val));

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._it->_prev;
			node* next = pos._it->_next;
			delete pos._it;

			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		void clear()
		{
			/*while (!empty())
			{
				erase(begin());
			}*/

			iterator it = begin();
			while (it != end())
			{
				/*it = erase(it);*/
				erase(it++);
			}
		}

		void swap(list<T>& x)
		{
			std::swap(this->_head, x._head);
		}

		bool empty()
		{
			return begin() == end();
		}

	private:
		node* _head;
	};

}