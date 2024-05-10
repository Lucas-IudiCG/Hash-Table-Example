#ifndef __HASH_TABLE_OPEN_ADDRESSING_H__
#define __HASH_TABLE_OPEN_ADDRESSING_H__

#include <string>
#include "HashElement.h"

class HashTableOA
{
public:
	enum class InsertResult
	{
		WithCollision,
		WithoutCollision,
		Updated,
		NoSlotAvailable,
	};

	HashTableOA();
	HashTableOA(int size);
	~HashTableOA();

	std::string Search(int key) const;
	InsertResult Insert(int key, const std::string& value);
	bool Remove(int key);

	bool IsEmpty() const;

	std::string ToString() const;

private:
	static const int DEFAULT_SIZE = 31;

	int m_Size;
	int m_Count;
	HashElement **m_Elements;

	int HashFunction(int key) const;
	int RehasingQuadraticProbing(int index) const;
};

#endif