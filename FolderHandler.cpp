/*
Designed by LuytenKy

FSModS Ver: 1.0.0-f
*/

#include "FolderHandler.h"
#include <filesystem>
#include <iostream>
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

            if (fs::create_directory(absolutePath)) {
                std::cout << "Directory created: " << absolutePath << std::endl;
            }
            else {
                std::cerr << "Failed to create directory: " << absolutePath << std::endl;
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
        std::cin.get();
    }
}
