#include <iostream>
#include <vector>
#include <chrono>
#include "Player.h"
#include "mergesort.h"
#include "quicksort.h"
#include "data.h"
#include "leaderboard.h"

int main() {
    int choice = 0;
    std::vector<Player> currentData;

    while (choice != 6) { //Ensures that the menu keeps showing until the user chooses to exit
        std::cout << "\n----------- MENU -----------\n";
        std::cout << "* Select one option *\n";
        std::cout << "1. Generate Leaderboard Data\n";
        std::cout << "2. Display\n";
        std::cout << "3. Sort using Merge\n";
        std::cout << "4. Sort using Quick\n";
        std::cout << "5. Compare\n";
        std::cout << "6. Exit\n";
        std::cout << "----------------------------\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int size;
                std::cout << "Enter number of players to generate: ";
                std::cin >> size;

                std::cout << "[Action: Generating " << size << " players...]\n";
                currentData = generateData(size);
                break;
            }
            case 2:
                if (currentData.empty()) {
                    std::cout << "No data to display. Please generate data first.\n";
                } else {
                    std::cout << "[Action: Displaying Data...]\n";
                    printLeaderboard(currentData, 10); // Display top 10
                }
                break;
            case 3:
                if (currentData.empty()) {
                    std::cout << "No data to sort. Please generate data first.\n";
                } else {
                    std::cout << "[Action: Running Merge Sort...]\n";
                    mergesort(currentData, 0, currentData.size() - 1);
                }
                break;
            case 4:
                if (currentData.empty()) {
                    std::cout << "No data to sort. Please generate data first.\n";
                } else {
                    std::cout << "[Action: Running Quick Sort...]\n";
                    quickSort(currentData, 0, currentData.size() - 1);
                }
                break;
            case 5:
                if (currentData.empty()) {
                    std::cout << "No data to compare. Please generate data first.\n";
                } else {
                    std::cout << "[Action: Running Both & Comparing Times...]\n";

                    std::vector<Player> mergeTest = currentData;
                    std::vector<Player> quickTest = currentData;

                    auto startQuick = std::chrono::high_resolution_clock::now();
                    quickSort(quickTest, 0, quickTest.size() - 1);
                    auto endQuick = std::chrono::high_resolution_clock::now();
                    auto quickDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endQuick - startQuick);

                    auto startMerge = std::chrono::high_resolution_clock::now();
                    mergesort(mergeTest, 0, mergeTest.size() - 1);
                    auto endMerge = std::chrono::high_resolution_clock::now();
                    auto mergeDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endMerge - startMerge);

                    std::cout << "\n=== RESULTS ===\n";
                    std::cout << "Merge Sort Time: " << mergeDuration.count() << " ns\n";
                    std::cout << "Quick Sort Time: " << quickDuration.count() << " ns\n";
                }
                break;
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
