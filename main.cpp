#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{

  int* pointer = new int(32);
  Node<int>* list = new Node<int>();

  for (int i = 0; i < 10; i++)
  {
    list->Add(i);
  }

  cout << *list << endl;

  list->Insert(33, 7);

  cout << *list << endl;

  return 0;
}
