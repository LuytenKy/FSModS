/*
Designed by LuytenKy

FSModS Ver: 2.0.0-f
*/

#include <iostream>
#include <filesystem>
#include <assert.h>
#include <windows.h>

#include "FolderHandler.h"
#include "InputHandler.h"
#include "FolderCreator.h"
#include "VectorMerge.h"

// Create a vector variable for each necessary directory
const std::vector<std::string> Directories{
    "/cache", "/cbanims", "/config", "/effects", "/fonts",
    "/hud", "/interface", "/maps", "/missions", "/models", "/music",
    "/scripts", "/sounds", "/tables", "/voice/briefing",
    "/voice/command_briefings", "/voice/debriefings", "/voice/personas",
    "/voice/special", "/voice/training"
};

// Create a vector variable for each unused directory
const std::vector<std::string> UnusedDirectories{
    "/force feedback", "/multidata", "/text", "/players", "/intelanims", "/movies", "/demos"
};

int main()
{
    bool AllowUnusedDirectories = InputHandler::AllowUnusedDirectories();
    std::string Location = InputHandler::GetModLocation();

    if (AllowUnusedDirectories) {
        auto MergedDirectories = MergeVectors(Directories, UnusedDirectories);

        // Check if the merge was successful
        if (MergedDirectories.empty()) {
            std::cerr << "Merge failed. Exiting..." << std::endl;
            Sleep(3000);
            return 1; // Indicate failure
        }

        FolderHandler::CreateModDirectory(Location, MergedDirectories);
    }
    else {
        FolderHandler::CreateModDirectory(Location, Directories);
    }

    return 0;
}