/* mono_searchnode.hpp
 * island | isle : group of adjoining blocks which are isolated from other blocks.
 * desert_island | d_isle : island which has no breakable point.
 */
#ifndef _MONO_MOVE_HPP_
#define _MONO_MOVE_HPP_

#include <vector>
#include "mono_point.hpp"

class MonoMove
{
public:
    int num_disle;
    std::vector<MonoPoint> move;

    MonoMove(int n);
    MonoMove(const MonoMove&);
    ~MonoMove();
    int getnum() const;
    void add_move(MonoPoint&);
    void show_move();
};

#endif