#include <iostream>
#include <vector>
#include "mono_bestnode.hpp"
#include "mono_move.hpp"

MonoBestNode::MonoBestNode(int maxsize) : best_move(maxsize) { }

MonoBestNode::~MonoBestNode() { }

void MonoBestNode::update(MonoMove& move)
{
    if (move.num_disle < best_move.num_disle) {
        best_move = move;
    }
}

void MonoBestNode::show()
{
    std::cout << "best count: " << best_move.num_disle << std::endl;
    if (best_move.move.empty()) {
        std::cout << "best move: empty" << std::endl;
    } else {
        best_move.show_move();
    }
}