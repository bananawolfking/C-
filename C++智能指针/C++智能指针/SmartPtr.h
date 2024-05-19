#pragma once

#include <functional>

namespace kele
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr()
			:_ptr(nullptr)
		{}

		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ptr)
			:_ptr(ptr._ptr)
		{
			ptr._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ptr)
		{
			if (this != &ptr)
			{
				_ptr = ptr._ptr;
				ptr._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if(_ptr != nullptr)
				delete _ptr;
			//cout << "delete _ptr" << endl;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr()
			:_ptr(nullptr)
		{}

		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		// C++11�ṩ�Ĺؼ���delete
		unique_ptr(unique_ptr<T>& ptr) = delete;

		unique_ptr<T>& operator=(unique_ptr<T>& ptr) = delete;

		~unique_ptr()
		{
			if (_ptr != nullptr)
				delete _ptr;
			//cout << "delete _ptr" << endl;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// 1.ֻ�ṩ�������������ṩʵ�֣���������û��Լ�����Ҳ��ʵ��
		// 2.private������Ա˽�л����Ϳ�����ȫ���
	//private:
		//unique_ptr(unique_ptr<T>& ptr);
		//unique_ptr<T>& operator=(unique_ptr<T>& ptr);

	private:
		T* _ptr;
	};



	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr()
			:_ptr(nullptr),
			_pcount(new int(1))
		{}

		shared_ptr(T* ptr) noexcept
			:_ptr(ptr),
			_pcount(new int(1))
		{}

		// �ṩdelete����
		template<class D>
		shared_ptr(T* ptr, D del) noexcept // ����lambda���ʽ�Ľ��վͲ���������
			:_ptr(ptr),
			_pcount(new int(1)),
			_del(del)
		{}

		shared_ptr(shared_ptr<T>& ptr) noexcept
			:_ptr(ptr._ptr),
			_pcount(ptr._pcount),
			_del(ptr._del)
		{
			++(*_pcount);
		}

		shared_ptr<T>& operator=(shared_ptr<T>& ptr)
		{
			if (_ptr != ptr._ptr)
			{
				release();
				_ptr = ptr._ptr;
				_pcount = ptr._pcount;
				_del = ptr._del;
				++(*_pcount);
			}
			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		void release()
		{
			if (--(*_pcount) == 0)
			{
				if (_ptr != nullptr)
					_del(_ptr);
			}
			//cout << "delete _ptr" << endl;

		}

		int use_count()
		{
			return *_pcount;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
		// ���ü�����
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};


	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(shared_ptr<T>& ptr) noexcept
			:_ptr(ptr)
		{}

		weak_ptr<T>& operator=(shared_ptr<T>& ptr) noexcept
		{
			if (_ptr != ptr.operator->())
			{
				_ptr = ptr.operator->();
			}
			return *this;
		}

		~weak_ptr()
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

}