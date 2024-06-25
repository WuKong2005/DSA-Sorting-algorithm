#include "experiment.h"

experiment::experiment() {
    inpPath = "input.txt";
    outPath = "output.txt";
    algoName[0] = algoName[1] = "";
    inputSize = typeMeasure = numTest = isComparisonMode = testAllDataType = readInputFromFile = false;
    inputOrder = NUMBER_DATA_ORDER;
    
    arrayInput = new int*[NUMBER_DATA_ORDER];
    for (int i = 0; i < NUMBER_DATA_ORDER; i++) {
        arrayInput[i] = nullptr;
    }
    listResult = new result[NUMBER_DATA_ORDER];
}

experiment::~experiment() {
    for (int i = 0; i < NUMBER_DATA_ORDER; i++) {
        delete [] arrayInput[i];
        arrayInput[i] = nullptr;
    }

    delete [] arrayInput;
    delete [] listResult;
}

void experiment::readCommand(int argc, char **argv) {
    if (strcmp(argv[1], "-a") == 0) {
        //ALGORITHM MODE

        algoName[0] = argv[2];
        if (!isValidNumber(argv[3])) { 
            // Command 1
            numTest = 1;
            readInputFromFile = true;
            inpPath = argv[3];
            readFile(arrayInput[0], inputSize, inpPath.c_str());
            typeMeasure = getTypeMeasure(argv[4]);
        }
        else {
            inputSize = std::stoi(argv[3]);
            if (argc == 6) {  
                // Command 2
                numTest = 1;
                inputOrder = getInputOrder(argv[4]);
                arrayInput[0] = new int[inputSize];
                GenerateData(arrayInput[0], inputSize, inputOrder);
                writeFile(arrayInput[0], inputSize, "input.txt");
            }
            else {
                // Command 3
                testAllDataType = true;
                numTest = NUMBER_DATA_ORDER;

                for (int inputOrderID = 0; inputOrderID < NUMBER_DATA_ORDER; inputOrderID++) {
                    arrayInput[inputOrderID] = new int[inputSize];
                    GenerateData(arrayInput[inputOrderID], inputSize, inputOrderID);
                    std::string inp = "input__.txt";
                    inp[6] = inputOrderID + 1 + '0';
                    writeFile(arrayInput[inputOrderID], inputSize, inp);
                }
            }
            typeMeasure = getTypeMeasure(argv[argc - 1]);
        }
    } 
    else {
        numTest = 2;
        isComparisonMode = true;
        typeMeasure = 3;
        algoName[0] = argv[2];
        algoName[1] = argv[3];
        if (argc == 5) { 
            // Command 4
            readInputFromFile = true;
            inpPath = argv[4];
            readFile(arrayInput[0], inputSize, inpPath.c_str());
        }
        else { 
            // Command 5
            inputSize = std::stoi(argv[4]);
            inputOrder = getInputOrder(argv[5]);
            arrayInput[0] = new int[inputSize];
            GenerateData(arrayInput[0], inputSize, inputOrder);
            writeFile(arrayInput[0], inputSize, "input.txt");
        }
    }
}

void experiment::startExperiment() {
    if (!isComparisonMode) 
        algorithmMode();
    else
        comparisonMode();
}

void experiment::algorithmMode() {
    int* tmp = new int[inputSize];

    int ID = sortAlgo.getAlgorithmID(algoName[0]);

    // numTest = 1 or numTest = 4
    for (int i = 0; i < numTest; i++) {
        memcpy(tmp, arrayInput[i], inputSize * sizeof(int));
        sortAlgo.sort(tmp, inputSize, ID, listResult[i].comparison);

        memcpy(tmp, arrayInput[i], inputSize * sizeof(int));
        sortAlgo.sort(tmp, inputSize, ID, listResult[i].timeElapsed);
    }

    if (!testAllDataType) {
        writeFile(tmp, inputSize, "output.txt");
    }

    delete [] tmp;
    
}

void experiment::comparisonMode() {
    int* tmp = new int[inputSize];
    for (int i = 0; i < 2; i++) {
        int ID = sortAlgo.getAlgorithmID(algoName[i]);

        memcpy(tmp, arrayInput[0], inputSize * sizeof(int));
        sortAlgo.sort(tmp, inputSize, ID, listResult[i].comparison);

        memcpy(tmp, arrayInput[0], inputSize * sizeof(int));
        sortAlgo.sort(tmp, inputSize, ID, listResult[i].timeElapsed);
    }

    delete [] tmp;
}

void experiment::printResult() {
    std::cout << "Input file : " << inpPath << '\n';
    std::cout << "Input size : " << inputSize << '\n';
    if (inputOrder != NUMBER_DATA_ORDER) {
        std::cout << "Input order: " << getInputOrderName(inputOrder) << '\n';
    }
    std::cout << "-----------------------------------\n";

    if (!testAllDataType) {
        for (int i = 0; i < 2; i++) {
            if (!algoName[i].size()) continue;
            std::cout << "Algorithm: " << algoName[i] << '\n';
            if (typeMeasure & 1) {
                std::cout << "Running time: " << listResult[i].timeElapsed.count() << '\n';
            }
            if (typeMeasure & 2) {
                std::cout << "Comparisons : " << listResult[i].comparison << '\n';
            }
            std::cout << "-----------------------------------\n";
        }
    }
    else {
        for (int inputOrderID = 0; inputOrderID < numTest; inputOrderID++) {
            std::cout << "Input order: " << getInputOrderName(inputOrderID) << '\n';
            std::cout << "-----------------------------------\n";
            if (typeMeasure & 1) {
                std::cout << "Running time: " << listResult[inputOrderID].timeElapsed.count() << '\n';
            }
            if (typeMeasure & 2) {
                std::cout << "Comparisons : " << listResult[inputOrderID].comparison << '\n';
            }
            std::cout << '\n';
        }
    }
}
