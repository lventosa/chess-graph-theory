#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned int vertex;
typedef unsigned int edge;
typedef unsigned int index; 

typedef vector<vector<vertex> > graph;

graph graph_king(index n, index m);
graph graph_queen(index n, index m);
graph graph_rook(index n, index m);
graph graph_bishop(index n, index m);
graph graph_knight(index n, index m);
void chess_graph_write(graph& G, index n1, index n2, ofstream& fout);
