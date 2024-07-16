//********************************************************************
//
// LRU.cpp
//
// This file implements the LRU page replacement algorithm.
//
//********************************************************************

#include "PageReplacement.h"
#include <list>
#include <unordered_map>

// LRU page replacement algorithm class
class LRU : public PageReplacement {
public:
    // Simulates the LRU algorithm
    int simulate(const std::vector<int>& referenceString, int frames) override {
        std::list<int> pages;
        std::unordered_map<int, std::list<int>::iterator> pageMap;
        int pageFaults = 0;

        for (int page : referenceString) {
            auto it = pageMap.find(page);
            if (it == pageMap.end()) {
                // Page fault
                if (pages.size() == frames) {
                    int removed = pages.back();
                    pages.pop_back();
                    pageMap.erase(removed);
                }
                pages.push_front(page);
                pageMap[page] = pages.begin();
                pageFaults++;
            } else {
                // Move the accessed page to the front
                pages.erase(it->second);
                pages.push_front(page);
                pageMap[page] = pages.begin();
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
    }
    // Add other algorithms here
    return nullptr;
}
