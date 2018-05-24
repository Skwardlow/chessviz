#include "boardviz.h"
#include <stdlib.h>
#include <stdio.h>

const int kBoardWidth = 8;
const int kBoardHeight = 8;

char** board;

void InitBoard(){
    int i,j;
    board = (char**)malloc(kBoardHeight * sizeof(char*));
    for (i = 0; i < kBoardHeight; i++) {
        board[i] = (char*)malloc(kBoardWidth * sizeof(char));
        for (j = 0; j < kBoardWidth; j++) {
            board[i][j] = ' ';
        }
    }
    FillBoard();
}

void FillBoard(){
    int i;
    for (i = 0; i < kBoardWidth; i++){
        board[i][1] = 'P';
        board[i][6] = 'p';
    }
    board[0][0] = 'R';
    board[1][0] = 'N';
    board[2][0] = 'B';
    board[3][0] = 'Q';
    board[4][0] = 'K';
    board[5][0] = 'B';
    board[6][0] = 'N';
    board[7][0] = 'R';
    board[0][7] = 'r';
    board[1][7] = 'n';
    board[2][7] = 'b';
    board[3][7] = 'q';
    board[4][7] = 'k';
    board[5][7] = 'b';
    board[6][7] = 'n';
    board[7][7] = 'r';
}

void ClearBoard(){
    int i;
    for (i = 0; i < kBoardHeight; i++) {
        free(board[i]);
    }
    free(board);
    board = NULL;
}

void PrintBoard(){
    int i,j;
    for (i = -1; i < kBoardHeight; i++) {
        for (j = -1; j < kBoardWidth; j++) {
            if (j < 0 && i < 0) {
                printf("   ");
            } else  if (j < 0) {
                printf("%d I",i + 1);
            } else if (i < 0) {
                printf(" %c  ",'A' + j);
            } else {
                printf(" %c I",board[j][i]);
            }
        }
        printf("\n  ");
        printf("________________________________\n");
    }
}

/*int MakeMove(char *move, int m1, int pawn) {
    int l1 = (int)(move[m1+1-pawn] - 'a');
    int l2 = (int)(move[m1+4-pawn] - 'a');
    int d1 = (int)(move[m1+2-pawn] - '1');
    int d2 = (int)(move[m1+5-pawn] - '1');
    if (CheckSyntax(move,m1,pawn) && ((pawn && (board[l1][d1]=='P' || board[l1][d1]=='p')) ||
            (board[l1][d1]==move[m1]||board[l1][d1]==move[m1]+32)) && board[l2][d2]==' ') {
        board[l2][d2] = board[l1][d1];
        board[l1][d1] = ' ';
    } else {
        return 0;
    }
    return 1;
}*/
