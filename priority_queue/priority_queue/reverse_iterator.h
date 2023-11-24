#pragma once

namespace kele
{
	/*template<class T, class iteartor, class Ref, class Ptr>*/
	template<class iteartor, class Ref, class Ptr>
	struct Reverse_Iterator
	{
		typedef Reverse_Iterator<iteartor, Ref, Ptr> self;
		/*typedef Reverse_Iterator<T, iteartor, T&, T*> X;*/
		iteartor rit;

		Reverse_Iterator(iteartor x)
			:rit(x)
		{}

		//Reverse_Iterator(X x)
		//	:rit(x.rit)
		//{}

		Ref operator*()
		{
			iteartor tmp = rit;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
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