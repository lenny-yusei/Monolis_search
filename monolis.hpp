/* monolis.hpp
 * 
 * 
 */
#ifndef _MONOLIS_HPP_
#define _MONOLIS_HPP_

#include <vector>
#include <memory>

#define BIT_E 0x100      // Use for break block, put a mark on changing block.

class MonoPoint;

class Monolis
{
public:
    // Make a random board.
    Monolis(int h, int w, int c);
    // Make a copy from *b.
    Monolis(int h, int w, int c, const int *b);
    // copy constructor
    Monolis(Monolis &mc);
    // destructor
    ~Monolis() { delete [] m_board; }
    inline int height() const { return m_height; }
    inline int width() const { return m_width; }
    inline int board_size() const { return m_height * m_width; }
    inline int num_color() const { return m_num_color; }
    // Return the data at (i, j).
    inline int block(int i, int j) const { return m_board[i * m_width + j]; }
    inline int block(MonoPoint& mp) const ;
    // Return block(i, j) is breakable.
    bool breakable(int i, int j) const;
    bool breakable(MonoPoint& mp) const;
    // Print board on console.
    void show_board() const;
    // Break the blocks from board(i,j) if its breakable.
    void break_from(int i, int j);
    void break_from(MonoPoint& mp);
private:
    int m_height;         // height of board
    int m_width;          // width of board
    int m_num_color;      // number of colors
    int* m_board;         // array[height * width]
    inline int point(int i, int j) { return i * m_width + j; }
    inline int point(MonoPoint& mp);
    void break_at(int i, int j, int color, std::vector<int>& vec);
};

#endif