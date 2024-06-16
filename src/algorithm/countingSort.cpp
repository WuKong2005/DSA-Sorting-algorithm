#include "countingSort.h"

void countingSort(int arr[], int n, long long &comparison) {
    
}

void countingSort(int arr[], int n) {
    int maxSize = *std::max_element(arr, arr + n);

    int* frequent = new int[maxSize + 1]{};

    for (int i = 0; i < n; i++) {
        ++frequent[arr[i]];
    }

    for (int value = 1; value <= maxSize; value++) {
        frequent[value] += frequent[value - 1];
    }

    int* tmp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        tmp[frequent[arr[i]] - 1] = arr[i];
        --frequent[arr[i]];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }

    delete [] frequent;
    delete [] tmp;

    return;
}