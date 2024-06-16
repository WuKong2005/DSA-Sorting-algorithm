#include "radixSort.h"

void radixSort(int arr[], int n, long long &comparison) {
}

void countingSort(int arr[], int n, int exp) {
    int* frequent = new int[BASE]{};

    for (int i = 0; i < n; i++) {
        ++frequent[(arr[i] / exp) % BASE];
    }

    for (int value = 1; value < BASE; value++) {
        frequent[value] += frequent[value - 1];
    }

    int* tmp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        tmp[frequent[(arr[i] / exp) % BASE] - 1] = arr[i];
        --frequent[(arr[i] / exp) % BASE] - 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }

    delete [] frequent;
    delete [] tmp;
}

void radixSort(int arr[], int n) {
    int maxValue = *std::max_element(arr, arr + n);

    for (int exp = 1; maxValue > exp; exp *= BASE) {
        countingSort(arr, n, exp);
    }

    return;
}