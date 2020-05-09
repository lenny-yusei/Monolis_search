#include "mono_data.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include "monolis.hpp"

MonoData::MonoData(const Monolis &mono)
{
    m_height = mono.height();
    m_width = mono.width();
    m_board_size = mono.board_size();
    m_num_color = mono.num_color();
    data = new char[m_board_size];
    for (int p = 0; p < m_board_size; p++) {
        data[p] = (char)mono.block(0, p);
    }
}
MonoData::MonoData(const MonoData& md)
{
    data = new char[m_board_size];
    std::copy(md.data, md.data + m_board_size, data);
}

int MonoData::m_height = 0;
int MonoData::m_width = 0;
int MonoData::m_board_size = 0;
int MonoData::m_num_color = 0;

/* (i, j) must conform 0 <= i < height, 0 <= j < width.*/
bool MonoData::breakable(int i, int j)
{
    return block(i, j) != 0 && (
        0 < j && block(i, j) == block(i, j - 1) || j < width() - 1 && block(i, j) == block(i, j + 1) ||
        0 < i && block(i, j) == block(i - 1, j) || i < height() - 1 && block(i, j) == block(i + 1, j) );
}

/* It must be breakable(i, j) == true. */
void MonoData::breakfrom(int i, int j)
{
    std::vector<int> vec;
    break_at(i, j, data[point(i, j)], vec);

    for (i = 0; i < vec.size(); i++) {
        char& p = data[vec[i]];
        p = p & ~BIT_E;
        if (p != 0)
            p = (p == num_color()) ? 1 : p + 1;
    }
}
void MonoData::breakfrom(MonoPoint& mp)
{
    breakfrom(mp.y, mp.x);
}

void MonoData::break_at(int i, int j, int color, std::vector<int> &vec)
{
    char& block_i_j = block(i, j);
    if (block_i_j == color) {
        block_i_j = 0;
        if (j > 0)
            break_at(i, j - 1, color, vec);
        if (j < width() - 1)
            break_at(i, j + 1, color, vec);
        if (i > 0)
            break_at(i - 1, j, color, vec);
        if (i < height() - 1)
            break_at(i + 1, j, color, vec);
    } else if (block_i_j != 0 && (block_i_j & BIT_E) == 0) {
        block_i_j |= BIT_E;
        vec.push_back(point(i, j));
    }
}

void MonoData::show_board()
{
    for (int i = 0; i < height(); i++) {
        for (int j = 0; j < width(); j++) {
            std::cout << block(i, j);
        }
        std::cout << std::endl;
    }
}
/*/
int main()
{

}
/*/