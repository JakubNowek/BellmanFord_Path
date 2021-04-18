#ifndef bellmanford_hpp
#define bellmanford_hpp
#include <fstream>
#include "graph_list.hpp"
#include "graph_matrix.hpp"
#define INFINITY 99999

void SaveArrayFile(int distanceArray[],int preArray[], int size, int vertexSource);
void bellmanfordList(GraphList &graph, int vertexSource);
void bellmanfordListFile(GraphList &graph, int vertexSource);
void bellmanfordMatrix(GraphMatrix &graph,int vertexSource);
void bellmanfordMatrixFile(GraphMatrix &graph, int vertexSource);


#endif