#pragma once

enum state
{
	EMPTY,
	EXITE,
	DELETE
};

template<class K, class V>
struct Hash_Ndoe
{
	//Hash_Ndoe(const pair<K, V>& kv)
	//	:_state(EMPTY),
	//	_kv(kv)
	//{}

	pair<K, V> _kv;
	state _state = EMPTY;

};

template<class K, class V>
class Hash
{
	typedef Hash_Ndoe<K, V> Node;
public:

	bool Insert(const pair<K, V>& kv)
	{
		//判断空间是否足够
		size_t _v_size = _v.size();
		if (_v_size == 0)
		{
			_v.resize(10);
		}
		else if (_n * 10 / _v_size > 7)
		{
			size_t newsize = _v_size * 2;
			Hash<K, V> newhash;
			newhash._v.resize(newsize);
			for (int i = 0; i < _v_size; ++i)
			{
				if (_v[i]._state == EXITE)
					newhash.Insert(_v[i]._kv);
			}
			_v.swap(newhash._v);
		}

		_v_size = _v.size();
		//找到对应位置
		size_t index = kv.first % _v_size;
		//线性探测
		int x = 1;
		while (_v[index]._state == EXITE)
		{
			if (_v[index]._kv.first == kv.first)
				return false;
			index = index + x;
			index %= _v_size;
		}
		_v[index]._kv = kv;
		_v[index]._state = EXITE;
		_n++;
		return true;

	}

	Node* Find(const K& key)
	{
		size_t _v_size = _v.size();
		if (_v_size == 0)
			return nullptr;
		size_t index = key % _v_size;
		size_t flag = index;
		int x = 1;
		while (_v[index]._state != EMPTY)
		{
			if (_v[index]._state == EXITE && _v[index]._kv.first == key)
				return &_v[index];
			index = index + x;
			index %= _v_size;
			if (flag == index)
				break;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		Node* ret = Find(key);
		if (ret == nullptr)
			return false;

		ret->_state = DELETE;
		_n--;
		return true;
	}


private:
	vector<Node> _v;
	size_t _n = 0;
};
