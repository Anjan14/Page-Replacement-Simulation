//********************************************************************
//
// Name: Anjan Roy
// CSC 360: Operating Systems
// Programming Project #5: Simulation of Page Replacement Strategies
// Date: July 14, 2024
// Instructor: Dr. Siming Liu
//
//********************************************************************

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "PageReplacement.h"

int main() {
    std::string line;
    std::vector<int> referenceString;
    int frames;

    // Read page reference string
    std::getline(std::cin, line);
    std::istringstream refStream(line);
    int page;
    while (refStream >> page) {
        referenceString.push_back(page);
    }

    // Read number of frames
    std::cin >> frames;
    std::cin.ignore();

    // Read algorithms and run simulations
    while (std::getline(std::cin, line)) {
        PageReplacement* algorithm = createPageReplacementAlgorithm(line);
        if (algorithm) {
            int pageFaults = algorithm->simulate(referenceString, frames);
            std::cout << line << ": " << pageFaults << std::endl;
            delete algorithm;
        }
    }

    return 0;
}
