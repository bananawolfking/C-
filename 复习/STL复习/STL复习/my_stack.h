#pragma once

#include "my_list.h"
#include "my_vector.h"

namespace kele
{
	template<class T, class Container = kele::vector<T>>
	class stack
	{
	public:
		stack(){}
		
		void push(const T& val){ _container.push_back(val);}

		void pop() { _container.pop_back();}

		T& top() { return _container.back();}

		const T& top() const { return _container.back();}

		bool empty() const { return _container.empty();}

		size_t size() const { return _container.size();}

	private:
		Container _container;
	};
}