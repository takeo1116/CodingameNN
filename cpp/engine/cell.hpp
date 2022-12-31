#pragma once
#include <iostream>

enum class Cell : int
{
    NO_SET,
    ME,
    OPPONENT,
    NO_ONE,
};

Cell ToOpponentCell(Cell cell);
