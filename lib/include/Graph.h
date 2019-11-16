#ifndef GRAPH_
#define GRAPH_

#include <iostream>
#include <sstream>

#include "LinkedList.h"

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

class Graph {
    private:
        LinkedList *vertex_list;
        int size;
        int quadrantRowSize;
        int quadrantColumnSize;
    
    public:
        Graph(int size, int quadrantRowSize, int quadrantColumnSize);
        ~Graph();
        vertex *getVertex(int position);
        void addVertex(int position, int color);
        void addEdge(int position1, int position2);
        bool verifyIfIsTheSameQuadrant(vertex *vertex1, vertex *vertex2);
        void print_graph(); //debug
};

#endif