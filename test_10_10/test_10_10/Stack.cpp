#include"Stack.h"

void Stack::Init(int n)
{
	_arr = (int*)malloc(sizeof(int) * n);
	if (_arr == nullptr)
	{
		perror("malloc error");
		exit(-1);
	}
	_size = 0;
	_capacity = n;
}

void Stack::Push(int i)
{
	if (_size == _capacity)
	{
		int* newp = (int*)realloc(_arr, sizeof(int) * 2 * _capacity);
		if (newp == nullptr)
		{
			perror("realloc error");
			exit(-1);
		}
		_arr = newp;
		_capacity *= 2;
	}
	_arr[_size++] = i;
}

void Stack::Print()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _arr[i] << " ";
	}
	cout << endl;
}