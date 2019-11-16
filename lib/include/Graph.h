#ifndef GRAPH_
#define GRAPH_

#include <iostream>
#include <sstream>

#include "LinkedList.h"

using namespace std;

class Graph {
    private:
        LinkedList *vertex_list;
        int size;
        int quadrantRowSize;
        int quadrantColumnSize;
    
    public:
        Graph(int size, int quadrantRowSize, int quadrantColumnSize);
        ~Graph();
        void addVertex(bool isColored, int position, int color);
        void addEdge(vertex *vertex1, vertex *vertex2);
        bool verifyIfIsTheSameQuadrant(vertex *vertex1, vertex *vertex2);
        void print_graph(); //debug
};

#endif