#include <quickSort.h>

// Choose an pivot and partition the array into two parts (elements that smaller than and greater than or equal to pivot). Put the pivot
//  to the correct possition and recursively sort the 2 parts.

// TIME COMPLEXITY:
// --- In function partition, l and r go through the size of array ~~~ n
// --- BEST CASE (each time seperate the array into two equal parts): T(n) = n + 2.T(n / 2) ---> T(n) ~~~ O(n.log(n))
// --- WORST CASE (each time the pivot is the greatest/smallest element): T(n) = n + T(n - 1) ---> T(n) ~~~ O(n^2)
// --- AVERAGE CASE: T(n) = T(n - k) + T(k) + n, for k = 1 -> n - 1 ----> T(n) = (sigma(T(n-k)) + sigma(T(k)))/n + n = 2.sigma(T(k))/n+n
//     ---> n.T(n) - n^2 = 2sigma(T(k)) = 2.T(n - 1) + (n - 1).T(n - 1) - (n - 1)^2
//     ---> T(n)/(n + 1) = T(n - 1)/n - (2n - 1)/(n(n+1)) ----> T(n) ~~~ n.log(n)

// ---> BEST - AVERAGE - WORST CASE: O(n.log(n)) - O(n.log(n)) - O(n^2)
// non-stable, in-place, adaptive

int partition(int* a, int l, int r) {
    int p = r; 
    --r;
    while (l <= r) {
        while (a[l] <= a[p] && l <= r)
            ++l;   
        while (a[r] > a[p] && r >= l)
            --r;
        if (l <= r) {
            std::swap(a[l], a[r]);
            ++l; --r;
        }
    }
    std::swap(a[l], a[p]);
    return l;
}

void quickSort(int* a, int n) {
    if (n <= 1)
        return;
    int mid = partition(a, 0, n - 1);
    quickSort(a, mid);
    quickSort(a + mid, n - mid);
}

// --------------------------------------------

int partition(int* a, int l, int r, int& compare) {
    int p = r; 
    --r;
    while (++compare && l <= r) {
        while ((++compare && a[l] <= a[p]) && (++compare && l <= r))
            ++l;   
        while ((++compare && a[r] > a[p]) && (++compare && r >= l))
            --r;
        if (++compare && l <= r) {
            std::swap(a[l], a[r]);
            ++l; --r;
        }
    }
    std::swap(a[l], a[p]);
    return l;
}

void quickSort(int* a, int n, int& compare) {
    if (++compare && n <= 1)
        return;
    int mid = partition(a, 0, n - 1, compare);
    quickSort(a, mid, compare);
    quickSort(a + mid, n - mid, compare);
}
