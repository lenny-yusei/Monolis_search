#include <iostream>
#include <vector>
#include "mono_bestnode.hpp"

MonoBestNode::MonoBestNode(int maxsize) : smallest_num_unbreakable(maxsize) { }

MonoBestNode::~MonoBestNode() { }

void MonoBestNode::update(int n, std::vector<int> &move)
{
    if (n < smallest_num_unbreakable) {
        smallest_num_unbreakable = n;
        best_move = move;
    }
}

void MonoBestNode::show()
{
    std::cout << "best count: " << smallest_num_unbreakable << std::endl;
    if (best_move.empty()) {
        std::cout << "best move: empty" << std::endl;
    } else {
        std::cout << "best move:" << std::endl;
        for (int i = 0; i < best_move.size() - 1; i++) {
            std::cout << best_move[i] << "->";
        }
        std::cout << best_move.back() << std::endl;
    }
}