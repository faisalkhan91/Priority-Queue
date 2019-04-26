#include <string>
#include <string.h>
#include <iostream>

using namespace std;

void swap(string& one, string& two);

struct NewHeapType
{
  void NewReheapDown(int root, int bottom);
  void NewReheapUp(int root, int bottom);
  void PrintHeap(int length);
  string *newelements;   // Array to be allocated dynamically
  int numnewElements;
};

void Swap(string& one, string& two)//swapping of newelements with references
{
  string temp;
  temp = one;
  one = two;
  two = temp;
}

void NewHeapType::NewReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;

  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (newelements[parent].length() < newelements[bottom].length())
    {
      Swap(newelements[parent], newelements[bottom]);
      NewReheapUp(root, parent);
    }
  }
}

void NewHeapType::NewReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (newelements[leftChild].length() <= newelements[rightChild].length())
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (newelements[root].length()< newelements[maxChild].length())
    {
      Swap(newelements[root], newelements[maxChild]);
      NewReheapDown(maxChild, bottom);
    }
  }
}
