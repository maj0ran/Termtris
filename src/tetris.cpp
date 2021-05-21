#include "tetris.hpp"

#include <iostream>

Tetris::Tetris(FWidget *parent) : FDialog{parent}
{
    FWidget::setMainWidget(this);
}

Tetris::~Tetris()
{
}

void Tetris::initLayout()
{
    this->setText("Termtris");
    this->setGeometry({1, 1}, {60, 40});
    FDialog::initLayout();
}

void Tetris::draw()
{
    FDialog::draw();
}
