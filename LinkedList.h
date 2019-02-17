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

    Node<X>* insert = new Node<X>;
    Node<X>* current = new Node<X>;
    Node<X>* next = new Node<X>;
    Node<X>* previous = new Node<X>;

    insert->Add(data);// can just instantiate insert with data, but this is nicer to look at . . .

    previous = this->next;

    for (int i = 0; i < position; i++)
    {
      current = previous->next;
      previous = current;
      current->next = next;

    }
    previous->next = insert;
    insert->next = next;
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
