/*
Designed by LuytenKy

FSModS Ver: 1.0.0-f
*/

#pragma once

#include <string>

namespace FolderHandler {
    void CreateModDirectory(const std::string ModFileLoc);
    bool CheckModDirectories(const std::string ModFileLoc);
}