#include"ticTacToe.h"

int main(int argc,char* argv[])
{
    initgraph(WID,600,INIT_RENDERMANUAL);
    ege_enable_aa(true);
    setbkcolor(BLACK);
    setcolor(WHITE);
    setfillcolor(WHITE);
    setcaption("tic_tac_toe");
    
    int i;
    int j;
    bool dr=false;
    bool dow=false;
    bool player=true;
    bool judge=false;

    init_game();


    draw_board(&player,&judge);

    for(;is_run();delay_fps(60))
    {
        if(judge)
        break;
        while(mousemsg())
        {
            mouse_msg msg=getmouse();
            i=button_move(msg,&dr);
            j=button_down(msg,&dow,&player);
            if(dr||dow)
            {
                instant_draw(i,&dr);
                down_draw(j,&dow);
                dr=false;
                dow=false;
            }
            else
            {
                cleardevice();
                draw_board(&player,&judge);
            }
        }
    }

    getch();
    closegraph();

    return 0;
}

//完全不知道自己写了什么