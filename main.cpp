#include "graphs.h"

int main()
{
    ofstream fout;
    int opt;

    fout.open("possible_moves_chess.out");

    do{
        cout << "Select the piece you wish to move:\n1. Rook\n2. Knight\n3. Bishop\n4. Queen\n5. King\n6. Exit" << endl;
        cin >> opt; 

        switch(opt){
            case 1:
            {
                graph rook = graph_rook(8, 8);
                fout << "The rook ";
                chess_graph_write(rook, 8, 8, fout);
                break;
            }
            case 2:
            {
                graph knight = graph_knight(8, 8);
                fout << "The knight ";
                chess_graph_write(knight, 8, 8, fout);
                break;
            }
            case 3:
            {
                graph bishop = graph_bishop(8, 8);
                fout << "The bishop ";
                chess_graph_write(bishop, 8, 8, fout);
                break;
            }
            case 4:
            {
                graph queen = graph_queen(8, 8);
                fout << "The queen ";
                chess_graph_write(queen, 8, 8, fout);
                break;
            }
            case 5:
            {
                graph king = graph_king(8, 8);
                fout << "The king ";
                chess_graph_write(king, 8, 8, fout);
            }
        }

    }while(opt!=6);
    
    fout.close();
}
