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
    char* data;

    inline int height() { return _height; }
    inline int width() { return _width; }
    inline int board_size() { return _board_size; }
    inline int num_color() { return _num_color; }
    inline int board(int i, int j) { return data[i*_height+j]; }
    bool breakable(int i, int j);
    void breakfrom(int i, int j);
};