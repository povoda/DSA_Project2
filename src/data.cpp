#include <vector>
#include <string>
#include <random>
#include "Player.h"

std::vector<Player> generateData(int numPlayers) {
    std::vector<Player> leaderboard;
    leaderboard.reserve(numPlayers);
    // Pre-allocates memory in the vector to establish a fixed capacity which improves performance

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> scoreDist(0, 99999);
    // Random number generator setup to create scores between 0 and 99,999

    for (int i = 0; i < numPlayers; ++i) {
        Player p;
        p.PlayerName = "Player" + std::to_string(i + 1);
        p.Score = scoreDist(gen);
        p.Rank = 0;
        leaderboard.push_back(p);
    }

    return leaderboard;
}
