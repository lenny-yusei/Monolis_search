/* mono_searchnode.hpp
 * island | isle : group of adjoining blocks which are isolated from other blocks.
 * desert_island | d_isle : island which has no breakable point.
 */
#ifndef _MONO_SEARCHNODE_HPP_
#define _MONO_SEARCHNODE_HPP_

#include <vector>
#include <list>
#include "mono_move.hpp"
#include "mono_data.hpp"

class Monolis;
class MonoSearchQueue;
class MonoBestNode;

// Get MonoData and search breakable points from it.
class MonoSearchNode
{
    static MonoSearchQueue* queue;
    static MonoBestNode* top_result;
    MonoBestNode* best;
    MonoData data;
    MonoMove move;
public:
    static void init(const Monolis&);
    static void start_search();
    static MonoBestNode* result();
private:
    MonoSearchNode(const MonoData& data, const MonoMove& move, MonoBestNode* best);
    ~MonoSearchNode();
    void search();
    inline int pos(int i, int j);
    void put_breakable_num(int* breakable_num, int i, int j, int b_count);
    void put_isle_num(int* isle_num, int i, int j, int i_count);
};

#endif