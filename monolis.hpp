#define BIT_E 0x10      // Use for break block, put a mark on changing block.
#include <vector>

class Monolis {
public:
    // Make a random board.
    Monolis(int h, int w, int c);
    // Make a copy from *b.
    Monolis(int h, int w, int c, const int *b);
    // copy constructor
    Monolis(Monolis &mc);
    // destructor
    ~Monolis();
    inline int height() { return _height; }
    inline int width() { return _width; }
    inline int board_size() { return _height * _width; }
    inline int num_color() { return _num_color; }
    inline int block(int i, int j) { return _board[i*_width+j]; }
    inline int block(int i) { return _board[i]; }
    // Print board on console.
    void show_board();
    // Break the blocks from board(i,j) if its breakable.
    void break_from(int i, int j);
private:
    int _height;         // height of board
    int _width;          // width of board
    int _num_color;      // number of colors
    int* _board;         // array[height * width]
    inline int* block_p(int i, int j) { return _board + i * width() + j; }
    void break_at(int i, int j, int color, std::vector<int*> *vec);
};