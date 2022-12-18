#pragma once

struct Action
{
    /*agentからの出力*/
private:
    int move;

public:
    int GetMove()
    {
        return move;
    }
    Action()
    {
    }
    Action(int pos)
    {
        move = pos;
    }
};