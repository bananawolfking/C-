#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
namespace kele {

	template<class T>
	struct less
	{
		bool operator()(T& e1, T& e2)
		{
			return e1 < e2;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(T& e1, T& e2)
		{
			return e1 > e2;
		}
	};

	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue {
	public:
		priority_queue() :_con() {}

		template<class InputIterator>
		priority_queue(InputIterator begin, InputIterator end)
			: _con(begin, end)
		{
			for (int i = (_con.size() - 1 - 1) >> 1; i >= 0; --i)
				Adjust_down(i);
		}

		void pop() {
			assert(!empty());

			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjust_down(0);
		}

		bool empty()const {
			return _con.empty();
		}

		size_t size()const {
			return _con.size();
		}

		void push(T x) {
			_con.push_back(x);
			Adjust_up(_con.size() - 1);
		}

		const T& top()const
		{
			return _con.front();
		}

		//向下排序
		void Adjust_down(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && Compare()(_con[child], _con[child + 1]))
					++child;
				if (Compare()(_con[parent], _con[child]))
				{
					//将父节点子节点进行调换
					std::swap(_con[parent], _con[child]);
					//更新父、子节点的位置
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					//堆已经建立成功
					break;
				}

			}
		}

		//向上排序
		void Adjust_up(size_t child) {
			size_t parent = (child - 1) >> 1;
			while (child) {
				if (Compare()(_con[parent], _con[child])) {
					//将父节点子节点进行调换
					std::swap(_con[parent], _con[child]);
					//更新父、子节点的位置
					child = parent;
					parent = (child - 1) >> 1;
				}
				else {
					//堆已经建立成功
					break;
				}
			}
		}
		Container _con;
	};
}