#include <fstream>
#include "DataGenerator.h"
#include "sortExecute.h"
#include "utility.h"
#include <cstring>

const bool debug = true;
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
    std::ofstream fout("outputExamine.txt");
    executeSort sortAlgo;

    for (int inputOrderID = 0; inputOrderID < NUMBER_DATA_ORDER; inputOrderID++) {
        for (int inputSizeID = 0; inputSizeID < NUMBER_DATA_TEST; inputSizeID++) {
            int n = DATA_SIZE[inputSizeID] / (debug ? 100 : 1);
            int* arr = new int[n];
            int* tmp = new int[n];
            result test;
            GenerateData(arr, n, inputOrderID);

            if (writingToFile) {
                fout << "Input size : " << n << "\n";
                fout << "Input order: " << getInputOrderName(inputOrderID) << '\n';
                fout << '\n';
            }
            for (int algorithmID = 0; algorithmID < NUMBER_SORT_ALGORITHM; algorithmID++) {
                memcpy(tmp, arr, n * sizeof(int));
                sortAlgo.sort(tmp, n, algorithmID, test.timeElapsed);

                memcpy(tmp, arr, n * sizeof(int));
                sortAlgo.sort(tmp, n, algorithmID, test.comparison);
                if (writingToFile) {
                    fout << "Algorithm: " << sortAlgo.getAlgorithmName(algorithmID) << '\n';
                    if (typeMeasure & 1) {
                        fout << "Running time: " << test.timeElapsed.count() << '\n';
                    }
                    if (typeMeasure & 2) {
                        fout << "Comparisons : " << test.comparison << '\n';
                    }
                    fout << "-----------------------------------\n";
                }
            }
            fout << "\n";
            delete [] arr;
            delete [] tmp;
        }
    }

    fout.close();
    return 0;
}