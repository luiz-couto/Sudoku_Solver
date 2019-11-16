#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;

int main() {
    Graph sudoku = Graph(4,2,2);
    sudoku.addVertex(false,0,0);
    sudoku.addVertex(true,1,4);
    sudoku.addVertex(false,2,0);
    sudoku.addVertex(true,3,1);
    sudoku.addVertex(true,4,3);
    sudoku.addVertex(false,5,0);
    sudoku.addVertex(false,6,0);
    sudoku.addVertex(false,7,0);
    sudoku.addVertex(false,8,0);
    sudoku.addVertex(false,9,0);
    sudoku.addVertex(false,10,0);
    sudoku.addVertex(true,11,4);
    sudoku.addVertex(false,8,0);
    sudoku.addVertex(false,9,0);
    sudoku.addVertex(false,10,0);
    sudoku.addVertex(false,11,0);

    sudoku.print_graph();
    cout << endl;
}