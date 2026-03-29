#include <iostream>
#include <iomanip>
#include <vector>
#include "Player.h"

void printLeaderboard(const std::vector<Player>& leaderboard, int topN) {
    std::cout << "\n==========================================\n";
    std::cout << "               LEADERBOARD                \n";
    std::cout << "==========================================\n";

    std::cout << std::left
              << std::setw(8) << "Rank" << "| "
              << std::setw(20) << "Player Name" << "| "
              << "Score\n";
    std::cout << "------------------------------------------\n";

    int limit = std::min(topN, static_cast<int>(leaderboard.size()));

    for (int i = 0; i < limit; ++i) {
        std::cout << std::left
                  << std::setw(8) << (i + 1) << "| "
                  << std::setw(20) << leaderboard[i].PlayerName << "| "
                  << leaderboard[i].Score << "\n";
    }
    std::cout << "------------------------------------------\n";
}
