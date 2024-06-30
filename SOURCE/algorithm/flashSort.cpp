#include "flashSort.h"

int getIndex(int m, int minValue, int maxValue, int val) {
    return 1ll * (m - 1) * (val - minValue) / (maxValue - minValue);
}

void flashSort(int arr[], int n) {
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;

    int* L = new int[m]{};

    //step 1
    int minValue = *std::min_element(arr, arr + n), maxValue = *std::max_element(arr, arr + n);
    if (maxValue == minValue)
        return;

    #define getK(x) 1ll * (m - 1) * (x - minValue) / (maxValue - minValue)

    for (int i = 0; i < n; ++i) {
        ++L[getK(arr[i])];
    }
    for (int i = 1; i < m; ++i) {
        L[i] += L[i - 1];
    }

    //step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(arr[i]);
        while (i >= L[k]) {
            k = getK(arr[++i]);
        }
        int z = arr[i];
        while (i != L[k]) {
            k = getK(z);
            int y = arr[L[k] - 1];
            arr[--L[k]] = z;
            z = y;
            ++count;
        }
    }   

    //step 3
    for (int k = 1; k < m; ++k) {
        for (int i = L[k] - 2; i >= L[k - 1]; --i) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i], j = i;
                while (t > arr[j + 1]) {
                    arr[j] = arr[j + 1]; 
                    ++j;
                }
                arr[j] = t;
            }
        } 
    }

    delete [] L;
    return;
}

void flashSort(int arr[], int n, long long &comparison) {
    if (++comparison && n <= 1) return;
    int m = n * 0.43;
    if (++comparison && m <= 2) m = 2;

    int* L = new int[m]{};

    //step 1
    int minValue = *std::min_element(arr, arr + n), maxValue = *std::max_element(arr, arr + n);
    comparison += (n * 2 + (n == 0)) * 2; // calculated based on the implementation of std::max_element
    if (++comparison && maxValue == minValue)
        return;

    #define getK(x) 1ll * (m - 1) * (x - minValue) / (maxValue - minValue)

    for (int i = 0; ++comparison && i < n; ++i) {
        ++L[getK(arr[i])];
    }
    for (int i = 1; ++comparison && i < m; ++i) {
        L[i] += L[i - 1];
    }

    //step 2
    int count = 0;
    int i = 0;
    while (++comparison && count < n) {
        int k = getK(arr[i]);
        while (++comparison && i >= L[k]) {
            k = getK(arr[++i]);
        }
        int z = arr[i];
        while (++comparison && i != L[k]) {
            k = getK(z);
            int y = arr[L[k] - 1];
            arr[--L[k]] = z;
            z = y;
            ++count;
        }
    }   

    //step 3
    for (int k = 1; ++comparison && k < m; ++k) {
        for (int i = L[k] - 2; ++comparison && i >= L[k - 1]; --i) {
            if (++comparison && arr[i] > arr[i + 1]) {
                int t = arr[i], j = i;
                while (++comparison && t > arr[j + 1]) {
                    arr[j] = arr[j + 1]; 
                    ++j;
                }
                arr[j] = t;
            }
        } 
    }

    delete [] L;
    return;
}
