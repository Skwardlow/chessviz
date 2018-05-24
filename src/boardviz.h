#ifndef CHESSVIZ_BOARD_H_
#define CHESSVIZ_BOARD_H_

char** board;

void FillBoard();
void ClearBoard();
int MakeMove(char*, int, int);
void PrintBoard();
void InitBoard();
#endif //CHESSVIZ_BOARD_H_
