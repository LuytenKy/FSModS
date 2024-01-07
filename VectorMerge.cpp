/*
Designed by LuytenKy

FSModS Ver: 2.0.2-f
*/

#include <iostream>
#include <filesystem>

#include "VectorMerge.h"

auto MergeVectors(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) -> std::vector<std::string> {
    std::vector<std::string> MergedVector = vec1;

    try {
        // Attempt to merge vectors
        MergedVector.insert(MergedVector.end(), vec2.begin(), vec2.end());
    }
    catch (const std::exception& e) {
        // Handle exceptions (e.g., if vec2 is too large to fit in memory)
        std::cerr << "Error merging vectors: " << e.what() << std::endl;
        // Return an empty vector to indicate failure
        return std::vector<std::string>();
    }

    // Return the merged vector
    return MergedVector;
}