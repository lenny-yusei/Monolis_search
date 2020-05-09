#include "monolis.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "mono_point.hpp"

// Make a random board.
Monolis::Monolis(int h, int w, int c) : m_height(h), m_width(w), m_num_color(c), m_board(new int[h * w])
{
    std::srand(std::time(NULL));
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            m_board[i * m_width + j] = rand() % m_num_color + 1;
        }
    }
}
// Make a copy from *b.
Monolis::Monolis(int h, int w, int c, const int *b) : m_height(h), m_width(w), m_num_color(c), m_board(new int[h * w])
{
    std::copy(b, b + m_height * m_width, m_board);
}
// copy constructor
Monolis::Monolis(Monolis &mc) : m_height(mc.m_height), m_width(mc.m_width), m_num_color(mc.m_num_color), m_board(new int[m_height * m_width])
{
   std::copy(mc.m_board, mc.m_board + m_height * m_width, this->m_board);
}
// Return the data at (i, j).
inline int Monolis::block(MonoPoint& mp) const
{
    return m_board[mp.y * m_width + mp.x];
}
// Return block(i, j) is breakable.
bool Monolis::breakable(int i, int j) const
{
    return block(i, j) != 0 && (
        j > 0 && block(i, j) == block(i, j - 1) || j < m_width - 1 && block(i, j) == block(i, j + 1) ||
        i > 0 && block(i, j) == block(i - 1, j) || i < m_height - 1 && block(i, j) == block(i + 1, j)
    );
}
bool Monolis::breakable(MonoPoint& mp) const
{
    return breakable(mp.y, mp.x);
}

inline int Monolis::point(MonoPoint& mp)
{
    return mp.y * m_width + mp.x;
}

void Monolis::show_board() const
{
    for (int i = 0; i < height(); i++) {
        for (int j = 0; j < width(); j++) {
            std::cout << block(i, j);
        }
        std::cout << std::endl;
    }
}

void Monolis::break_from(int i, int j)
{
    // Set pointers of changing blocks.
    std::vector<int> vec;
    if (breakable(i, j)) {
        break_at(i, j, m_board[point(i, j)], vec);
    }
    //std::cout << vec.size() << std::endl;
    // Remove bit from changing blocks and then change those color to next color.
    for (int k = 0; k < vec.size(); k++) {
        int& p = m_board[vec[k]];
        p = p & ~BIT_E;
        if (p != 0)
            p = (p == num_color()) ? 1 : p + 1;
    }
}

void Monolis::break_from(MonoPoint& mp)
{
    break_from(mp.y, mp.x);
}

void Monolis::break_at(int i, int j, int color, std::vector<int>& vec)
{
    //std::cout << i << "," << j << std::endl;
    if (block(i, j) == color) {
        m_board[point(i, j)] = 0;
        if (j > 0)
            break_at(i, j - 1, color, vec);
        if (j < width() - 1)
            break_at(i, j + 1, color, vec);
        if (i > 0)
            break_at(i - 1, j, color, vec);
        if (i < height() - 1)
            break_at(i + 1, j, color, vec);
    } else if (m_board[point(i, j)] != 0 && (m_board[point(i, j)] & BIT_E) == 0) {
        m_board[point(i, j)] |= BIT_E;
        vec.push_back(point(i, j));
    }
}

/*/
int main(void)
{
    int a, b;
    Monolis* m1 = new Monolis(5,5,3);
    m1->show_board();

    std::cin >> a >> b;
    auto mp = MonoPoint(a, b);
    std::cout << mp << std::endl;
    m1->break_from(mp);
    std::cout << std::endl;
    m1->show_board();
    delete m1;

    return 0;
}
/*/
