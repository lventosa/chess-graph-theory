#include "graphs.h"

int main()
{
    ofstream fout;
    int opt;

    fout.open("possible_moves_chess.out");

    do{
        cout << "Pick a piece:\n1. King\n2. Bishop\n3. Knight\n4. Rook\n5. Exit" << endl;
        cin >> opt; 

        switch(opt){
            case 1:
                graph king = graph_king(8, 8);
                fout << "The king " << chess_graph_write(king, 8, 8, fout) << endl;
                break;

            case 2:
                graph bishop = graph_bishop(8, 8);
                fout << "The bishop " << chess_graph_write(bishop, 8, 8, fout) << endl;
                break;

            case 3:
                graph knight = graph_knight(8, 8);
                fout << "The knight " << chess_graph_write(knight, 8, 8, fout) << endl;
                break;

            default:
                graph rook = graph_rook(8, 8);
                fout << "The rook " << chess_graph_write(rook, 8, 8, fout) << endl;
        }

    }while(opt!=5);
    
    fout.close();

}
