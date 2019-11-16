#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct vertex {
    bool isColored;
    vector<int> possibleColors;
    int row;
    int column;
    int *quadrant = new int[2];
    int index;

    LinkedList *connectTo = new LinkedList();
};

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
        void insertElement(vertex *vertex);
        vertex *getElementByPosition(int position);
        int size();
        void printList();
};

#endif