#include"HashTable.h"
#include<string>

const USH HASH_BITS = 15;
const USH HASH_SIZE = (1 << HASH_BITS);
const USH HASH_MASK = HASH_SIZE - 1;

HashTable::HashTable(size_t size)
	: _prev(new USH[size * 2])
	, _head(_prev + size)
	, _hashSize(size * 2)
{
	memset(_head, 0, sizeof(USH)*size);
}

HashTable::~HashTable()
{
	if (_prev)
	{
		delete[] _prev;
		_prev = _head = nullptr;
	}
}

void HashTable::HashFunc(USH& hashAddr, USH ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

USH HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

void HashTable::Insert(USH& hashAddr, USH ch, USH pos, USH& matchHead)
{
	HashFunc(hashAddr, ch);

	_prev[pos&HASH_MASK] = _head[hashAddr];
	matchHead = _head[hashAddr];
	_head[hashAddr] = pos;
}

USH HashTable::GetNext(USH matchPos)
{
	return _prev[matchPos];
}