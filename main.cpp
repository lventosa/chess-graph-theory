#include "graphs.h"

int main()
{
    ofstream fout;
    int opt;

    fout.open("possible_moves_chess.out");

    do{
        cout << "Pick a piece:\n1. King\n2. Bishop\n3. Knight\n4. Rook\n5. Exit" << endl;
        scanf("%d", &opt); // comprovar que realment es faci aixi

        switch(opt){
            case 1:
                graph kg = graph_king(8, 8);
                chess_graph_write(kg, 8, 8, fout);
                break;

            case 2:
                graph bs = graph_bishop(8, 8);
                // comprovar si el color afecta. Si afecta, preguntar si juga a blanques o negres 
                chess_graph_write(bs, 8, 8, fout);
                break;

            case 3:
                graph kn = graph_knight(8, 8);
                chess_graph_write(kn, 8, 8, fout);
                break;

            default:
                graph rk = graph_rook(8, 8);
                chess_graph_write(rk, 8, 8, fout);
    }while(opt!=5);
    
    fout.close();

}
