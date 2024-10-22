//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 12-2

/** ADT sorted list: Link-based implementation.
@file LinkedSortedList.h */

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include <iostream>
#include <cassert>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain
	int itemCount;           // Current count of list items

							 // Locates the node that is before the node that should or does
							 // contain the given entry.
							 // @param anEntry  The entry to find.
							 // @return  Either a pointer to the node before the node that contains
							 //    or should contain the given entry, or nullptr if no prior node exists.
	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const
	{
		Node<ItemType>* curPtr = headPtr;
		Node<ItemType>* prevPtr = nullptr;

		while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
		{
			prevPtr = curPtr;
			curPtr = curPtr->getNext();
		} // end while

		return prevPtr;
	} // end getNodeBefore

	// Locates the node at a given position within the chain.
	Node<ItemType>* getNodeAt(int position) const
	{
		assert(position >= 1 && position <= itemCount);
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();
		return curPtr;
	}

	// Returns a pointer to a copy of the chain to which origChainPtr points.
	Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr)
	{
		Node<ItemType>* copiedChainPtr;
		if (origChainPtr == nullptr)
		{
			copiedChainPtr = nullptr;
		}
		else
		{
			// Build new chain from given one
			copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
			copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
		}  // end if

		return copiedChainPtr;
	}  // end copyChain

public:
	LinkedSortedList() : headPtr(nullptr), itemCount(0) {}
	LinkedSortedList(const LinkedSortedList<ItemType>& aList) { headPtr = copyChain(aList.headPtr); }
	virtual ~LinkedSortedList() { clear(); }

	void insertSorted(const ItemType& newEntry)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		Node<ItemType>* prevPtr = getNodeBefore(newEntry);

		if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else // Add after node before
		{
			Node<ItemType>* aftPtr = prevPtr->getNext();
			newNodePtr->setNext(aftPtr);
			prevPtr->setNext(newNodePtr);
		} // end if

		itemCount++;
	} // end insertSorted

	bool removeSorted(const ItemType& anEntry)
	{
		if (itemCount == 0)
			return false;
		else if (itemCount == 1)
		{
			return remove(1);
		}
		else
		{
			for (int i = 1; i <= itemCount; i++)
			{
				if (getEntry(i) == anEntry)
					return remove(i);
			}
			return false;
		}
	} // end removeSorted

	int getPosition(const ItemType& newEntry) const throw(PrecondViolatedExcep)
	{
		{
			if (itemCount == 0)
				throw(PrecondViolatedExcep("getPosition(const ItemType& anEntry) called with empty list or invalid position."));
			else
			{
				for (int i = 1; i <= itemCount; i++)
				{
					if (getEntry(i) == anEntry)
						return i;
				}
			}
			throw(PrecondViolatedExcep("getPosition(const ItemType& anEntry): anEntry not in list. "));
		}
	}

	// The following methods are the same as given in ListInterface:
	bool isEmpty() const { return itemCount == 0; }
	int getLength() const { return itemCount; }
	bool remove(int position)
	{
		bool ableToRemove = position >= 1 && position <= itemCount;
		if (ableToRemove)
		{
			Node<ItemType>* curPtr = nullptr;
			if (position == 1)
			{
				curPtr = headPtr;
				headPtr = headPtr->getNext();
			}
			else
			{
				Node<ItemType>* prevPtr = getNodeAt(position - 1);
				curPtr = prevPtr->getNext();
				prevPtr->setNext(curPtr->getNext());
			}
			curPtr->setNext(nullptr);
			delete curPtr;
			curPtr = nullptr;
			itemCount--;
		}
		return ableToRemove;
	}
	void clear()
	{
		while (!isEmpty())
			remove(1);
	}
	ItemType getEntry(int position) const throw(PrecondViolatedExcep)
	{
		if (position >= 1 && position <= itemCount)
			return getNodeAt(position)->getItem();
		else
			throw(PrecondViolatedExcep("getEntry() called with empty list or invalid position."));
	}
}; // end LinkedSortedList

//#include "LinkedSortedList.cpp"
#endif