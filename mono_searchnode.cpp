#include <vector>
#include "monolis.hpp"
#include "mono_data.hpp"
#include "mono_bestnode.hpp"
#include "mono_searchnode.hpp"

MonoSearchNode::MonoSearchNode(Monolis &mono)
{
    work_queue = std::vector<MonoSearchNode*>();
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

std::vector<MonoSearchNode*> MonoSearchNode::work_queue = std::vector<MonoSearchNode*>();

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

/*/
int main()
{
    Monolis a(4, 4, 3);
    MonoSearchNode msn(a);
}
/*/