#include "mono_data.hpp"
#include "monolis.hpp"
#include <vector>
#include <cstring>

MonoData::MonoData(Monolis &m)
{
    _height = m.height();
    _width = m.width();
    _board_size = m.board_size();
    _num_color = m.num_color();
    data = new char[_board_size];
    for (int i = 0; i < _board_size; i++) {
        data[i] = (char)m.block(i);
    }
}
MonoData::MonoData(MonoData &m)
{
    data = new char[_board_size];
    std::memcpy(data, m.data, sizeof data);
}
MonoData::~MonoData()
{
    delete [] data;
}

/* (i, j) must conform 0 <= i < height, 0 <= j < width.*/
bool MonoData::breakable(int i, int j)
{
    return j > 0 && block(i, j) == block(i, j - 1) ||
           j < height() - 1 && block(i, j) == block(i, j + 1) ||
           i > 0 && block(i, j) == block(i - 1, j) ||
           i < width() - 1 && block(i, j) == block(i + 1, j);
}

/* It must be breakable(i, j) == true. */
void MonoData::breakfrom(int i, int j)
{
    std::vector<char*> vec;
    break_at(i, j, block(i, j), vec);

    for (i = 0; i < vec.size(); i++) {
        char* p = vec[i];
        *p = *p & ~BIT_E;
        if (*p != 0)
            *p = (*p == num_color()) ? 1 : *p + 1;
    }
}

void MonoData::break_at(int i, int j, int color, std::vector<char*> &vec)
{
    if (block(i, j) == color) {
        *block_p(i, j) = 0;
        if (i > 0)
            break_at(i-1, j, color, vec);
        if (i < height() - 1)
            break_at(i+1, j, color, vec);
        if (j > 0)
            break_at(i, j-1, color, vec);
        if (j < width() - 1)
            break_at(i, j+1, color, vec);
    } else if (block(i, j) != 0 && (block(i, j) & BIT_E) == 0) {
        *block_p(i, j) |= BIT_E;
        vec.push_back(block_p(i, j));
    }
}