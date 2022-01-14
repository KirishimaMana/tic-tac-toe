#include"ticTacToe.h"

tb board[9];

void init_game()
{
    board[0]={HEI/2-LEN,HEI/2-LEN,0};
    board[1]={HEI/2,HEI/2-LEN,0};
    board[2]={HEI/2+LEN,HEI/2-LEN,0};
    board[3]={HEI/2-LEN,HEI/2,0};
    board[4]={HEI/2,HEI/2,0};
    board[5]={HEI/2+LEN,HEI/2,0};
    board[6]={HEI/2-LEN,HEI/2+LEN,0};
    board[7]={HEI/2,HEI/2+LEN,0};
    board[8]={HEI/2+LEN,HEI/2+LEN,0};
}

void draw_board(bool* player,bool* judge)
{
    setlinewidth(1);
    moveto(HEI/2-LEN/2-LEN,HEI/2-LEN/2);
    linerel(3*LEN,0);
    moveto(HEI/2-LEN/2-LEN,HEI/2+LEN/2);
    linerel(3*LEN,0);
    moveto(HEI/2-LEN/2,HEI/2-LEN/2-LEN);
    linerel(0,3*LEN);
    moveto(HEI/2+LEN/2,HEI/2-LEN/2-LEN);
    linerel(0,3*LEN);
    moveto(HEI/2-LEN/2-LEN,HEI/2-LEN/2-LEN);
    linerel(3*LEN,0);
    linerel(0,3*LEN);
    linerel(-3*LEN,0);
    linerel(0,-3*LEN);

    setlinewidth(10);
    int i;
    for(i=0;i<9;i++)
    {
        if(board[i].value==1)
        drawX(i);
        else if(board[i].value==2)
        drawO(i);
    }

    setlinewidth(5);
    if(*player)
    {
        line(getwidth()/2-CHE/2,530-CHE/2,getwidth()/2+CHE/2,530+CHE/2);
        line(getwidth()/2+CHE/2,530-CHE/2,getwidth()/2-CHE/2,530+CHE/2);
    }
    else
    circle(getwidth()/2,530,CHE/2);

    judge_game(judge);
}

int button_move(mouse_msg msg,bool* dr)
{
    int i;
    if(msg.is_move())
    {
        for(i=0;i<9;i++)
        {
            if(msg.x<=board[i].x+GAP&&msg.x>=board[i].x-GAP&&msg.y<=board[i].y+GAP&&msg.y>=board[i].y-GAP)
            {
                *dr=true;
                break;
            }
        }
    }
    return i;
}

int button_down(mouse_msg msg,bool* dow,bool* player)
{
    int j;
    if(msg.is_left())
    {
        if(msg.is_down())
        {
            for(j=0;j<9;j++)
            {
                if(board[j].value)
                continue;
                if(msg.x<=board[j].x+GAP&&msg.x>=board[j].x-GAP&&msg.y<=board[j].y+GAP&&msg.y>=board[j].y-GAP)
                {
                    if(*player)
                    {
                        board[j].value=1;
                        *player=false;
                    }
                    else
                    {
                        board[j].value=2;
                        *player=true;
                    }
                    *dow=true;
                    break;
                }
            }
        }
    }
    return j;
}

void instant_draw(int i,bool* dr)
{
    if(*dr)
    {
        setlinewidth(1);
        rectangle(board[i].x-GAP,board[i].y-GAP,board[i].x+GAP,board[i].y+GAP);
    }
}


void down_draw(int i,bool* dow)
{
    if(*dow)
    {
        setlinewidth(5);
        rectangle(board[i].x-GAP,board[i].y-GAP,board[i].x+GAP,board[i].y+GAP);
        *dow=false;
    }
}

void drawX(int i)
{
    line(board[i].x-CHE,board[i].y-CHE,board[i].x+CHE,board[i].y+CHE);
    line(board[i].x+CHE,board[i].y-CHE,board[i].x-CHE,board[i].y+CHE);
}

void drawO(int i)
{
    circle(board[i].x,board[i].y,CHE);
}

void judge_game(bool* judge)
{
    bool tie=true;
    int i;
    setlinewidth(2);
    for(i=0;i<3;i++)
    {
        if(board[i].value)
        {
            if(board[i].value==board[i+3].value&&board[i].value==board[i+6].value)
            {
                rectangle(board[i].x-GAP,board[i].y-GAP,board[i].x+GAP,board[i].y+GAP);
                rectangle(board[i+3].x-GAP,board[i+3].y-GAP,board[i+3].x+GAP,board[i+3].y+GAP);
                rectangle(board[i+6].x-GAP,board[i+6].y-GAP,board[i+6].x+GAP,board[i+6].y+GAP);
                *judge=true;
                tie=false;
            }
        }
    }
    for(i=0;i<7;i=i+3)
    {
        if(board[i].value)
        {
            if(board[i].value==board[i+1].value&&board[i].value==board[i+2].value)
            {
                rectangle(board[i].x-GAP,board[i].y-GAP,board[i].x+GAP,board[i].y+GAP);
                rectangle(board[i+1].x-GAP,board[i+1].y-GAP,board[i+1].x+GAP,board[i+1].y+GAP);
                rectangle(board[i+2].x-GAP,board[i+2].y-GAP,board[i+2].x+GAP,board[i+2].y+GAP);
                *judge=true;
                tie=false;
            }
        }
    }
    if(board[0].value&&board[4].value&&board[8].value)
    {
        if(board[0].value==board[4].value&&board[0].value==board[8].value)
        {
            rectangle(board[0].x-GAP,board[0].y-GAP,board[0].x+GAP,board[0].y+GAP);
            rectangle(board[4].x-GAP,board[4].y-GAP,board[4].x+GAP,board[4].y+GAP);
            rectangle(board[8].x-GAP,board[8].y-GAP,board[8].x+GAP,board[8].y+GAP);
            *judge=true;
            tie=false;
        }
    }
    if(board[2].value&&board[4].value&&board[6].value)
    {
        if(board[2].value==board[4].value&&board[2].value==board[6].value)
        {
            rectangle(board[2].x-GAP,board[2].y-GAP,board[2].x+GAP,board[2].y+GAP);
            rectangle(board[4].x-GAP,board[4].y-GAP,board[4].x+GAP,board[4].y+GAP);
            rectangle(board[6].x-GAP,board[6].y-GAP,board[6].x+GAP,board[6].y+GAP);
            *judge=true;
            tie=false;
        }
    }

    for(i=0;i<9;i++)
    {
        if(board[i].value==0)
        break;
    }
    if(i==9&&tie)
    {
        for(i=0;i<9;i++)
        rectangle(board[i].x-GAP,board[i].y-GAP,board[i].x+GAP,board[i].y+GAP);
        *judge=true;
    }
}