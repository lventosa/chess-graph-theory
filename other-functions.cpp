#include "graphs.h"

void chess_graph_write(graph& G, index n1, index n2, ofstream& fout)
{

	vertex vn = G.size();

    edge en = 0; 
    for(vertex v=0; v<vn; v++){ 
        en += G[v].size();
    }  
    en /= 2;
     
    fout << "This -piece- has a total of " << en << " possible final destinations " << endl; // substituir piece pel nom en angles
    fout << "\nWhere can it get to?" << endl;

    for(vertex v=0; v<vn; v++){
		fout << "(" << v/n2 << "," << v%n2 << ")" << "\t:";
        for(index i=0; i<G[v].size(); i++) 
            fout << "\t" << "(" << G[v][i]/n2 << "," << G[v][i]%n2 << ")"; 
        fout << endl;
    }
}