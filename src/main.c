#include "boardviz.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    InitBoard();
    system("clear");
    PrintBoard();
/*    while (MakeMove()) 
	{
        PrintBoard(0);
        fprintf(outfile,"\n\n");
    }*/
    
    
    printf("\n");
    return 0;
}
