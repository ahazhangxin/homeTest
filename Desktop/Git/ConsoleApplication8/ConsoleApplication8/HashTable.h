#pragma once
#include"Common.h"

class HashTable
{
public:
	HashTable(size_t size);

	~HashTable();

	void Insert(USH& hashAddr, USH ch, USH pos, USH& matchHead);
	void HashFunc(USH& hashAddr, USH ch);
	USH GetNext(USH matchPos);
private:
	
	USH H_SHIFT();
private:
	USH* _prev;
	USH* _head;
	size_t _hashSize;
};
