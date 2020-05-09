#ifndef _MONO_BESTNODE_HPP_
#define _MONO_BESTNODE_HPP_

#include <vector>
#include "mono_move.hpp"

class MonoBestNode {
public:
    MonoMove best_move;
    
    MonoBestNode(int maxsize);
    ~MonoBestNode();
    void update(MonoMove&);
    void show();
};

#endif