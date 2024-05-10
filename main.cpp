//#define CHECK_FOR_MEMORY_LEAKS

#ifdef CHECK_FOR_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // #ifdef CHECK_FOR_MEMORY_LEAKS

#include <iostream>
#include "HashTableOA.h"
void PrintIsEmptyOA(const HashTableOA* hashTable)
{
	std::cout << "Hash table is" << (hashTable->IsEmpty() ? " " : " not ") << "empty.\n";
}

void PrintSearchOA(const HashTableOA* hashTable, int key)
{
	std::cout << "Search value for key " << key << ": ";

	std::string value = hashTable->Search(key);
	std::cout << (value == "" ? "<Search returned empty value>" : value) << '\n';
}

void PrintInsertOA(HashTableOA* hashTable, int key, const std::string& value)
{
	std::cout << "Insert(" << key << ", " << value << "): ";

	HashTableOA::InsertResult result = hashTable->Insert(key, value);
	switch (result)
	{
	case HashTableOA::InsertResult::WithCollision:
		std::cout << "with collision!\n";
		break;
	case HashTableOA::InsertResult::WithoutCollision:
		std::cout << "no collision.\n";
		break;
	case HashTableOA::InsertResult::Updated:
		std::cout << "value updated.\n";
		break;
	case HashTableOA::InsertResult::NoSlotAvailable:
		std::cout << "no slot available!\n";
		break;
	}
}

void PrintRemoveOA(HashTableOA* hashTable, int key)
{
	std::cout << "Remove(" << key << "): ";

	bool result = hashTable->Remove(key);
	std::cout << (result ? "removed!" : "key not found.") << '\n';
}


int main()
{
#ifdef CHECK_FOR_MEMORY_LEAKS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // #ifdef CHECK_FOR_MEMORY_LEAKS

	std::cout << "\n*** HASH TABLE (OPEN ADDRESSING - LINEAR PROBING) ***\n";

	HashTableOA hashTableOA(11);
	PrintIsEmptyOA(&hashTableOA);

	PrintInsertOA(&hashTableOA, 50078, "BANCO DE DADOS");
	PrintInsertOA(&hashTableOA, 50327, "ESTRUTURA DE DADOS I");
	PrintInsertOA(&hashTableOA, 50720, "MODELAGEM MATEMATICA I");
	PrintInsertOA(&hashTableOA, 50782, "ORGANIZACAO DE COMPUTADORES");
	PrintInsertOA(&hashTableOA, 50898, "PROJETO E ANALISE DE ALGORITMOS I");

	PrintInsertOA(&hashTableOA, 50013, "ALGORITMOS NUMERICOS");
	PrintInsertOA(&hashTableOA, 50329, "ESTRUTURA DE DADOS II");
	PrintInsertOA(&hashTableOA, 50721, "MODELAGEM MATEMATICA II");
	PrintInsertOA(&hashTableOA, 50897, "PROJETO DE SOFTWARE");
	PrintInsertOA(&hashTableOA, 50899, "PROJETO E ANALISE DE ALGORITMOS II");
	PrintInsertOA(&hashTableOA, 51032, "SISTEMAS OPERACIONAIS");

	int key = 50329;
	PrintSearchOA(&hashTableOA, key);
	PrintRemoveOA(&hashTableOA, key);
	PrintSearchOA(&hashTableOA, key);
	PrintInsertOA(&hashTableOA, key, "ESTRUTURA DE DADOS II");
	PrintInsertOA(&hashTableOA, key, "Estrutura de Dados II");

	std::cout << hashTableOA.ToString();
}