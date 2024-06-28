#include <quickSort.h>

int partition(int* a, int l, int r) {
    int p = l + rand() % (r + 1);
    std::swap(a[p], a[r]);
    p = r;
    --r;
    while (l <= r) {
        while (a[l] <= a[p] && l <= r)
            ++l;   
        while (a[r] > a[p] && l <= r)
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
    quickSort(a + mid + 1, n - mid - 1);
}

int partition(int* a, int l, int r, long long& compare) {
    int p = l + rand() % (r + 1);
    std::swap(a[p], a[r]);
    p = r;
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

void quickSort(int* a, int n, long long& compare) {
    if (++compare && n <= 1)
        return;
    int mid = partition(a, 0, n - 1, compare);
    quickSort(a, mid, compare);
    quickSort(a + mid + 1, n - mid - 1, compare);
}
