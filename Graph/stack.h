#pragma once
#include <stddef.h>
#include "iostream"
#include "pch.h"
using namespace std;



template <class ItemType>
struct StackNodeType;

template<class ItemType>
class StackType
{
public:
	StackType();
	~StackType();
	void MakeEmpty();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ItemType item);
	ItemType Pop();
private:
	StackNodeType<ItemType>* topPtr;
};

template <class ItemType>
struct StackNodeType
{
	ItemType info;
	StackNodeType<ItemType>* next;
};

template<class ItemType>
StackType<ItemType>::StackType()
{
	topPtr = NULL;
}
template <class ItemType>
StackType<ItemType>::~StackType()
{
	StackNodeType<ItemType>* tempPtr;
	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<class ItemType>
ItemType StackType<ItemType>::Pop()
{
	StackNodeType<ItemType>* tempPtr;
	ItemType item = topPtr->info;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
	return item;
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
	StackNodeType<ItemType>* location;
	location = new StackNodeType<ItemType>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	StackNodeType<ItemType>* ptr;
	ptr = new StackNodeType<ItemType>;
	if (ptr == NULL)
		return true;
	else
	{
		delete ptr;
		return false;
	}
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	return (topPtr == NULL);
}

template <class ItemType>
void StackType<ItemType>::MakeEmpty()
{
	StackNodeType<ItemType>* tempPtr;

	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}
