#include <iostream>
using namespace std;

#ifndef LINKEDLIST_H
#define  LINKEDLIST_H

class ListException : public exception {}; // I AM NOT SURE WHERE TO ADD THESE

class ListAllocationException : public ListException {} AllocationException;

template <class X>
class Node
{
private:
  X* data;
  Node<X>* next;

public:

  void Add(X input)
  {
    if (this->data == NULL)
    {
      this->data = new X(input);
    }
    else
    {
      Node<X>* added = new Node<X>(*(this->data), this->next);
      *(this->data) = input;
      this->next = added;
    }
  }

  void Insert(X data, int position)
  {
    if (position == 0)
    {
      this->Add(data);
    }
    else
    {
      if (this->next == NULL)
      {
        this->next = new Node<X>(data);
      }
      else
      {
        this->next->Insert(data, position - 1);
      }
    }
  }

  void Remove()
  {
    delete this->data;

    if (this->next == NULL)
    {
      this->data = NULL;
    }
    else
    {
      this->data = this->next->data;
      this->next = this->next->next;
    }
  }

  void Remove(int position)
  {
     if (position == 0)
     {
       Remove();
     }
     else
     {
       this->next->Remove(position - 1);
     }
  }

  bool Contains(X key)
  {
    if (this->next == NULL)
    {
      return false;
    }
    else if (*(this->data) == key)
    {
      return true;
    }
    else
    {
      this->next->Contains(key);
    }
  }

  int Size(int size = 1)
  {
    if (this->End())
    {
      return size;
    }
    else
    {
      this->next->Size(size + 1);
    }
  }

  X Data()
  {
    return *(this->data);
  }

  bool Empty()
  {
    return this->data == NULL;
  }

  bool End()
  {
    return this->next == NULL;
  }

  friend ostream& operator<<(ostream& stream, Node& list)
  {
    if (list.Empty())
    {
      return stream;
    }
    else if (list.End())
    {
      stream << list.Data() << " ";
      return stream;
    }
    else
    {
      stream << list.Data() << " ";
      stream << *(list.next);
    }
    return stream;
  }

  void operator=(Node& a)
  {
    if (this->next == NULL)
    {
      return;
    }
    else
    {
      a->next->data = this->next->data;
    }
  }

  Node()
  {
    this->data = NULL;
    this->next = NULL;
  }

  Node(X input)
  {
    try
    {
      this->data = new X(input);
      this->next = NULL;
    }
    catch (ListAllocationException e){cout << "ListAllocationException" << endl;}
    
  }

  Node(X input, Node* next)
  {
    try
    {
      this->data = new X(input);
    }
    catch (ListAllocationException e){cout << "ListAllocationException" << endl;}

    this->next = next; //I do not know how to test for this so I won't do error handling on this
  }

  // ~Node() HELP ME GRANT
  // {
  //   if (this == NULL)
  //   {
  //     return;
  //   }
  //   else
  //   {
  //     delete this->data;
  //     this->
  //   }
  // }
};

#endif
