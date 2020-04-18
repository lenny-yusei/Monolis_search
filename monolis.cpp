#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "monolis.h"

Monolis::Monolis(int h, int w, int c)
{
    _height = h;
    _width = w;
    _num_color = c;
    _board = new int[_height * _width];

    std::srand(std::time(NULL));
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            _board[i * _width + j] = rand() % _num_color + 1;
        }
    }
}
Monolis::Monolis(int h, int w, int c, const int *b)
{
    _height = h;
    _width = w;
    _num_color = c;
    _board = new int[_height * _width];

    std::copy(b, b + _height * _width, _board);
}
Monolis::Monolis(Monolis &mc)
{
    _height = mc._height;
    _width = mc._width;
    _num_color = mc._num_color;
    _board = new int[_height * _width];

    std::copy(mc._board, mc._board + mc._height * mc._width, this->_board);
}
Monolis::~Monolis()
{
    std::cout << "delete" << std::endl;
    delete [] _board;
}

void Monolis::show_board()
{
    for (int i = 0; i < height(); i++) {
        for (int j = 0; j < width(); j++) {
            std::cout << board(i, j);
        }
        std::cout << std::endl;
    }
}

void Monolis::break_from(int i, int j)
{
    std::vector<int*> vec;
    if (i > 0 && board(i, j) == board(i - 1, j) ||
        i < height() - 1 && board(i, j) == board(i + 1, j) ||
        j > 0 && board(i, j) == board(i, j - 1) ||
        j < width() - 1 && board(i, j) == board(i, j + 1) ) {
            break_at(i, j, board(i, j), &vec);
    }
    std::cout << vec.size() << std::endl;
    for (i = 0; i < vec.size(); i++) {
        int* p = vec[i];
        *p = *p & ~BIT_E;
        if (*p != 0)
            *p = (*p == num_color()) ? 1 : *p + 1;
    }
}

void Monolis::break_at(int i, int j, int color, std::vector<int*> *vec)
{
    if (board(i, j) == color) {
        *board_p(i, j) = 0;
        if (i > 0)
            break_at(i-1, j, color, vec);
        if (i < height() - 1)
            break_at(i+1, j, color, vec);
        if (j > 0)
            break_at(i, j-1, color, vec);
        if (j < width() - 1)
            break_at(i, j+1, color, vec);
    } else if (!(board(i, j) == 0 || (board(i, j) & BIT_E) != 0)) {
        *board_p(i, j) |= BIT_E;
        vec->push_back(board_p(i, j));
    }
}

/*
int main(void)
{
    int a, b;
    Monolis* m1 = new Monolis(5,5,3);
    Monolis* m2 = new Monolis(*m1);
    
    m1->show_board();
    std::cin >> a >> b;
    m2->break_from(a, b);
    m1->show_board();
    std::cout << std::endl;
    m2->show_board();
    delete m1;
    delete m2;
    Monolis m3(10, 10, 3);
    return 0;
}
*/