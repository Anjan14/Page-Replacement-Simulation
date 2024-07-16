//********************************************************************
//
// RAND.cpp
//
// This file implements the Random page replacement algorithm.
//
//********************************************************************

#include "PageReplacement.h"
#include <unordered_set>
#include <vector>
#include <cstdlib>

// RAND page replacement algorithm class
class RAND : public PageReplacement {
public:
    // Simulates the RAND algorithm
    int simulate(const std::vector<int>& referenceString, int frames) override {
        std::unordered_set<int> pages;
        std::vector<int> pageVector;
        int pageFaults = 0;

        for (int page : referenceString) {
            if (pages.find(page) == pages.end()) {
                // Page fault
                if (pages.size() == frames) {
                    int randomIndex = std::rand() % pageVector.size();
                    int pageToRemove = pageVector[randomIndex];
                    pages.erase(pageToRemove);
                    pageVector.erase(pageVector.begin() + randomIndex);
                }
                pages.insert(page);
                pageVector.push_back(page);
                pageFaults++;
            }
        }

        return pageFaults;
    }
};

// Update factory function implementation for creating algorithm instances
PageReplacement* createPageReplacementAlgorithm(const std::string& algorithmName) {
    if (algorithmName == "FIFO") {
        return new FIFO();
    } else if (algorithmName == "LRU") {
        return new LRU();
    } else if (algorithmName == "OPT") {
        return new OPT();
    } else if (algorithmName == "RAND") {
        return new RAND();
    }
    return nullptr;
}
