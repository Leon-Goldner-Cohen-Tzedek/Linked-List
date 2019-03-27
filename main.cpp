#include <iostream>
#include "LinkedList.h"
#include "LinkedStack.h"
using namespace std;

int main()
{

  LinkedStack<int> testStack;

  testStack.Push(1);
  testStack.Push(2);
  cout << testStack.Pop() << endl;
  cout << testStack.Pop() << endl;
  testStack.Peek();
  testStack.Pop();

}
