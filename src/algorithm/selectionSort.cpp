#include "selectionSort.h"

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        int min = i; 
        for (int j = i + 1; j < n; j++) { 
            if (a[j] < a[min]) 
                min = j;
        }
        std::swap(a[i], a[min]);
    }
}

void selectionSort(int a[], int n, long long &comparison) {
    for (int i = 0; ++comparison && (i < n - 1); i++) { 
        int min = i; 
        for (int j = i + 1; ++comparison && (j < n); j++) { 
            if (++comparison && (a[j] < a[min])) 
                min = j;
        }
        std::swap(a[i], a[min]);
    }
}
