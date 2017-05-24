#pragma once
#include <vector>
#include <cstdio>
#include <memory>


const int LEN = 13;
//哈希函数使用除留余数法 冲突解决使用链地址法构造哈希表

//哈希节点


struct hash_node
{
	int data;
	hash_node* next;
	hash_node(int e, hash_node* _next = nullptr) : data(e), next(_next){}
	~hash_node( ) = default;
};


class hashTable
{
private:
	std::shared_ptr< std::vector<hash_node*> > table;
public:
	hashTable(int len = LEN) : table(new std::vector<hash_node*>(len))
	{
		for(auto i : *table )
		{
			i = nullptr;
		}
	}

	//为使简单， 先将拷贝构造等函数禁止
	hashTable(const hashTable&) = delete;
	hashTable& operator= (const hashTable&) = delete;

	~hashTable()
	{
		for(auto i : *table )
		{
			auto p = i;
			hash_node* pp = nullptr;
			if (p != nullptr )
				 pp = p->next;
			while (pp != nullptr)
			{
				delete p;
				p = pp;
				pp = pp->next;
			}
			delete p;
		}
	}

private:
	static int hash(int num);

	//冲突处理
	void collision(size_t posi, hash_node* new_node);

public:
	void print_hash( ) const;
	void insert(const int elem);
	bool remove(const int elem);
};

inline int hashTable::hash(int num)
{
	return num % LEN;
}

inline void hashTable::collision(size_t posi, hash_node* new_node)
{
	auto p = (*table)[posi];
	if (p == nullptr)
	{
		(*table)[posi] = new_node;
		return;
	}
	while (p->next != nullptr)
	{
		p = p->next;
	}

	p->next = new_node;
}

inline void hashTable::print_hash() const
{
	int line = 0;
	for(auto i = table->begin(); i != table->end(); ++i )
	{
		printf("table[%d]: ", line++);
		if ( *i == nullptr )
			printf("null\n");
		else
		{
			hash_node* p = *i;
			while (p != nullptr)
			{
				printf("%d ", p->data);
				p = p->next;
			}
			printf("\n");
		}
	}
}

inline void hashTable::insert(const int elem)
{
	int posi = hashTable::hash(elem);
	auto new_node = new hash_node(elem);
	collision(posi, new_node);
}

inline bool hashTable::remove(const int elem)
{
	int posi = hashTable::hash(elem);
	auto temp = (*table)[posi];
	if (temp->data == elem )
	{
		delete temp;
		(*table)[posi] = nullptr;
	}
	else
	{
		while((temp->next != nullptr) && (temp->next->data != elem) )
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			return false;
		}
		auto p = temp->next;
		temp->next = p->next;
		delete p;
		p = nullptr;
	}
	return true;
}

