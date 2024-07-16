//********************************************************************
//
// PageReplacement.h
//
// This header file defines the PageReplacement abstract base class
// and a factory function for creating page replacement algorithm
// instances.
//
//********************************************************************

#ifndef PAGEREPLACEMENT_H
#define PAGEREPLACEMENT_H

#include <vector>
#include <string>

// Abstract base class for page replacement algorithms
class PageReplacement {
public:
    // Pure virtual function to simulate the algorithm
    virtual int simulate(const std::vector<int>& referenceString, int frames) = 0;
    virtual ~PageReplacement() = default;
};

// Factory function to create instances of page replacement algorithms
PageReplacement* createPageReplacementAlgorithm(const std::string& algorithmName);

#endif // PAGEREPLACEMENT_H
