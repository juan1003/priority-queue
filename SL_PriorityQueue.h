//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT priority queue: ADT sorted list implementation.
Listing 14-6.
@file SL_PriorityQueue.h */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
	LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
										   // items in the priority queue

public:
	SL_PriorityQueue() { slistPtr = new SortedList<ItemType>(); }
	SL_PriorityQueue(const SL_PriorityQueue& pq) { slistPtr = new SortedList<ItemType>(*pq.slistPtr); }
	~SL_PriorityQueue() { delete slistPtr->isEmpty(); }

	bool isEmpty() { return slistPtr->isEmpty(); }
	bool add(const ItemType& newEntry)
	{
		slistPtr->insertSorted(newEntry);
		return true;
	}  // end add
	bool remove()
	{
		// The highest priority item is at the end of the sorted list
		return slistPtr->remove(slistPtr->getLength());
	}  // end remove

/** @throw PrecondViolatedExcep if priority queue is empty. */
	ItemType peek() const throw(PrecondViolatedExcep)
	{
		if (slistPtr->isEmpty())
			throw(PrecondViolatedExcep("peek() called with empty list."));
		return slistPtr->getEntry(1); 	// highest priority is at beginning of list
	}
}; // end SL_PriorityQueue

//#include "SL_PriorityQueue.cpp"
#endif
