#include <fstream>
#include "DataGenerator.h"
#include "sortExecute.h"
#include "utility.h"
#include <cstring>
#include <iomanip>

const bool debug = false;
const bool writingToFile = true;
const int typeMeasure = 3;

const int NUMBER_DATA_TEST = 6;
int const DATA_SIZE[] = {10000, 30000, 50000, 100000, 300000, 500000};

struct result {
    long long comparison{};
    std::chrono::duration<double, std::micro> timeElapsed{};
};

int main() {
    srand(time(NULL));
    // std::ofstream fout("outputExamine.txt");
    std::ofstream fout("outputReverseC.csv",std::ios::app);
    executeSort sortAlgo;

    for (int inputOrderID = 3; inputOrderID < NUMBER_DATA_ORDER; inputOrderID++) {
        for (int inputSizeID = 0; inputSizeID < NUMBER_DATA_TEST-3; inputSizeID++) {
            int n = DATA_SIZE[inputSizeID] / (debug ? 100 : 1);
            int* arr = new int[n];
            int* tmp = new int[n];
            result test;
            GenerateData(arr, n, inputOrderID);

            if (writingToFile) {
                fout << "\nInput size : " << n << ";\n";
                // fout << "Input order: " << getInputOrderName(inputOrderID) << '\n';
                // fout << ";\n";
            }
            for (int algorithmID = 0; algorithmID < 11; algorithmID++) {
                // memcpy(tmp, arr, n * sizeof(int));
                // sortAlgo.sort(tmp, n, algorithmID, test.timeElapsed);
                
                memcpy(tmp, arr, n * sizeof(int));
                sortAlgo.sort(tmp, n, algorithmID, test.comparison);
                std::cout << sortAlgo.getAlgorithmName(algorithmID) << "\n";
                if (writingToFile) {
                    fout << sortAlgo.getAlgorithmName(algorithmID) << ";";
                    fout << std::setprecision(12) << test.comparison << ";\n";
                    // fout << "Algorithm: " << sortAlgo.getAlgorithmName(algorithmID) << '\n';
                    // if (typeMeasure & 1) {
                    //     fout << "Running time: " << test.timeElapsed.count() << '\n';
                    // }
                    // if (typeMeasure & 2) {
                    //     fout << "Comparisons : " << test.comparison << '\n';
                    // }
                    // fout << "-----------------------------------\n";
                // }
                }
            }
            std::cout << "\n";
            fout << ";\n";
            delete [] arr;
            delete [] tmp;
        }
        fout << ";\n";
    }
    fout.close();
    return 0;
}