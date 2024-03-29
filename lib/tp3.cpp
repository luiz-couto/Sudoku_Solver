#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;

void runSudoku(Graph *sudoku, int sudokuSize) {
    
    int noChangesCounter = 0;
    bool removedColor;

    while(!sudoku->everyVertexHasColor()){

        for (int i=0; i<sudokuSize*sudokuSize; i++) {
            vertex *vertexI = sudoku->getVertex(i);
            if (vertexI->possibleColors.size() == 1) {
                for (int j=0; j<vertexI->connectTo->size(); j++) {
                    vertex *vertexJ = vertexI->connectTo->getElementByPosition(j);
                    if (vertexJ->possibleColors.size() >= 1) {
                        removedColor = sudoku->removeColor(vertexJ->index, vertexI->possibleColors[0]);
                        if (removedColor)
                            noChangesCounter = 0;
                    }
                }
            }
        }
        noChangesCounter++;
        if (noChangesCounter == 3) {
            break;
        }
    }
}

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

    // Add vertices to graph
    for (int i=0; i<sudokuSize*sudokuSize; i++) {
        file >> vertexColor;
        int vertexColorInt = vertexColor - '0';
        sudoku.addVertex(i,vertexColorInt);
    }

    // Add edges between vertices that can't be the same color
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

    runSudoku(&sudoku, sudokuSize);

    if (sudoku.everyVertexHasColor()){
        cout << "solução" << endl;
        sudoku.printSudoku();
        return 0;
    }
    
    vector<vector<int>> checkPoint = sudoku.createCheckpoint();
    bool foundSolution = false;

    for(int i=0; i<sudokuSize*sudokuSize; i++) {
        vertex *vertexI = sudoku.getVertex(i);
        if (vertexI->possibleColors.size() > 1) {
            for (int j=0; j<vertexI->possibleColors.size(); j++) {
                vector<int> colorChoice = {0};
                colorChoice[0] = vertexI->possibleColors[j];
                vertexI->possibleColors = colorChoice;
                runSudoku(&sudoku, sudokuSize);
                if (sudoku.everyVertexHasColor()){
                    foundSolution = true;
                    break;
                } else {
                    sudoku.returnToCheckpoint(checkPoint);
                }
            }
        }
        if(foundSolution) {
            break;
        }
    }

    if (sudoku.everyVertexHasColor()){
        cout << "solução" << endl;
        sudoku.printSudoku();
        return 0;
    }

    cout << "sem solução" << endl;
    sudoku.printSudoku();
    return 0;

    }
}