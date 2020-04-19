#ifndef _MONO_SEARCHNODE_HPP_
#define _MONO_SEARCHNODE_HPP_

#include <vector>
#include <list>
#include "mono_data.hpp"
#include "mono_bestnode.hpp"

/* Get MonoData and search breakable points from it. */
/* return the best in broken. */
class MonoSearchNode {
public:
    static std::vector<MonoSearchNode*> work_queue;
    MonoData* data;
    std::vector<int> move;
    MonoBestNode* best;
    static MonoBestNode* the_best;

    MonoSearchNode(Monolis& mono);
    MonoSearchNode(MonoData* data, std::vector<int> move, MonoBestNode* best);
    ~MonoSearchNode();
    void search();
    static MonoSearchNode* get_worknode();
    static bool haswork() { return !work_queue.empty(); }
private:
    void put_breakable_num(int breakable_num[], int i, int j, int start_p);
    inline int blockpos(int i, int j) { return i * data->height() + j; }
    inline int* data_p(int* d, int i, int j) { return d + i * data->height() + j; }
};

#endif