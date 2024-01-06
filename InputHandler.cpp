/*
Designed by LuytenKy

FSModS Ver: 1.0.4-f
*/

#include "InputHandler.h"
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <sstream>
namespace fs = std::filesystem;

void ClearConsoleScreen() {
    system("cls");
}

void FSModSInterfaceInit() {
    std::cout << "========================================" << std::endl;
    std::cout << "   FreeSpaceModStarter 1.0.4-f" << std::endl;
    std::cout << "   Designed by LuytenKy" << std::endl;
    std::cout << "========================================" << std::endl;
}

namespace InputHandler {
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
