#include <iostream>
#include <vector>
#include "Player.h"

void displayMenu() {
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
            case 1:
                std::cout << "[Action: Generating Data...]\n";
                break;
            case 2:
                std::cout << "[Action: Displaying Data...]\n";
                break;
            case 3:
                std::cout << "[Action: Running Merge Sort...]\n";
                break;
            case 4:
                std::cout << "[Action: Running Quick Sort...]\n";
                break;
            case 5:
                std::cout << "[Action: Running Both & Comparing Times...]\n";
                break;
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
