#include "insertionSort.h"

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertionSort(int a[], int n, long long &comparison) {
    for (int i = 1; ++comparison && (i < n); i++) {
        int j = i - 1;
        int key = a[i];
        while ((++comparison && (j >= 0)) && (++comparison && (a[j] > key))) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}