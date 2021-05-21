#include "playfield.hpp"

Playfield::Playfield(FWidget *parent, FPoint &&pos) : FWidget{parent}, pos_(pos)
{
    for (auto &i : cells) {
        for(auto &j : i) {
            j = std::nullopt;
        }
    }
}

Playfield::~Playfield()
{
}

void Playfield::initLayout()
{
    /* drawing width is 2 times as a single cell is 2*character-width in order
     * to achieve quadratic cells.
     * Also add 2 for the border to width and height
     */
    FSize size{width * 2 + 2, height + 2};
    this->setGeometry(pos_, size);
}

void Playfield::draw()
{
    setColor(FColor::Black, FColor::White);
    this->drawBorder();
    for (std::size_t i = 0; i < width; i++) {
        for (std::size_t j = 0; j < height; j++) {
            if(cells[i][j].has_value()) {
                setColor(FColor::Undefined, FColor::Blue);
                print() << FPoint{static_cast<int>(i * 2 + 2), static_cast<int>(j + 2)} << "  ";
            } else {
                setColor(FColor::LightGray, FColor::White);
                print() << FPoint{static_cast<int>(i * 2 + 2), static_cast<int>(j + 2)} << " .";
            }
        }
    }
}
