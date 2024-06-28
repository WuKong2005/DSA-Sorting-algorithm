#include <mergeSort.h>

// merge array a[l, m) with a[m, r)
void merge(int* a, int l, int m, int r) {
    int* L = new int [m - l + 1];
    int* R = new int [r - m + 1];
    L[m - l] = R[r - m] = INT_MAX;

    for (int i = 0; i < m - l; ++i)
        L[i] = a[i];
    for (int i = 0; i < r - m; ++i)
        R[i] = a[m + i];

    int i = 0, j = 0;
    for (int k = 0; k < r - l; ++k) {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
    
    delete [] L;
    delete [] R;
}

void mergeSort(int* a, int n) {
    if (n < 2)
        return;
    int mid = n / 2;
    mergeSort(a, mid);
    mergeSort(a + mid, n - mid);
    merge(a, 0, mid, n);
}

void merge(int* a, int l, int m, int r, long long& comparisons) {
    int* L = new int [m - l + 1];
    int* R = new int [r - m + 1];
    L[m - l] = R[r - m] = INT_MAX;

    for (int i = 0; ++comparisons && i < m - l; ++i)
        L[i] = a[i];
    for (int i = 0; ++comparisons && i < r - m; ++i)
        R[i] = a[m + i];

    int i = 0, j = 0;
    for (int k = 0; ++comparisons && k < r - l; ++k) {
        if (++comparisons && L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
    
    delete [] L;
    delete [] R;
}

void mergeSort(int* a, int n, long long& comparisons) {
    if (++comparisons && n < 2)
        return;
    int mid = n / 2;
    mergeSort(a, mid, comparisons);
    mergeSort(a + mid, n - mid, comparisons);
    merge(a, 0, mid, n, comparisons);
}
