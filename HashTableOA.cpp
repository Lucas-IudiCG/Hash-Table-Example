#include "HashTableOA.h"

HashTableOA::HashTableOA()
	: HashTableOA(DEFAULT_SIZE)
{
}

HashTableOA::HashTableOA(int size)
	: m_Size(size)
	, m_Count(0)
{
	m_Elements = new HashElement*[m_Size];
	for (int i = 0; i < m_Size; ++i)
		m_Elements[i] = nullptr;
}

HashTableOA::~HashTableOA()
{
	for (int i = 0; i < m_Size; ++i)
	{
		delete m_Elements[i];
		m_Elements[i] = nullptr;
	}
	delete[] m_Elements;
}

std::string HashTableOA::Search(int key) const
{
	int hashKey = HashFunction(key);
	int originalHashKey = hashKey;

	while (m_Elements[hashKey])
	{
		// Key found, return value.
		if (m_Elements[hashKey]->key == key)
			return m_Elements[hashKey]->value;

		// Keep searching for the key using linear probing.
		hashKey = (hashKey + 1) % m_Size;

		// Make sure we don't enter into an infinite loop.
		if (hashKey == originalHashKey)
			break;
	}

	return "";
}

HashTableOA::InsertResult HashTableOA::Insert(int key, const std::string& value)
{
	//if (m_Count >= m_Size)
	//	return InsertResult::NoSlotAvailable;

	int hashKey = HashFunction(key);
	int originalHashKey = hashKey;
	InsertResult result = m_Elements[hashKey] == nullptr ? InsertResult::WithoutCollision : InsertResult::WithCollision;

	while (m_Elements[hashKey])
	{
		if (m_Elements[hashKey]->key == key)
		{
			m_Elements[hashKey]->value = value;
			return InsertResult::Updated;
		}

		// Keep searching for a free slot using linear probing (circular array).
		hashKey = (hashKey + 1) % m_Size;

		// Make sure we don't enter into an infinite loop.
		if (hashKey == originalHashKey)
			break;
	}

	if (m_Count >= m_Size)
		return InsertResult::NoSlotAvailable;

	if (m_Elements[hashKey] == nullptr)
	{
		++m_Count;
		m_Elements[hashKey] = new HashElement(key, value);
	}

	return result;
}

bool HashTableOA::Remove(int key)
{
	int hashKey = HashFunction(key);
	int originalHashKey = hashKey;

	while (m_Elements[hashKey])
	{
		if (m_Elements[hashKey]->key == key)
		{
			--m_Count;
			delete m_Elements[hashKey];
			m_Elements[hashKey] = nullptr;

			return true;
		}

		// Keep searching for the key using linear probing.
		hashKey = (hashKey + 1) % m_Size;

		// Make sure we don't enter into an infinite loop.
		if (hashKey == originalHashKey)
			break;
	}

	return false;
}

bool HashTableOA::IsEmpty() const
{
	return m_Count == 0;
}

std::string HashTableOA::ToString() const
{
	std::ostringstream oss;

	for (int i = 0; i < m_Size; ++i)
		oss << "[" << i << "] " << (m_Elements[i] ? m_Elements[i]->ToString() : "<empty>") << '\n';

	return oss.str();
}

int HashTableOA::HashFunction(int key) const
{
	int index =key % m_Size;
	if(m_Elements[index]==NULL){
	    return index;
	}
	else{
	    return HashIncr(index);
	}
}

int HashTableOA::HashIncr(int index) const{
    
    
}
int HashTableOA::Rehash(int index) const{
  }