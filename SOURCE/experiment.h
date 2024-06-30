#pragma once

#include <cstring>
#include "DataGenerator.h"
#include "sortExecute.h"
#include "utility.h"

// Struct to hold the results of sorting, including comparison count and time elapsed
struct result {
    long long comparison{};
    std::chrono::duration<double, std::milli> timeElapsed{};
};

// Struct to manage sorting experiments
struct experiment {
    std::string inpPath;
    std::string outPath;
    std::string algoName[2];
    int inputSize;
    int inputOrder;
    int typeMeasure;
    int numTest;
    bool isComparisonMode;
    bool testAllDataType;
    bool readInputFromFile;
    executeSort sortAlgo;
    int** arrayInput;
    result* listResult;
    
    experiment();
    ~experiment();

    void readCommand(int argc, char** argv);
    void startExperiment();
    void algorithmMode();
    void comparisonMode();
    void printResult();
};