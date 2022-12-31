#include "cell.hpp"

Cell ToOpponentCell(Cell cell)
{
    if (cell == Cell::ME)
        return Cell::OPPONENT;
    else if (cell == Cell::OPPONENT)
        return Cell::ME;
    else if (cell == Cell::NO_ONE)
        return Cell::NO_ONE;
    else
        throw std::runtime_error("error in ToOpponentCell()");
}
