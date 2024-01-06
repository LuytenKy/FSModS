/*
Designed by LuytenKy

FSModS Ver: 1.0.4-f
*/

#include <iostream>
#include "FolderHandler.h"
#include "InputHandler.h"

int main()
{
    // Startup the app
    std::string Location = InputHandler::GetModLocation();
    // Create the directories
    FolderHandler::CreateModDirectory(Location);

    return 0;
}
