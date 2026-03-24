#pragma once
#include <string>

struct Player {
    std::string PlayerName;
    int Score;

    Player() : PlayerName(), Score(0) {}
    Player(const std::string& name, int score) : PlayerName(name), Score(score) {}
    std::string getName() const { return PlayerName; }
    int getScore() const { return Score; }
};
