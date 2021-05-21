#pragma once

#include <final/final.h>

using namespace finalcut;

class Score final : public FWidget {
public:
    Score(FWidget *parent, FPoint &&pos);
    ~Score();

    /* add _points_ to total score and return new score */
    unsigned int addScore(unsigned int points);

    void initLayout() override;
    void draw() override;

    FLabel text{"score:", this};

private:
    unsigned int score_ = 0;
    FPoint pos_;

    static constexpr std::size_t width = 16;
    static constexpr std::size_t height = 3;
};
