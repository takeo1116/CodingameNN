#pragma once

struct Action{
    /*agentからの出力*/
    int move;

    Action(int pos)
    {
        move = pos;
    }
};