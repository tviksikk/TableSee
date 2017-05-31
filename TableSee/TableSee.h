#pragma once
#include <iostream>

template<class K, class V>
class table
{
private:
	K* kkkkkk;
	V* vvvvvv;
	int size,used;

public:
	table(int size);
	~table();

	void add(K k, V v);
	void remove(K k);
	V& operator[](K k);
	table& operator = (table& vt);
	void resize(int newsized);

};

template<class K, class V>
table<K,V>::table(int size)
{
	this->size = size;
	kkkkkk = new K[size];
	for (size_t i = 0; i < size; i++)
	{
		kkkkkk[i] = K();
	}
	vvvvvv = new V[size];
	used = 0;
}

template<class K, class V>
table<K, V>::~table()
{
	delete[]kkkkkk;
	delete[]vvvvvv;
}

template<class K, class V>
void table<K, V>::add(K k, V v)
{
	for (size_t i = 0; i < size; i++)
	{
		if (kkkkkk[i] == K())
		{
			kkkkkk[i] = k;
			vvvvvv[i] = v;
			used++;
			return;
		}
	}

	throw 1;

}

template<class K, class V>
void table<K, V>::remove(K k)
{
	for (int i = 0; i < size; i++)
	{
		if (kkkkkk[i] == k)
		{
			used--;
			kkkkkk[i] = K();
			break;
		}
	}
}

template<class K, class V>
V & table<K, V>::operator[](K k)
{
	for (int i = 0; i < size; i++)
		if (kkkkkk[i] == k)
			return vvvvvv[i];

		throw 1;

}


template<class K, class V>
table<K,V> & table<K, V>::operator=(table & vt)
{
	size = vt.size;
	kkkkkk = new K[size];
	vvvvvv = new V[size];
	used = vt.used;
	for (int i = 0; i < size; i++)
	{
		kkkkkk[i] = vt.kkkkkk[i];
		vvvvvv[i] = vt.vvvvvv[i];
	}

	return *this;
}

template<class K, class V>
void table<K, V>::resize(int newsized)
{
		if (newsized == size)
			return;
		if (newsized < used)
			throw 1;

		K* keys = new K[newsized];
		V* vals = new V[newsized];
		size_t insertindex = 0;
		for (int i = 0; i < size; i++)
		{
			if (kkkkkk[i] != K())
			{
				keys[insertindex] = kkkkkk[i];
				vals[insertindex] = vvvvvv[i];
				++insertindex;
			}
		}
		delete[]kkkkkk, vvvvvv;
		kkkkkk = keys;
		vvvvvv = vals;
		size = newsized;
}
