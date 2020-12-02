#include "graph.h"

// King graph 
graph graph_king(index n, index m) // The king can only move forward one step but in any direction
{
    graph Kg(n*m); 
    for(index i=0; i<n; i++)
        for(index j=0; j<m; j++){
            vertex v = i*m+i; 
            if(j<m-1){
                Kg[v].push_back(v+1); 
                Kg[v+1].push_back(v);
            } 

            if(i<n-1){
                Kg[v].push_back(v+m);
                Kg[v+m].push_back(v);
                if(j<m-1){ 
                    Kg[v].push_back(v+m+1);
                    Kg[v+m+1].push_back(v);
                } 
                if(j>0){
                    Kg[v].push_back(v+m-1);
                    Kg[v+m-1].push_back(v);
                }
            } 
        }
        return Kg;
}

// Rook graph
graph graph_rook(index n, index m) // The rook moves in a straight line
{
    graph Rk(n*m);
    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v = i*m+j; 
            for(index k=1; i+k<n; k++){ 
                Rk[v].push_back(v+k*m);
                Rk[v+k*m].push_back(v);
            }
            for(index k=1; j+k<m; k++){ 
                Rk[v].push_back(v+k);
                Rk[v+k].push_back(v);
            }
               
        }
    }

    return Rk;
}

// Bishop graph
graph graph_bishop(index n, index m) // The bishop moves diagonally
{
    graph Bp(n*m);
    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++){
            vertex v=i*m+j; 
            for(index k=1; i+k<n && j+k<m; k++){
                Bp[v].push_back(v+k*m+k);
                Bp[v+k*m+k].push_back(v);
            }
            for(index k=1; i+k<n && j>=k; k++){
                Bp[v].push_back(v+k*m-k);
                Bp[v+k*m-k].push_back(v);
            }
               
        }
    }

    return Bp;
}

// Knight graph
graph graph_knight(index n, index m) // The knight moves one step forward and another step across
{
    graph Kt(n*m);
    for(index i=0; i<n; i++){
        for(index j=0; j<m; j++) {
            vertex v = i*m+j;
            if(i<n-1 && j<m-2) {
                Kt[v].push_back(v+m+2);
                Kt[v+m+2].push_back(v);
            }
            if(i<n-1 && j>1){
                Kt[v].push_back(v+m-2);
                Kt[v+m-2].push_back(v);
            }
            if(i<n-2 && j<m-1) {
                Kt[v].push_back(v+2*m+1);
                Kt[v + 2*m + 1].push_back(v);
            }
            if(i<n-2 && j>0) {
                Kt[v].push_back(v+2*m-1);
                Kt[v+2*m-1].push_back(v);
            }
        }
    }

    return Kt;
}