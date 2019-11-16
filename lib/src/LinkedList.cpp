#include "LinkedList.h"
#include <iostream>
#include <sstream>

using namespace std;

LinkedList::LinkedList() {
    this->start = nullptr;
    this->end = nullptr;
    this->number_of_elements = 0;
}

LinkedList::~LinkedList() {

}

void LinkedList::insertElement(vertex *vertex) {
    node *newNode = new node;
    newNode->_vertex = vertex;

    if(this->number_of_elements == 0) {
        newNode->prox = nullptr;
        this->start = newNode;
        this->end = newNode;
    } else {
        this->end->prox = newNode;
        newNode->prox = nullptr;
        this->end = newNode;
    }
    this->number_of_elements++;
}

int LinkedList::size() {
    return this->number_of_elements;
}

vertex *LinkedList::getElementByPosition(int position) {
    node *current = this->start;
    for (int i=0;i<position;i++){
        current = current->prox;
    }
    return current->_vertex;
}

void LinkedList::printList() {
    node *current = this->start;
    for (int i=0; i<this->number_of_elements; i++) {
        cout << current->_vertex->index << " -> ";
        current = current->prox;
    }
}