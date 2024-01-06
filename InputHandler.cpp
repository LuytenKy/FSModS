/*
Designed by LuytenKy

FSModS Ver: 2.0.0-f
*/

#include <iostream>
#include <windows.h>
#include <filesystem>
#include <sstream>
#include <set>

#include "InputHandler.h"

namespace fs = std::filesystem;

void ClearConsoleScreen() {
    system("cls");
}

void FSModSInterfaceInit() {
    std::cout << "========================================" << std::endl;
    std::cout << "   FreeSpaceModStarter 2.0.0-f" << std::endl;
    std::cout << "   Designed by LuytenKy" << std::endl;
    std::cout << "========================================" << std::endl;
}

namespace InputHandler {
    bool AllowUnusedDirectories() {
        std::string Answer;
        FSModSInterfaceInit();

        std::cout << "Allow unused directories? (y for Yes, n for No)" << std::endl;
        std::cin >> Answer;

        if (Answer == "y" || Answer == "Y") {
            return true;
        }
        else if (Answer == "n" || Answer == "N") {
            return false;
        }
        else {
            std::cerr << "Invalid input! Please enter either 'y' or 'n'. Set to false!" << std::endl;
            Sleep(3000);
            ClearConsoleScreen();
            return false;
        }
    }

    std::string GetModLocation() {
        std::string Location;
        bool isValid = false;

        do {
            // Clear the console and initilize interface
            ClearConsoleScreen();
            FSModSInterfaceInit();

            std::cout << "Enter mod location: " << std::endl;

            // Read the entire line of input
            std::getline(std::cin, Location);

            // Check if the entered location is valid
            if (fs::is_directory(Location)) {
                isValid = true;
            }
            else {
                std::cout << "Invalid mod location. Please enter a valid directory." << std::endl;
                isValid = false;
            }

        } while (!isValid);

        return Location;
    }
}