#pragma once

#include <array>

enum class TetriminoType { I, J, L, O, S, T, Z };

enum class Color { Red, Pink, Green, Yellow, Orange, Blue, Cyan };

class Tetrimino {
public:
    Tetrimino(TetriminoType type);
    ~Tetrimino();

private:
    TetriminoType type_;
    Color color_;
};
