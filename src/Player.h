#pragma once
#include <string>
struct Player {
    std::string PlayerName;
    int Score;
    int Rank;

    Player() : PlayerName(), Score(0), Rank(0) {}
    Player(const std::string& name, int score) : PlayerName(name), Score(score), Rank(0) {}
    std::string getName() const { return PlayerName; }
    int getScore() const { return Score; }
    int getRank() const { return Rank; }
};
