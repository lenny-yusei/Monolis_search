/* monosearch.cpp */
#include <iostream>
#include "monolis.hpp"
#include "mono_searchnode.hpp"

int main()
{
    Monolis mono(5, 5, 3);
    mono.show_board();
    MonoSearchNode msnode_base(mono);
    MonoSearchNode* node;

    while (MonoSearchNode::haswork()) {
        node = MonoSearchNode::get_worknode();
        node->search();
        delete node;
        std::cout << "test" << std::endl;
    }

    MonoSearchNode::the_best->show();

    std::vector<int> &best_move = MonoSearchNode::the_best->best_move;
    for (int i = 0; i < best_move.size(); i++) {
        mono.break_from(best_move[i] / mono.width(), best_move[i] % mono.width());
    }
    mono.show_board();

    return 0;
}