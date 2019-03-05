#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{


  Node<int>* list = new Node<int>();
  Node<int>* list2 = new Node<int>();

  for (int i = 0; i < 10; i++)
  {
    list->Add(i);
  }

  cout << *list << endl;
  cout << *list2 << endl;

  list2 = list;
  bool a = list->Contains(3);
  bool b = list->Contains(100);
  cout << a << endl;
  cout << b << endl;
  cout << *list2 << endl;

  return 0;
}
