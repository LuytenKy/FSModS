/*
Designed by LuytenKy

FSModS Ver: 2.0.0-f
*/

#include <filesystem>
#include <iostream>

#include "FolderHandler.h"
#include "FolderCreator.h"

namespace fs = std::filesystem;

namespace FolderHandler {
    void CreateModDirectory(const std::string Location, const std::vector<std::string>& Directory) {
        bool AllDirectoriesOkay = CreateFolders(Location, Directory);
        CheckIfAllDirectoriesOkay(AllDirectoriesOkay);
    }
}