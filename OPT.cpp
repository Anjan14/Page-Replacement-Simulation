//********************************************************************
//
// OPT.cpp
//
// This file implements the Optimal page replacement algorithm.
//
//********************************************************************

#include "PageReplacement.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// OPT page replacement algorithm class
class OPT : public PageReplacement {
public:
    // Simulates the OPT algorithm
    int simulate(const std::vector<int>& referenceString, int frames) override {
        std::unordered_set<int> pages;
        std::unordered_map<int, int> futureUse;
        int pageFaults = 0;

        for (size_t i = 0; i < referenceString.size(); ++i) {
            int page = referenceString[i];
            if (pages.find(page) == pages.end()) {
                // Page fault
                if (pages.size() == frames) {
                    int farthest = i;
                    int pageToRemove = -1;
                    for (int p : pages) {
                        auto it = std::find(referenceString.begin() + i + 1, referenceString.end(), p);
                        int index = it == referenceString.end() ? referenceString.size() : it - referenceString.begin();
                        if (index > farthest) {
                            farthest = index;
                            pageToRemove = p;
                        }
                    }
                    pages.erase(pageToRemove);
                }
                pages.insert(page);
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
    }
    // Add other algorithms here
    return nullptr;
}
