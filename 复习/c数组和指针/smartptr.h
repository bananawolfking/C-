#pragma once
#include <functional>
#include <atomic>

// auto_ptr
namespace kele
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr):_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& aptr):_ptr(aptr._ptr)
		{
			aptr._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
				aptr._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			delete _ptr;
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }

	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
		typedef unique_ptr<T> self_ptr;
	public:
		
		unique_ptr(T* ptr) :_ptr(ptr)
		{}

		template<class del>
		unique_ptr(T* ptr, del delfunc) :_ptr(ptr), _del(delfunc)
		{}

		unique_ptr(self_ptr& aptr) = delete;

		self_ptr& operator=(self_ptr& aptr) = delete;

		unique_ptr(self_ptr&& aptr)
			:_ptr(nullptr)
		{
			swap(_ptr, aptr._ptr);
			swap(_del, aptr._del);
		}

		self_ptr& operator=(self_ptr&& aptr)
		{
			if (this != &aptr)
			{
				swap(_ptr, aptr._ptr);
				swap(_del, aptr._del);
			}
			return *this;
		}

		~unique_ptr()
		{
			_del(_ptr);
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }
	private:
		T* _ptr;
		std::function<void(T*)> _del = [](T* ptr) {
			//if(ptr != nullptr)
				delete ptr; 
		};
	};


	template<class T>
	class shared_ptr
	{
		typedef shared_ptr<T> self_ptr;
	public:

		shared_ptr(T* ptr) :_ptr(ptr), _ref_count(new std::atomic<size_t>(1))
		{}

		// 对于lambda表达式的接收就不能用引用
		template<class del>
		shared_ptr(T* ptr, const del& delfunc) 
			: _ptr(ptr), _del(delfunc), 
			_ref_count(new std::atomic<size_t>(1))
		{}

		shared_ptr(self_ptr& aptr)
			:_ptr(aptr._ptr), _del(aptr._del), _ref_count(aptr._ref_count)
		{
			(*_ref_count)++;
		}

		self_ptr& operator=(self_ptr& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
				_del = aptr._del;
				_ref_count = aptr._ref_count;
				(*_ref_count)++;
			}
			return *this;
		}

		shared_ptr(self_ptr&& aptr)
			:_ptr(nullptr), _ref_count(new std::atomic<size_t>(1))
		{
			swap(_ptr, aptr._ptr);
			swap(_del, aptr._del);
			swap(_ref_count, _ref_count);
		}

		self_ptr& operator=(self_ptr&& aptr)
		{
			if (this != &aptr)
			{
				swap(_ptr, aptr._ptr);
				swap(_del, aptr._del);
				swap(_ref_count, _ref_count);
			}
			return *this;
		}

		~shared_ptr()
		{
			(*_ref_count)--;
			if(*_ref_count == 0)
				_del(_ptr);
		}

		T& operator*() { return *_ptr; }

		T* operator->() { return _ptr; }

		T* get() { return _ptr; }
	private:
		T* _ptr;

		// 定制删除器
		std::function<void(T*)> _del = [](T* ptr) {
			//if(ptr != nullptr)
			cout << "delete" << endl;
			delete ptr;
		};

		std::atomic<size_t>* _ref_count; // 引用计数
	};


	template<class T>
	class weak_ptr
	{
		typedef weak_ptr<T> self_ptr;
	public:

		weak_ptr(T* ptr) :_ptr(ptr)
		{}

		weak_ptr(self_ptr& aptr)
			:_ptr(aptr._ptr)
		{}

		weak_ptr(shared_ptr<T>& aptr)
			:_ptr(aptr.get())
		{}

		self_ptr& operator=(self_ptr& aptr)
		{
			if (this != &aptr)
			{
				_ptr = aptr._ptr;
			}
			return *this;
		}

		self_ptr& operator=(shared_ptr<T>& aptr)
		{
			_ptr = aptr.get();
			return *this;
		}

		~weak_ptr()
		{
			cout << "weak delete" << endl;
		}

		T& operator*() { return *_ptr;}

		T* operator->(){ return _ptr;}
	private:
		T* _ptr;
	};

}