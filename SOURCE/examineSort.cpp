#include <fstream>
#include <cstring>
#include <iomanip>
#include "DataGenerator.h"
#include "sortExecute.h"
#include "utility.h"

bool debug = false;
const int NUMBER_DATA_TEST = 6;
int const DATA_SIZE[] = {10000, 30000, 50000, 100000, 300000, 500000};

// Struct to hold the results of sorting, including comparison count and time elapsed
struct result
{
    long long comparison{};
    std::chrono::duration<double, std::milli> timeElapsed{};
};

int main(int argc, char** argv) 
{
    if (argc == 2 && strcmp(argv[1], "-debug") == 0) {
        debug = true;
    }  

    srand(time(NULL));
    std::ofstream fout("result.csv");
    executeSort sortAlgo;

    fout << "Input order,Input size,Algorithm,Running time,Comparisons\n";

    for (int inputOrderID = 0; inputOrderID < NUMBER_DATA_ORDER; inputOrderID++)
    {
        for (int inputSizeID = 0; inputSizeID < NUMBER_DATA_TEST; inputSizeID++)
        {
            int n = DATA_SIZE[inputSizeID] / (debug ? 10 : 1);
            int *arr = new int[n];
            int *tmp = new int[n];
            result test;
            GenerateData(arr, n, inputOrderID);

            for (int algorithmID = 0; algorithmID < NUMBER_SORT_ALGORITHM; algorithmID++) {
                memcpy(tmp, arr, n * sizeof(int));
                sortAlgo.sort(tmp, n, algorithmID, test.comparison);

                memcpy(tmp, arr, n * sizeof(int));
                sortAlgo.sort(tmp, n, algorithmID, test.timeElapsed);

                fout << getInputOrderName(inputOrderID) << ',' << n << "," << sortAlgo.getAlgorithmName(algorithmID) << ',';
                fout << std::setprecision(15) << test.timeElapsed.count() << ',' << test.comparison << '\n';
            }
            delete[] arr;
            delete[] tmp;
        }
    }

    fout.close();
}