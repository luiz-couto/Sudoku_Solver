#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct vertex;

struct node {
    vertex *_vertex;
    node *prox;
};

class LinkedList  {
    private:
        node *start;
        node *end;
        int number_of_elements;

    public:
        LinkedList();
        ~LinkedList();
        void insertElement(vertex *_vertex);
        vertex *getElementByPosition(int position);
        int size();
        void printList();
};

#endif