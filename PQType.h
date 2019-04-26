// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};

#include <string>
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

#include "Heap.h"
#include "NewHeap.h"
#include "BinarySearchTree.h"
#include "LinkedList.h"

template<class ItemType>
class PQType
{
public:
  PQType(int);          // parameterized class constructor
  ~PQType();            // class destructor

  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.

  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)

  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)

  void Enqueue(ItemType newItem, char dataStructure);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.

  void Dequeue(ItemType& item, char dataStructure);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.

  int GetLength();
  void PrintQueue(char dataStructure);
  void PQPrint();
  void PQPrintArray();

private:
  int length;
  HeapType<ItemType> items;
  NewHeapType heap;
  LinkedList<ItemType> llist;
  BinarySearchTree<ItemType> binary;
  int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    heap.newelements = new string[max];
    length = 0;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    llist.MakeEmptyList();
    binary.MakeEmpty();
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item, char dataStructure)
// Post: element with highest priority has been removed
//       from the queue; a copy is returned in item.
{
    if (length == 0)
        throw EmptyPQ();
    else if (dataStructure == 'a')
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
        cout << item << " is dequeued." << endl;
    }
    else if (dataStructure == 'b')
    {
        llist.RemoveNode();
        length--;
    }
    else if (dataStructure == 'c')
    {
        length--;
        cout << binary.DequeueTree() << endl;
    }
    else
    {
    item = items.elements[0];
    items.elements[0] = items.elements[length-1];
    length--;
    items.ReheapDown(0, length-1);
    }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem, char dataStructure)
// Post: newItem is in the queue.
{
    if (length == maxItems)
        throw FullPQ();
    else if (dataStructure == 'a')
    {
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0, length-1);
    }
    else if(dataStructure == 'b')
    {
        length++;
        llist.InsertNode(newItem);
    }
    else if (dataStructure == 'c')
    {
        length++;
        binary.InsertNode(newItem);
    }
    else{
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0, length-1);
    }
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

template<class ItemType>
int PQType<ItemType>::GetLength()
{
    return length;
}

template<class ItemType>
void PQType<ItemType>::PrintQueue(char dataStructure)
{
    if (dataStructure == 'a')
    {
        int i = 0;
        while(i<length)
        {
            cout << i << ". " << items.elements[i] << endl;
            i++;
        }
    }
    else if (dataStructure == 'b')
    {
        llist.PrintList();
    }
    else if (dataStructure == 'c')
    {
        binary.Print();
    }
    else
    {
        int i = 0;
        while(i<length)
        {
            cout << i << ". " << heap.newelements[i] << endl;
            i++;
        }
    }
}

template<class ItemType>
void PQType<ItemType>::PQPrint()
// Prints the current queue
{
  int i = 0;
  ItemType array[length];
  cout << "\nThe PQ using heaps is: \n\n";
  while(true){
	  this->Dequeue(array[i], 'd');
	  cout <<array[i] << " ";
	  i++;
	  if(length == 0) break;
  }
  i--;
  while(i >= 0) {
	  Enqueue(array[i--], 'd');
  }
}

template<class ItemType>
void PQType<ItemType>::PQPrintArray(){
	int i = 0;
	cout << "\nArray PQ is: \n\n";
	while(i < length) {
		cout << items.elements[i] << " ";
		i++;
	}
}
