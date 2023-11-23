#pragma once

namespace kele
{
	template<class iteartor, class Ref, class Ptr>
	struct Reverse_Iterator
	{
		typedef Reverse_Iterator<iteartor, Ref, Ptr> self;
		iteartor rit;

		Reverse_Iterator(iteartor x)
			:rit(x)
		{}

		Ref operator*()
		{
			iteartor tmp = rit;
			return *(--tmp);
		}

		Ptr operator->()
		{
			iteartor tmp = rit;
			return &(--tmp);
		}

		self operator++()
		{
			--rit;
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			--rit;
			return tmp;
		}

		self operator--()
		{
			++rit;
			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			++rit;
			return tmp;
		}

		bool operator!=(const self& x) const
		{
			return rit != x.rit;
		}

		bool operator==(const self& x) const
		{
			return rit == x.rit;
		}
	};
}