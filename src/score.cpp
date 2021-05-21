#include "score.hpp"

Score::Score(FWidget *parent, FPoint &&pos) : FWidget{parent}
{
    pos_ = pos;
}

Score::~Score()
{
}

void Score::initLayout()
{
    this->setGeometry(pos_, {width, height});
}

void Score::draw()
{
    setColor(FColor::Black, FColor::White);
    this->drawBorder();
    print() << FPoint {2, 2} 
            << FColorPair{FColor::Red, FColor::White} 
            << "Score : "
            << score_;
}
