#include "graphs.h"

// King graph 
graph graph_king(index n, index m) // The king can only move forward one step but in any direction
{
    graph king(n*m); 

    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v = i*m+j; 
            if(j<m-1){
                king[v].push_back(v+1); 
                king[v+1].push_back(v);
            } 

            if(i<n-1){
                king[v].push_back(v+m);
                king[v+m].push_back(v);
                if(j<m-1){ 
                    king[v].push_back(v+m+1);
                    king[v+m+1].push_back(v);
                } 
                if(j>0){
                    king[v].push_back(v+m-1);
                    king[v+m-1].push_back(v);
                }
            } 
        }
    }

        return king;
}

// Queen graph
graph graph_queen(index n, index m)
{
    graph queen(n*m);

    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v = i*m+j; 
            for(index k=1; i+k<n; k++){ 
                queen[v].push_back(v+k*m);
                queen[v+k*m].push_back(v);
            }
            for(index k=1; j+k<m; k++){ 
                queen[v].push_back(v+k);
                queen[v+k].push_back(v);
            }
            for(index k=1; i+k<n && j+k<m; k++){
                queen[v].push_back(v+k*m+k);
                queen[v+k*m+k].push_back(v);
            }
            for(index k=1; i+k<n && j>=k; k++){
                queen[v].push_back(v+k*m-k);
                queen[v+k*m-k].push_back(v);
            }
               
        }
    }

    return queen;
}

// Rook graph
graph graph_rook(index n, index m) // The rook moves in a straight line
{
    graph rook(n*m);

    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v = i*m+j; 
            for(index k=1; i+k<n; k++){ 
                rook[v].push_back(v+k*m);
                rook[v+k*m].push_back(v);
            }
            for(index k=1; j+k<m; k++){ 
                rook[v].push_back(v+k);
                rook[v+k].push_back(v);
            }
               
        }
    }

    return rook;
}

// Bishop graph
graph graph_bishop(index n, index m) // The bishop moves diagonally
{
    graph bishop(n*m);

    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v=i*m+j; 
            for(index k=1; i+k<n && j+k<m; k++){
                bishop[v].push_back(v+k*m+k);
                bishop[v+k*m+k].push_back(v);
            }
            for(index k=1; i+k<n && j>=k; k++){
                bishop[v].push_back(v+k*m-k);
                bishop[v+k*m-k].push_back(v);
            }
               
        }
    }

    return bishop;
}

// Knight graph
graph graph_knight(index n, index m) // The knight moves one step forward and another step across
{
    graph knight(n*m);
    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++) {
            vertex v = i*m+j;
            if(i<n-1 && j<m-2) {
                knight[v].push_back(v+m+2);
                knight[v+m+2].push_back(v);
            }
            if(i<n-1 && j>1){
                knight[v].push_back(v+m-2);
                knight[v+m-2].push_back(v);
            }
            if(i<n-2 && j<m-1) {
                knight[v].push_back(v+2*m+1);
                knight[v + 2*m + 1].push_back(v);
            }
            if(i<n-2 && j>0) {
                knight[v].push_back(v+2*m-1);
                knight[v+2*m-1].push_back(v);
            }
        }
    }

    return knight;
}

void chess_graph_write(graph& G, index n1, index n2, ofstream& fout)
{

	vertex vn = G.size();

    edge en = 0; 
    for(vertex v=0; v<vn; v++){ 
        en += G[v].size();
    }  
    en /= 2;
     
    fout << "has a total of " << en << " possible destinations given all possible starting points " << endl; 
    fout << "\nWhere can it get to?" << endl;

    for(vertex v=0; v<vn; v++){
		fout << "(" << v/n2 << "," << v%n2 << ")" << ":";
        for(index i=0; i<G[v].size(); i++) 
            fout << " " << "(" << G[v][i]/n2 << "," << G[v][i]%n2 << ")"; 
        fout << endl;
    }

    fout << endl;
}