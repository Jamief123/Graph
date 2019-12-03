#pragma once
#include <stddef.h>
#include "iostream"
#include "pch.h"
using namespace std;


template <class ItemType>
struct NodeType;

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next;
};

template <class ItemType>
class QueType
{
public:
	QueType();
	~QueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	ItemType Dequeue();
	void Display();
private:
	NodeType<ItemType>* qFront;
	NodeType<ItemType>* qRear;

};


template <class ItemType>
QueType<ItemType>::QueType()
// Class constructor.
// Post:  qFront and qRear are set to NULL.
{
	qFront = NULL;
	qRear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType()
// Class destructor.
{
	MakeEmpty();
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
// Post: Queue is empty; all elements have been
// deallocated.
{
	NodeType<ItemType>* tempPtr;

	while (qFront != NULL)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = NULL;
}


template <class ItemType>
bool QueType<ItemType>::IsFull() const
// Returns true if there is no room for another
// ItemType on the free store;
// false otherwise.
{
	NodeType<ItemType>* ptr;
	ptr = new NodeType<ItemType>;
	if (ptr == NULL)
		return true;
	else
	{
		delete ptr;
		return false;
	}
}


template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
	return (qFront == NULL);
}


template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:Queue has been initialized and is not full
// Post: newItem is at rear of queue.
{
	NodeType<ItemType>* newNode;

	newNode = new NodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;
	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;
	qRear = newNode;
}


template <class ItemType>
ItemType QueType<ItemType>::Dequeue()
// Removes front item from the queue and returns
// it in item.
// Pre:  Queue has been initialized and is not
// empty.
// Post: Front element has been removed from
// queue.
//       item is a copy of removed element.
{
	ItemType item;
	NodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == NULL)
		qRear = NULL;
	return item;
	delete tempPtr;
}



template <class ItemType>
void QueType<ItemType>::Display()
{
	NodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	if (qFront == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		while (tempPtr != NULL)
		{

			cout << tempPtr->info << " ";
			tempPtr = tempPtr->next;
		}
	}
	delete tempPtr;
}

