#pragma once

namespace kele
{
	template<class T>
	struct less
	{
		bool operator()(const T& a, const T& b) 
		{
			return a < b;
		}
	};


	template<class T>
	struct greater
	{
		bool operator()(const T& a, const T& b) 
		{
			return a > b;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		Compare com;

		priority_queue() {};

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			//Container tmp(first, last);
			//swap(tmp, _con);
			for (int i = ((int)_con.size() - 1 - 1) >> 1; i >= 0; --i)
			{
				adjust_down(i);
			}
		}

		void adjust_up(size_t son)//T(log size())
		{
			size_t parent = (son - 1) / 2;
			while (son != 0)
			{
				if (com(_con[parent], _con[son]))
				{
					swap(_con[son], _con[parent]);
					son = parent;
					parent = (son - 1) / 2;
				}
				else
					break;
			}
		}

		void adjust_down(size_t parent)//T(log size())
		{
			size_t son = parent * 2 + 1;
			while (son < size())
			{
				if (son + 1 < size() && com(_con[son], _con[son + 1]))
				{
					++son;
				}
				if (com(_con[parent], _con[son]))
				{
					swap(_con[son], _con[parent]);
					parent = son;
					son = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void push(T val)
		{
			_con.push_back(val);
			adjust_up(size()-1);
		}

		void pop()
		{
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
