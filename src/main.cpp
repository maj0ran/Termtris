#include <iostream>

#include <final/final.h>

#include "playfield.hpp"
#include "tetris.hpp"

int main(int argc, char **argv)
{
    FApplication app(argc, argv);
    Tetris *tetris = new Tetris(&app);

    tetris->show();
    return app.exec();
}
