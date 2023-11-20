#pragma once

namespace kele
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
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