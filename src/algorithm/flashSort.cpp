#include "flashSort.h"

void flashSort(int arr[], int n, long long &comparison) {
}

void flashSort(int arr[], int n) {
    int minValue = *std::min_element(arr, arr + n), maxValue = *std::max_element(arr, arr + n);

    if (minValue == maxValue) {
        return;
    }

    int m = std::max(2, (int)(n * 0.45));
    int* L = new int[m]{};

    for (int i = 0; i < n; i++) {
        int k = 1LL * (arr[i] - minValue) * (m - 1) / (maxValue - minValue);
        ++L[k];
    }

    for (int k = 1; k < m; ++k) {
        L[k] += L[k - 1];
    }

    int i = 0;
    int count = 0;
    int curk = m - 1;
    while (count < n) {
        while (i >= L[curk]) {
            ++i;
            curk = 1LL * (arr[i] - minValue) * (m - 1) / (maxValue - minValue);
        }

        int flash = arr[i];
        while(i != L[curk]) {
            curk = 1LL * (arr[i] - minValue) * (m - 1) / (maxValue - minValue);

            std::swap(arr[L[curk] - 1], flash);
            --L[curk];
            ++count;
        }
    }

    std::cout << "done this step\n";
    for (int k = 0; k < m; k++) {
        std::cout << L[k] << " \n"[k == m - 1];
    }

    for (int k = 1; k < m; k++) {
        for (int i = L[k - 1] + 1; i < L[k]; i++) {
            int selected = arr[i];
            int pos = i - 1;

            while (pos > i && arr[pos] > selected) {
                arr[pos + 1] = arr[pos];
                --pos;
            }
            
            arr[pos + 1] = selected;
        }
    }

    delete [] L;
}
