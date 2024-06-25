#include <mergeSort.h>

// MERGE SORT
// Each time, if the number of elements is more than 1, divide the array into 2 subarray and apply mergeSort on the 2 subarray, then
//  try to merge the two sorted-subarray.

// TIME COMPLEXITY:
// --- Basic operation: (In function merge): L[i] <= R[i]: r - l ~~ n
// ---> T(n) = 2T(n/2) + n. Suppose n = 2^k then T(2^k) = 2T(2^{k-1}) + n  = 4.T(2^{k-2}) + 2n = ... = 2^k.T(1) + k.n = (k + 1)n
// ---> TIME COMPLEXITY ~~ O(nlog(n))
// BEST CASE ~~~ WORST CASE --> the performance is not affected by the order of input 

// ---> BEST - AVERAGE - WORST CASE: O(n.log(n)) - O(n.log(n)) - O(n.log(n))
// ---> stable, not in-place, non-adaptive

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

// ---------------------------------------------------

void merge(int* a, int l, int m, int r, long long& compare) {
    int* L = new int [m - l + 1];
    int* R = new int [r - m + 1];
    L[m - l] = R[r - m] = INT_MAX;

    for (int i = 0; ++compare && i < m - l; ++i)
        L[i] = a[i];
    for (int i = 0; ++compare && i < r - m; ++i)
        R[i] = a[m + i];

    int i = 0, j = 0;
    for (int k = 0; ++compare && k < r - l; ++k) {
        if (++compare && L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
    
    delete [] L;
    delete [] R;
}

void mergeSort(int* a, int n, long long& compare) {
    if (++compare && n < 2)
        return;
    int mid = n / 2;
    mergeSort(a, mid, compare);
    mergeSort(a + mid, n - mid, compare);
    merge(a, 0, mid, n, compare);
}
