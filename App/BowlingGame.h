//
// Created by bRad on 7/9/16.
//

#ifndef APP_BOWLINGGAME_H
#define APP_BOWLINGGAME_H

#include <vector>

class BowlingGame
{
public:
    int Score(const std::vector<int>& rolls) const;

private:
    int CalculateFrameScores(const std::vector<int>& rolls, int depth) const;
};

#endif //APP_BOWLINGGAME_H
