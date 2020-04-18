#include "monolis.hpp"

class MonoData {
public:
    MonoData(Monolis&);
    MonoData(MonoData&);
    ~MonoData();
    static int _height;
    static int _width;
    static int _board_size;
    static int _num_color;
    char* data;             // It is using char intead of int to reduse memory.

    inline int height() { return _height; }
    inline int width() { return _width; }
    inline int board_size() { return _board_size; }
    inline int num_color() { return _num_color; }
    inline int block(int i, int j) { return data[i*_height+j]; }
    /* (i, j) must conform 0 <= i < height, 0 <= j < width.*/
    bool breakable(int i, int j);
    /* It must be breakable(i, j) == true. */
    void breakfrom(int i, int j);
private:
    void break_at(int i, int j, int color, std::vector<char*> &vec);
    inline char* block_p(int i, int j) { return data + i * width() + j; }
};