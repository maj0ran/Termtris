#pragma once

#include <final/final.h>

#include "playfield.hpp"
#include "score.hpp"

using namespace finalcut;

class Tetris final : public FDialog {
public:
    Tetris(FWidget *parent);
    ~Tetris();

    void initLayout() override;
    void draw() override;

private:
    Playfield playfield {this, {25, 4}};
    Score score         {this, {2, 4}};
};
