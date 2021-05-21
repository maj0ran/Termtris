#pragma once

#include "tetriminos.hpp"

#include <final/final.h>
#include <cstddef>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 22

using namespace finalcut;


struct Block
{
  Color color;  
};
struct Cell
{
    std::size_t x;
    std::size_t y;
};

class Playfield final : public FWidget {
public:
    Playfield(FWidget *parent, FPoint &&pos);
    ~Playfield();

    std::array<std::array<std::optional<Block>, FIELD_HEIGHT>, FIELD_WIDTH> cells;
    
    void initLayout() override;
    void draw() override;

private:
    FPoint pos_;

    /* The playfield of Tetris is usually 10 field in width.
     * A single 'cell' has the width 2, as monospace-fonts are half the width
     * as the height. Add another 2 to width and height for the border of the field. */
    static constexpr size_t width = FIELD_WIDTH;
    static constexpr size_t height = FIELD_HEIGHT;
};
