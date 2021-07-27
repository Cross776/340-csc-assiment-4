//	LinkedBag340.cpp
//	Created by: CSC340


#include <iostream>
#include <LinkedBag.h>

#include <ctime>
#include <cstdlib>
#include <cstddef>
using namespace std;

template<typename ItemType> // this is for B#1
  bool LinkedBag<ItemType>::removeSecondNode340() {
	  Node<ItemType>* temp = headPtr;	
	  temp = headPtr->getNext();		// next 
	return remove(temp->getItem());	} 

template<typename ItemType> // this is for B#2
  bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) { //new nodes
    Node<ItemType> *temp = headPtr;
    while (temp->getNext() != nullptr) { 
      temp = temp->getNext(); }
    Node<ItemType> *newNode = new Node<ItemType>();
    newNode->setItem(newEntry);
    temp->setNext(newNode);
    itemCount++;
  return true; }

template<typename ItemType> // this is for B#3
  int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count{0};
    Node<ItemType> *temp = headPtr;	
    while (temp != nullptr) {
      count ++;
      temp = temp->getNext(); }
    return count; }


// this is for B#6 which I will move to the end later
template<typename ItemType>
 ItemType LinkedBag<ItemType>::removeRandom340() {
  int random_num{};
	int size = getCurrentSize340Iterative();
  int min{ 1 };	
  int max = size;	
  ItemType item{};
  srand(time(nullptr));
    for (int i{ 1 }; i <= max; i++) {
		  random_num = rand() % max + min; }
    Node<ItemType>* temp1 = headPtr
    int position = random_num; 	// random number
      for (int i{ 0 }; i < (position - 2); i++) {
        temp1 = temp1->getNext(); }
        Node<ItemType>* temp2 = temp1->getNext();	// nth Node
		item = temp2->getItem();
		remove(item);
		return item; }

// this is for B#4
template<typename ItemType>
	int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
		Node<ItemType> *temp = headPtr;		
	return getCurrentSize340RecursiveHelper(temp); } 

template<typename ItemType> //helper
	int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* temp) const {
		int count{0};
	
		if (temp == nullptr) {	
		return count;
		} else {
		return 1 + getCurrentSize340RecursiveHelper(temp->getNext());	} }

//this is for B#5
