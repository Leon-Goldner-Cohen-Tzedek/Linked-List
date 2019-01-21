#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{

  int* pointer = new int(32);
  LinkedList<int>* list = new LinkedList<int>();

  for (int i = 0; i < 10; i++)
  {
    list->Add(i);
  }

  cout << *list << endl;

  return 0;
}
