/*
Designed by LuytenKy

FSModS Ver: 2.0.2-f
*/

#include <filesystem>
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#endif

bool AllDirectoriesOkay = true;

namespace fs = std::filesystem;

bool CreateFolders(const std::string& location, const std::vector<std::string>& directories) {
    bool allDirectoriesOkay = true;

    for (const auto& directory : directories) {
        fs::path absolutePath = fs::absolute(location + directory);

        try {
            // Create intermediate directories if they don't exist
            if (!fs::exists(absolutePath.parent_path())) {
                fs::create_directories(absolutePath.parent_path());
            }

            // Now create the final directory
            if (fs::create_directory(absolutePath)) {
                std::cout << "Directory created: " << absolutePath << std::endl;
            }
            else {
                std::cerr << "Failed to create directory: " << absolutePath << std::endl;
                allDirectoriesOkay = false;
            }
        }
        catch (const fs::filesystem_error& ex) {
            std::cerr << "Filesystem error: " << ex.what() << std::endl;
            allDirectoriesOkay = false;
        }
    }

    return allDirectoriesOkay;
}

void CheckIfAllDirectoriesOkay(bool allDirectoriesOkay) {
    if (allDirectoriesOkay) {
        std::cout << "All directories were successfully generated." << std::endl;
    }
    else {
        std::cerr << "Some directories failed to be generated. Either they were already present." << std::endl;
    }

    std::cout << "Press Enter to continue...";
    // Platform-independent way to wait for user input
#ifdef _WIN32
    _getch(); // Use _getch() on Windows
#else
    std::getchar(); // Use getchar() on non-Windows platforms
#endif
}
