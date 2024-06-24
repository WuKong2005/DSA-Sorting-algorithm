#pragma once

#include <cstring>
#include "DataGenerator.h"
#include "sortExecute.h"
#include "utility.h"

struct result {
    long long comparison{};
    std::chrono::duration<double, std::milli> timeElapsed{};
};

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