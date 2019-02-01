#include <iostream>
using namespace std;

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
    else if (this->next == NULL)
    {
      this->next = new Node<X>(input);
    }
    else
    {
      this->next->Add(input);
    }
  }

  void Insert(X data, int position)
  {
    if (this->data == NULL)
    {
      this->Add(data);
    }

    Node<X>* insert = new Node<X>(data);
    Node<X>* temp = new Node<X>;

    for (int i = 0; i < position; i++)
    {
      insert->next = temp->next;
      temp->next = insert;
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

  Node()
  {
    this->data = NULL;
    this->next = NULL;
  }

  Node(X input)
  {
    this->data = new X(input);
    this->next = NULL;
  }
};
