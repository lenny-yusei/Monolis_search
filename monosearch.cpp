/* monosearch.cpp */
#include <iostream>
#include "monolis.hpp"
#include "mono_searchnode.hpp"

int main()
{
    Monolis mono(5, 5, 3);
    MonoSearchNode msnode_base(mono);
    MonoSearchNode* node;

    while (!MonoSearchNode::haswork()) {
        node = MonoSearchNode::get_worknode();
        node->search();
        delete node;
    }

    return 0;
}