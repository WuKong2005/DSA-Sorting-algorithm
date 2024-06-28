#include "sortExecute.h"

// Constructor to initialize algorithm names and function pointers
executeSort::executeSort()
{
    algorithmName[0] = "bubble-sort";
    algorithmName[1] = "insertion-sort";
    algorithmName[2] = "selection-sort";
    algorithmName[3] = "shaker-sort";
    algorithmName[4] = "shell-sort";
    algorithmName[5] = "heap-sort";
    algorithmName[6] = "merge-sort";
    algorithmName[7] = "quick-sort";
    algorithmName[8] = "counting-sort";
    algorithmName[9] = "radix-sort";
    algorithmName[10] = "flash-sort";

    pSort[0] = bubbleSort;
    pSort[1] = insertionSort;
    pSort[2] = selectionSort;
    pSort[3] = shakerSort;
    pSort[4] = shellSort;
    pSort[5] = heapSort;
    pSort[6] = mergeSort;
    pSort[7] = quickSort;
    pSort[8] = countingSort;
    pSort[9] = radixSort;
    pSort[10] = flashSort;

    pSortWithComparison[0] = bubbleSort;
    pSortWithComparison[1] = insertionSort;
    pSortWithComparison[2] = selectionSort;
    pSortWithComparison[3] = shakerSort;
    pSortWithComparison[4] = shellSort;
    pSortWithComparison[5] = heapSort;
    pSortWithComparison[6] = mergeSort;
    pSortWithComparison[7] = quickSort;
    pSortWithComparison[8] = countingSort;
    pSortWithComparison[9] = radixSort;
    pSortWithComparison[10] = flashSort;
}

// Destructor
executeSort::~executeSort()
{
}

// Function to get the algorithm ID based on its name
int executeSort::getAlgorithmID(std::string algoName)
{
    return std::find(algorithmName, algorithmName + NUMBER_SORT_ALGORITHM, algoName) - algorithmName;
}

// Function to get the algorithm name based on its ID
std::string executeSort::getAlgorithmName(int algorithmID)
{
    return algorithmName[algorithmID];
}

// Function to sort an array and measure the time taken
void executeSort::sort(int arr[], int n, int algorithmID, std::chrono::duration<double, std::micro> &timeElapsed)
{
    if (algorithmID == NUMBER_SORT_ALGORITHM)
    {
        return;
    }

    const auto timeStart = std::chrono::steady_clock::now();
    pSort[algorithmID](arr, n);
    const auto timeEnd = std::chrono::steady_clock::now();
    timeElapsed = timeEnd - timeStart;

    assert(std::is_sorted(arr, arr + n));
}

// Function to sort an array and count the number of comparisons
void executeSort::sort(int arr[], int n, int algorithmID, long long &comparison)
{
    if (algorithmID == NUMBER_SORT_ALGORITHM)
    {
        return;
    }

    comparison = 0;
    pSortWithComparison[algorithmID](arr, n, comparison);

    assert(std::is_sorted(arr, arr + n));
}
