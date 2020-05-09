#include "mono_searchnode.hpp"
#include <iostream>
#include <vector>
#include "monolis.hpp"
#include "mono_data.hpp"
#include "mono_bestnode.hpp"
#include "mono_searchqueue.hpp"

MonoSearchNode::MonoSearchNode(const MonoData& data, const MonoMove& move, MonoBestNode* best) : data(data), move(move), best(best) { }

MonoSearchNode::~MonoSearchNode() { }

MonoSearchQueue* MonoSearchNode::queue;
MonoBestNode* MonoSearchNode::top_result;

void MonoSearchNode::init(const Monolis& mono)
{
    queue = new MonoSearchQueue();
    MonoData md(mono);
    MonoMove mm(0);
    MonoBestNode* mb = new MonoBestNode(mono.board_size());
    MonoSearchNode* node = new MonoSearchNode(md, mm, mb);
    top_result = mb;
    queue->add_node(node);
}

void MonoSearchNode::start_search()
{
    while (queue->has_node()) {
        MonoSearchNode* node = queue->pop_node();
        node->search();
        delete node;
        queue->end_node();
    }
}

MonoBestNode* MonoSearchNode::result()
{
    return top_result;
}


void MonoSearchNode::search()
{
    int block_count = 0;
    int breacable_count = 0;
    int breakable_num[data.board_size()] = {0};
    std::vector<MonoPoint> breakable_point;
    int isle_num[data.board_size()] = {0};
    int isle_count = 0;

    // Search for breakable points and stock the first point.
    for (int i = 0; i < data.height(); i++) {
        for (int j = 0; j < data.width(); j++) {
            if (breakable_num[pos(i, j)] == 0 && data.breakable(i, j)) {
                breacable_count++;
                put_breakable_num(breakable_num, i, j, breacable_count);
                breakable_point.emplace_back(i, j);

                if (isle_num[pos(i, j)] == 0) {
                    isle_count++;
                    put_isle_num(isle_num, i, j, isle_count);
                }
            }
        }
    }    

    for (int i = 0; i < data.height(); i++) {
        for (int j = 0; j < data.width(); j++) {
            if (data.block(i, j) != 0 && isle_num[pos(i, j)] == 0) {
                data.block(i, j) = 0;
                move.num_disle++;
            }
        }
    }
    // std::cout << "unbreakable points = " << num_d_isle << std::endl;
    if (move.num_disle >= best->best_move.num_disle) {
        return;
    }

    if (breacable_count == 0) {         // If there is no breakable point, update the best score.
        best->update(move);
    } else {
        for (int i = 0; i < breakable_point.size(); i++) {
            // std::cout << "new_move" << std::endl;
            MonoSearchNode* new_node = new MonoSearchNode(data, move, best);
            new_node->data.breakfrom(breakable_point[i]);
            new_node->move.add_move(breakable_point[i]);
            queue->add_node(new_node);
            //std::cout << "new_node" << std::endl;
        }
        // std::cout << std::endl;
    }
}

// Put breakable count from the first breakable point.
void MonoSearchNode::put_breakable_num(int* breakable_num, int i, int j, int b_count)
{
    breakable_num[pos(i, j)] = b_count;

    if (j > 0 && breakable_num[pos(i, j - 1)] == 0 && data.block(i, j) == data.block(i, j - 1))
        put_breakable_num(breakable_num, i, j - 1, b_count);
    if (j < data.width() - 1 && breakable_num[pos(i, j + 1)] == 0 && data.block(i, j) == data.block(i, j + 1))
        put_breakable_num(breakable_num, i, j + 1, b_count);
    if (i > 0 && breakable_num[pos(i - 1, j)] == 0 && data.block(i, j) == data.block(i - 1, j))
        put_breakable_num(breakable_num, i - 1, j, b_count);
    if (i < data.height() - 1 && breakable_num[pos(i + 1, j)] == 0 && data.block(i, j) == data.block(i + 1, j))
        put_breakable_num(breakable_num, i + 1, j, b_count);
}

// Put isle number from breakable point.
void MonoSearchNode::put_isle_num(int* isle_num, int i, int j, int i_count)
{
    isle_num[pos(i, j)] = i_count;

    if (j > 0 && isle_num[pos(i, j - 1)] == 0 && data.block(i, j - 1) != 0)
        put_isle_num(isle_num, i, j - 1, i_count);
    if (j < data.width() - 1 && isle_num[pos(i, j + 1)] == 0 && data.block(i, j + 1) != 0)
        put_isle_num(isle_num, i, j + 1, i_count);
    if (i > 0 && isle_num[pos(i - 1, j)] == 0 && data.block(i - 1, j) != 0)
        put_isle_num(isle_num, i - 1, j, i_count);
    if (i < data.height() - 1 && isle_num[pos(i + 1, j)] == 0 && data.block(i + 1, j) != 0)
        put_isle_num(isle_num, i + 1, j, i_count);
}

inline int MonoSearchNode::pos(int i, int j) { return i * data.width() + j; }

/*/
int main()
{
    Monolis a(4, 4, 3);
    MonoSearchNode msn(a);
}
/*/