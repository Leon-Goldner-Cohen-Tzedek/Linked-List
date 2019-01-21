#include <iostream>
using namespace std;

template <class X>
class LinkedList
{
private:
  X* data;
  LinkedList<X>* next;

public:

  void Add(X input)
  {
    if (this->data == NULL)
    {
      this->data = new X(input);
    }
    else if (this->next == NULL)
    {
      this->next = new LinkedList<X>(input);
    }
    else
    {
      this->next->Add(input);
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

  friend ostream& operator<<(ostream& stream, LinkedList& list)
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

  LinkedList()
  {
    this->data = NULL;
    this->next = NULL;
  }

  LinkedList(X input)
  {
    this->data = new X(input);
    this->next = NULL;
  }
};
