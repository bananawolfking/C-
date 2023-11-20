#pragma once

namespace kele
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		stack()
		{}
		
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}


	private:
		Container _con;
	};
}
