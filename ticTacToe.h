#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

#include<graphics.h>
#define LEN 150
#define WID 500
#define HEI 500
#define GAP 60
#define CHE 40

typedef struct theBoard
{
    float x;
    float y;
    int value;
}tb;

extern tb board[9];

void init_game();
void draw_board(bool*,bool*);
void drawX(int);
void drawO(int);

int button_move(mouse_msg,bool*);
int button_down(mouse_msg,bool*,bool*);

void instant_draw(int,bool*);
void down_draw(int,bool*);

void judge_game(bool*);

#endif