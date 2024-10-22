////  Created by Frank M. Carrano and Tim Henry.
////  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//
//// PARITALLY COMPLETE.
//
//
///** Implementation file for the class LinkedSortedList.
//@file LinkedSortedList.cpp */
//
//#include "LinkedSortedList.h"  // Header file
//#include <cassert>
//
//template<class ItemType>
//LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
//{
//	headPtr = copyChain(aList.headPtr);
//}  // end copy constructor
//
//template<class ItemType>
//void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
//{
//	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
//	Node<ItemType>* prevPtr = getNodeBefore(newEntry);
//
//	if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
//	{
//		newNodePtr->setNext(headPtr);
//		headPtr = newNodePtr;
//	}
//	else // Add after node before
//	{
//		Node<ItemType>* aftPtr = prevPtr->getNext();
//		newNodePtr->setNext(aftPtr);
//		prevPtr->setNext(newNodePtr);
//	} // end if
//
//	itemCount++;
//} // end insertSorted
//
//template<class ItemType>
//bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
//{
//	if (itemCount == 0)
//		return false;
//	else if (itemCount == 1)
//	{
//		return remove(1);
//	}
//	else
//	{
//		for (int i = 1; i <= itemCount; i++)
//		{
//			if (getEntry(i) == anEntry)
//				return remove(i);
//		}
//		return false;
//	}
//} // end remove
//
//  // Private Methods:
//
//template<class ItemType>
//Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
//{
//	Node<ItemType>* copiedChainPtr;
//	if (origChainPtr == nullptr)
//	{
//		copiedChainPtr = nullptr;
//	}
//	else
//	{
//		// Build new chain from given one
//		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
//		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
//	}  // end if
//
//	return copiedChainPtr;
//}  // end copyChain
//
//template<class ItemType>
//Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
//{
//	Node<ItemType>* curPtr = headPtr;
//	Node<ItemType>* prevPtr = nullptr;
//
//	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
//	{
//		prevPtr = curPtr;
//		curPtr = curPtr->getNext();
//	} // end while
//
//	return prevPtr;
//} // end getNodeBefore
//
