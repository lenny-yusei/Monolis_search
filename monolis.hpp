#define BIT_E 0x10
#include <vector>

class Monolis {
public:
    Monolis(int h, int w, int c);
    Monolis(int h, int w, int c, const int *b);
    Monolis(Monolis &mc);
    ~Monolis();
    inline int height() { return _height; }
    inline int width() { return _width; }
    inline int num_color() { return _num_color; }
    inline int board(int i, int j) { return _board[i*_width+j]; }
    inline int board(int i) { return _board[i]; }
    void show_board();
    void break_from(int i, int j);
private:
    int _height;         // height of board
    int _width;          // width of board
    int _num_color;      // number of colors
    int* _board;         // array[height * width]
    inline int* board_p(int i, int j) { return _board + i * width() + j; }
    void break_at(int i, int j, int color, std::vector<int*> *vec);
};