#include <heapSort.h>

void heapify(int* a, int n, int parrent) {
    int largest = parrent;
    int l = 2 * parrent + 1;
    int r = l + 1;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != parrent) {
        std::swap(a[largest], a[parrent]);
        heapify(a, n, largest);
    }
}

void heapSort(int* a, int n) {
    // build max heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(a, n, i);

    // sequently get the maximum element to the end of array and re-heapify the rest of array
    for (int i = 0; i < n - 1; ++i) {
        std::swap(a[0], a[n - i - 1]);
        heapify(a, n - i - 1, 0);
    }
}

void heapify(int* a, int n, int parrent, long long& comparisons) {
    int largest = parrent;
    int l = 2 * parrent + 1;
    int r = l + 1;

    if ((++comparisons && l < n) && (++comparisons && a[l] > a[largest]))
        largest = l;
    if ((++comparisons && r < n) && (++comparisons && a[r] > a[largest]))
        largest = r;

    if (++comparisons && largest != parrent) {
        std::swap(a[largest], a[parrent]);
        heapify(a, n, largest, comparisons);
    }
}

void heapSort(int* a, int n, long long& comparisons) {
    for (int i = n / 2 - 1; ++comparisons && i >= 0; --i)
        heapify(a, n, i, comparisons);

    for (int i = 0; ++comparisons && i < n - 1; ++i) {
        std::swap(a[0], a[n - i - 1]);
        heapify(a, n - i - 1, 0, comparisons);
    }
}