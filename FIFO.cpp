//********************************************************************
//
// FIFO.cpp
//
// This file implements the FIFO page replacement algorithm.
//
//********************************************************************

#include "PageReplacement.h"
#include <queue>
#include <unordered_set>

// FIFO page replacement algorithm class
class FIFO : public PageReplacement {
public:
    // Simulates the FIFO algorithm
    int simulate(const std::vector<int>& referenceString, int frames) override {
        std::queue<int> pages;
        std::unordered_set<int> pageSet;
        int pageFaults = 0;

        for (int page : referenceString) {
            if (pageSet.find(page) == pageSet.end()) {
                // Page fault
                if (pages.size() == frames) {
                    int removed = pages.front();
                    pages.pop();
                    pageSet.erase(removed);
                }
                pages.push(page);
                pageSet.insert(page);
                pageFaults++;
            }
        }

        return pageFaults;
    }
};

// Factory function implementation for creating algorithm instances
PageReplacement* createPageReplacementAlgorithm(const std::string& algorithmName) {
    if (algorithmName == "FIFO") {
        return new FIFO();
    }
    // Add other algorithms here
    return nullptr;
}
