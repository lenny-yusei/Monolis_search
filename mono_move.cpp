#include "mono_move.hpp"
#include <iostream>
#include <vector>
#include "mono_point.hpp"

MonoMove::MonoMove(int n) : num_disle(n), move() { }
MonoMove::MonoMove(const MonoMove& mm) : num_disle(mm.num_disle), move(mm.move) { }
MonoMove::~MonoMove() { }

int MonoMove::getnum() const
{
    return num_disle;
}

void MonoMove::show_move()
{
    for (int i = 0; i < move.size(); i++) {
        std::cout << move[i] << ", ";
    }
    std::cout << std::endl;
}

void MonoMove::add_move(MonoPoint& mp)
{
    move.push_back(mp);
}