#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph(int size, int quadrantRowSize, int quadrantColumnSize) {
    this->quadrantRowSize = quadrantRowSize;
    this->quadrantColumnSize = quadrantColumnSize;
    this->size = size;
    this->vertex_list = new LinkedList();
}

Graph::~Graph() {

}

void Graph::addVertex(int position, int color) {
    vertex *newVertex = new vertex;
    newVertex->index = position;
    newVertex->column = position % this->size;
    newVertex->row = position / this->size;

    if(color != 0)
        newVertex->possibleColors.push_back(color);
    else
    {   
        for (int i=1; i<=this->size; i++){
            newVertex->possibleColors.push_back(i);
        }
    }
    
    newVertex->quadrant[0] = newVertex->row / this->quadrantRowSize;
    newVertex->quadrant[1] = newVertex->column / this->quadrantColumnSize;

    this->vertex_list->insertElement(newVertex);
}

bool Graph::verifyIfIsTheSameQuadrant(vertex *vertex1, vertex *vertex2) {
    if (vertex1->quadrant[0] == vertex2->quadrant[0] && vertex1->quadrant[1] == vertex2->quadrant[1])
        return true;
    else
        return false;
}

void Graph::addEdge(int position1, int position2) {
    vertex *vertex1 = this->getVertex(position1);
    vertex *vertex2 = this->getVertex(position2);
    vertex1->connectTo->insertElement(vertex2);
}

vertex *Graph::getVertex(int position) {
    return this->vertex_list->getElementByPosition(position);
}

void Graph::removeColor(int position, int color) {
    vertex *currentVertex = this->getVertex(position);
    int index = 0;
    for (int i=0; i<currentVertex->possibleColors.size; i++) {
        if (currentVertex->possibleColors[index] == color) {
            break;
        }
        index++;
    }
    currentVertex->possibleColors.erase(currentVertex->possibleColors.begin()+index);
}

void Graph::print_graph() {
    for (int i=0; i<this->size*this->size; i++) {
        cout << i << " | " ;
        this->vertex_list->getElementByPosition(i)->connectTo->printList();
        cout << endl;
    }
}