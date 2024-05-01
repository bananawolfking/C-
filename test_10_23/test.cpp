#include<iostream>
using namespace std;

class Array
{
	friend ostream& operator<<(ostream& out, const Array& x);
public:
	Array(int n = 10)
	{
		size = n;
		int* parr = (int*)malloc(sizeof(int) * size);
		if (parr == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		arr = parr;
	}

	Array(Array& x)
	{
		size = x.size;
		int* parr = (int*)malloc(sizeof(int) * size);
		if (parr == nullptr)
		{
			perror("malloc error");
			exit(-1);
		}
		arr = parr;
		memcpy(arr, x.arr, sizeof(int) * size);
	}

	~Array()
	{
		free(arr);
		arr = nullptr;
		size = 0;
	}

	int& operator[](int i)
	{
		return arr[i];
	}

	const int& operator[](int i) const
	{
		return arr[i];
	}
private:
	int* arr;
	int size;
};

ostream& operator<<(ostream& out, const Array& x)
{
	for (int i = 0; i < x.size; ++i)
	{
		out << x[i] << " ";
	}
	out << endl;
	return out;
}


int main()
{
	Array a;
	for (int i = 0; i < 10; ++i)
	{
		a[i] = i;
	}
	cout << a;
	return 0;
}