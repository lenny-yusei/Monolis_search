#ifndef _MONO_DATA_HPP_
#define _MONO_DATA_HPP_

#include <vector>
#include "mono_point.hpp"

class Monolis;

class MonoData
{
public:
    MonoData(const Monolis&);
    MonoData(const MonoData&);
    ~MonoData() { delete [] data; }

    inline int height() const { return m_height; }
    inline int width() const { return m_width; }
    inline int board_size() const { return m_board_size; }
    inline int num_color() const { return m_num_color; }
    // Return refurence of data[i * m_width + j].
    inline char& block(int i, int j) { return data[i * m_width + j]; }
    // (i, j) must conform 0 <= i < height, 0 <= j < width.
    bool breakable(int i, int j);
    void breakable(MonoPoint& mp);
    // It must be breakable(i, j) == true.
    void breakfrom(int i, int j);
    void breakfrom(MonoPoint& mp);
    // Show the data on console.
    void show_board();
    // Overloard []
    char& operator [] (MonoPoint mp) { return data[mp.y * m_width + mp.x]; }
private:
    static int m_height;
    static int m_width;
    static int m_board_size;
    static int m_num_color;
    // It is using char intead of int to reduse memory.
    char* data;

    inline int point(int i, int j) { return i * m_width + j; }
    void break_at(int i, int j, int color, std::vector<int> &vec);
};

#endif