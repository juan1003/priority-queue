//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h
Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType        item; // A data item
	Node<ItemType>* next; // Pointer to next node

public:
	Node() : next(nullptr) {}
	Node(const ItemType& anItem) : item(anItem), next(nullptr) {}
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) {}
	void setItem(const ItemType& anItem) { item = anItem; }
	void setNext(Node<ItemType>* nextNodePtr) { next = nextNodePtr; }
	ItemType getItem() const { return item; }
	Node<ItemType>* getNext() const { return next; }
}; // end Node

//#include "Node.cpp"
#endif