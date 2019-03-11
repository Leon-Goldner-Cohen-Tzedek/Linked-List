# Linked-List
[![Build Status](https://travis-ci.com/Leon-Goldner-Cohen-Tzedek/Linked-List.svg?branch=master)](https://travis-ci.com/Leon-Goldner-Cohen-Tzedek/Linked-List)

A linked list for C++

Example code and what it does:


Node<int>* list = new Node<int>(); //creates a new empty node that holds ints

list->Add(x); //adds x to the start of the list

list->Insert(data, position); //adds data to of the right type to the position in the node

list->Remove(position); //deletes the data in that position

bool y = list->Contains(value); //returns true if the value is in the list. Make sure to store it to a variable, it does weird things if you do not

list->Data(); //returns the data in the current node

list->Empty(); //returns NULL if the data does not exist

list->End(); //returns next as NULL if it does not exist, signifying the end of the list
