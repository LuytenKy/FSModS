#include "FolderHandler.h"
#include <filesystem>
#include <iostream>

// Platform-independent method to wait for user input
#ifdef _WIN32
#include <conio.h>
#else
#include <cstdio>
#endif

namespace fs = std::filesystem;

namespace FolderHandler {
    void CreateModDirectory(const std::string ModFileLoc) {
        // List of directories to generate
        const std::vector<std::string> directories = {
            "/cache", "/cbanims", "/config", "/effects", "/fonts",
            "/hud", "/interface", "/maps", "/missions", "/models", "/music",
            "/scripts", "/sounds", "/tables", "/voice/briefing",
            "/voice/command_briefings", "/voice/debriefings", "/voice/personas",
            "/voice/special", "/voice/training"
        };
        // Certain directories that aren't really needed
#ifdef AllowUnusedDirectories
        directories.insert(directories.end(), {
            "/force feedback", "/multidata", "/text", "/players", "/intelanims", "/movies", "/demos"
            });
#endif

        bool allDirectoriesOkay = true;

        for (const auto& directory : directories) {
            fs::path absolutePath = fs::absolute(ModFileLoc + directory);

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

        if (allDirectoriesOkay) {
            std::cout << "All directories were successfully generated." << std::endl;
        }
        else {
            std::cerr << "Some directories failed to be generated." << std::endl;
        }

        std::cout << "Press Enter to continue...";
        // Platform-independent way to wait for user input
#ifdef _WIN32
        _getch(); // Use _getch() on Windows
#else
        std::getchar(); // Use getchar() on non-Windows platforms
#endif
        }
    }

