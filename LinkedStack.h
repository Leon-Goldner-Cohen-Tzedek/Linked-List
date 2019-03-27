#include <iostream>
#include "LinkedList.h"

using namespace std;

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H


class LinkedStackException: public exception {}; // I AM NOT SURE WHERE TO ADD THESE

class StackUnderflow: public LinkedStackException {} StackUnderflow;

template <class X>
class LinkedStack
{
private:
  int head;
  Node<X>* stack;
public:

  void Push(X value)
  {
    if (this->stack == NULL)
    {
      this->stack = new Node<X>(value);
    }
    else
    {
      this->stack->Add(value);
      head++;
    }
  }

  X Pop()
  {
    try
    {
      if (this->head < 0) throw StackUnderflow;

      X temp = this->stack->Data();
      this->stack->Remove();
      head--;
      return temp;
    }
    catch (LinkedStackException e) {cout << "StackUnderflow" << endl;}
  }

  X Peek()
  {
    try
    {
      if (this->head < 0) throw StackUnderflow;

      return this->stack->Data();
    }
    catch (LinkedStackException e) {cout << "StackUnderflow" << endl;}
  }

  LinkedStack()
  {
    this->stack = NULL;
    this->head = 0;
  }

};



#endif
