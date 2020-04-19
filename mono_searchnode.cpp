#include <vector>
#include "monolis.hpp"
#include "mono_data.hpp"
#include "mono_bestnode.hpp"
#include "mono_searchnode.hpp"
#include <iostream>

MonoSearchNode::MonoSearchNode(Monolis &mono)
{
    this->data = new MonoData(mono);
    this->move = std::vector<int>();
    this->best = new MonoBestNode(mono.board_size());
    the_best = this->best;
    work_queue.clear();
    work_queue.push_back(this);
}
MonoSearchNode::MonoSearchNode(MonoData* data, std::vector<int> move, MonoBestNode* best)
{
    this->data = data;
    this->move = move;
    this->best = best;
}

MonoSearchNode::~MonoSearchNode()
{
    delete data;
}

MonoBestNode* MonoSearchNode::the_best = nullptr;

std::vector<MonoSearchNode*> MonoSearchNode::work_queue = std::vector<MonoSearchNode*>();

void MonoSearchNode::search()
{
    int block_count = 0;
    int breacable_count = 0;
    int breakable_num[data->board_size()] = {0};
    std::vector<int> breakable_point;
    /**/
    for (int i = 0; i < data->height(); i++) {
        for (int j = 0; j < data->width(); j++) {
            if (data->block(i, j) != 0) {
                block_count++;
                if (breakable_num[blockpos(i, j)] == 0 && data->breakable(i, j)) { // 破壊可能なポイントを記録する。最初のポイントは記録する。
                    breacable_count++;
                    breakable_num[blockpos(i, j)] = breacable_count;
                    put_breakable_num(breakable_num, i, j, blockpos(i, j));
                    breakable_point.push_back(blockpos(i, j));
                }
            }
        }
    }

    for (int i = 0; i < data->height(); i++) {
        for (int j = 0; j < data->width(); j++) {
            std::cout << breakable_num[blockpos(i, j)];
        }
        std::cout << std::endl;
    }

    std::cout << "block count = " << block_count << std::endl;
    std::cout << "breakable points = " << breakable_point.size() << std::endl;

    if (breacable_count == 0) {         // If there is no breakable point, update the best score.
        best->update(block_count, move);
    } else {
        for (int i = 0; i < breakable_point.size(); i++) {
            std::cout << i << " : " << breakable_point[i] << std::endl;
            MonoData* new_data = new MonoData(data);
            new_data->breakfrom(0, breakable_point[i]);
            std::cout << "new_data" << std::endl;
            std::vector<int> new_move(move);
            new_move.push_back(breakable_point[i]);
            std::cout << "new_move" << std::endl;
            MonoSearchNode* new_node = new MonoSearchNode(new_data, new_move, best);
            work_queue.push_back(new_node);
            std::cout << "new_node" << std::endl;
        }
        std::cout << std::endl;
    }
}

void MonoSearchNode::put_breakable_num(int* breakable_num, int i, int j, int start_p)
{
    breakable_num[blockpos(i, j)] = breakable_num[start_p];

    if (j > 0 && breakable_num[blockpos(i, j - 1)] == 0 && data->block(i, j) == data->block(i, j - 1))
        put_breakable_num(breakable_num, i, j - 1, start_p);
    if (j < data->width() - 1 && breakable_num[blockpos(i, j + 1)] == 0 && data->block(i, j) == data->block(i, j + 1))
        put_breakable_num(breakable_num, i, j + 1, start_p);
    if (i > 0 && breakable_num[blockpos(i - 1, j)] == 0 && data->block(i, j) == data->block(i - 1, j))
        put_breakable_num(breakable_num, i - 1, j, start_p);
    if (i < data->height() - 1 && breakable_num[blockpos(i + 1, j)] == 0 && data->block(i, j) == data->block(i + 1, j))
        put_breakable_num(breakable_num, i + 1, j, start_p);
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