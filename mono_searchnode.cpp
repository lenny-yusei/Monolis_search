
#include "mono_data.hpp"
#include "mono_searchnode.hpp"

MonoSearchNode::MonoSearchNode(Monolis &mono)
{
    data = new MonoData(mono);
    best = new MonoBestNode();
    work_queue.push_back(this);
}
MonoSearchNode::MonoSearchNode(MonoData* data, MonoBestNode* best)
{
    this->data = data;
    this->best = best;
}

MonoSearchNode::~MonoSearchNode()
{
    delete data;
}

void MonoSearchNode::search()
{
    int breakable_num[data->board_size()] = {0};
    /**/
}

MonoSearchNode* MonoSearchNode::get_worknode()
{
    MonoSearchNode* node = work_queue.back();
    work_queue.pop_back();
    return node;
}
