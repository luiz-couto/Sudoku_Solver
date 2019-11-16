#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2)
        return 0;
    
    int sudokuSize, quadrantRowSize, quadrantColumnSize;
    string line;
    ifstream file(argv[1]);
    if (file.is_open()) {
    file >> sudokuSize >> quadrantColumnSize >> quadrantRowSize;
    
    Graph sudoku = Graph(sudokuSize,quadrantRowSize,quadrantColumnSize);
    char vertexColor;

    for (int i=0; i<sudokuSize*sudokuSize; i++) {
        file >> vertexColor;
        sudoku.addVertex(i,(int)vertexColor);
    }

    sudoku.print_graph();

    }
}