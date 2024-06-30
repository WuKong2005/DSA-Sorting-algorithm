#pragma once

#include <algorithm>
#include <string>
#include <chrono>
#include <assert.h>

#include "algorithm/bubbleSort.h"
#include "algorithm/countingSort.h"
#include "algorithm/flashSort.h"
#include "algorithm/heapSort.h"
#include "algorithm/insertionSort.h"
#include "algorithm/mergeSort.h"
#include "algorithm/quickSort.h"
#include "algorithm/radixSort.h"
#include "algorithm/selectionSort.h"
#include "algorithm/shakerSort.h"
#include "algorithm/shellSort.h"

// Define the number of sorting algorithms
int const NUMBER_SORT_ALGORITHM = 11;

// Enum to represent sorting algorithm IDs
enum ALGORITHM_ID
{
    BUBBLE_SORT,
    INSERTION_SORT,
    SELECTION_SORT,
    SHAKER_SORT,
    SHELL_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT,
    COUNTING_SORT,
    RADIX_SORT,
    FLASH_SORT
};

// Struct to hold sorting function pointers and their corresponding names
struct executeSort
{
    std::string algorithmName[NUMBER_SORT_ALGORITHM];
    void (*pSort[NUMBER_SORT_ALGORITHM])(int arr[], int n);
    void (*pSortWithComparison[NUMBER_SORT_ALGORITHM])(int arr[], int n, long long &comparison);

    executeSort();
    ~executeSort();

    int getAlgorithmID(std::string algoName);
    std::string getAlgorithmName(int algorithmID);
    void sort(int arr[], int n, int algorithmID, std::chrono::duration<double, std::micro> &timeElapsed);
    void sort(int arr[], int n, int algorithmID, long long &comparison);
};