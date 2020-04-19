#ifndef _MONO_BESTNODE_HPP_
#define _MONO_BESTNODE_HPP_

#include <vector>

class MonoBestNode {
public:
    int smallest_num_unbreakable;
    std::vector<int> best_move;
    MonoBestNode(int maxsize);
    ~MonoBestNode();
    void update(int n, std::vector<int> &move);
    void show();
};

#endif