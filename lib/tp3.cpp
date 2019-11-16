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
        int vertexColorInt = vertexColor - '0';
        sudoku.addVertex(i,vertexColorInt);
    }

    for (int i=0; i<sudokuSize*sudokuSize; i++) {
        vertex *vertexI = sudoku.getVertex(i);
        for (int j=0; j<sudokuSize*sudokuSize; j++) {
            if (i != j) {
                vertex *vertexJ = sudoku.getVertex(j);
                if (vertexI->row == vertexJ->row || vertexI->column == vertexJ->column || sudoku.verifyIfIsTheSameQuadrant(vertexI,vertexJ)) {
                    sudoku.addEdge(i,j);
                }
            }
        }
    }

    cout << endl << endl;
    sudoku.printSudoku();

    for (int i=0; i<sudokuSize*sudokuSize; i++) {
        vertex *vertexI = sudoku.getVertex(i);
        if (vertexI->possibleColors.size() == 1) {
            for (int j=0; j<vertexI->connectTo->size(); j++) {
                vertex *vertexJ = vertexI->connectTo->getElementByPosition(j);
                if (vertexJ->possibleColors.size() > 1) {
                    sudoku.removeColor(vertexJ->index, vertexI->possibleColors[0]);
                }
            }
        }
    }

    cout << endl << endl;
    sudoku.printSudoku();

    }
}