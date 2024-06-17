#include "bubbleSort.h"

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2 - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void bubbleSort(int a[], int n, long long &comparison) {
    for (int i = 0; ++comparison && (i < n - 2); i++) {
        for (int j = 0; ++comparison && (j < n - 2 - i); j++) {
            if (++comparison && (a[j] > a[j + 1]))
                swap(a[j], a[j + 1]);
        }
    }
}