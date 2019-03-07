#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{


  Node<int>* list = new Node<int>();

  for (int i = 0; i < 10; i++)
  {
    list->Add(i);
  }

  cout << *list << endl;

  int a = list->Size();
  cout << a << endl;

  return 0;
}
