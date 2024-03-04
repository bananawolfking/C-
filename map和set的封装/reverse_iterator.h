#pragma once

namespace kele
{
	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef T                          value_type;
		typedef T* pointer;
		typedef T& reference;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef T                          value_type;
		typedef const T* pointer;
		typedef const T& reference;
	};

	template<class Iteartor>
	struct Reverse_Iterator
	{
		typedef typename iterator_traits<Iteartor>::value_type value_type;
		typedef typename iterator_traits<Iteartor>::reference reference;
		typedef typename iterator_traits<Iteartor>::pointer pointer;

		typedef Reverse_Iterator<Iteartor> self;

		Iteartor rit;

		Reverse_Iterator(Iteartor x)
			:rit(x)
		{}

		template<class iter>
		Reverse_Iterator(const Reverse_Iterator<iter>& x)
			: rit(x.rit)
		{}

		reference operator*()
		{
			Iteartor tmp = rit;
			return *(--tmp);
		}

		pointer operator->()
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