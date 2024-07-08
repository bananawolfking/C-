#pragma once

#include "my_list.h"

namespace kele
{
	template<class T, class Container = kele::list<T>>
	class queue
	{
	public:
		queue(){}

		void push(const T& val) { _container.push_back(val);}

		void pop() { _container.pop_front();}

		T& front() { return _container.front();}

		const T& front() const { return _container.front();}

		T& back() { return _container.back();}

		const T& back() const { return _container.back();}

		bool empty() const { return _container.empty();}

		size_t size() const { return _container.size();}
	private:
		Container _container;
	};
}