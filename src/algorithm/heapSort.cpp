#include <heapSort.h>

// HEAP SORT
// ---> BEST - AVERAGE - WORST CASE: O(n.log(n)) - O(n.log(n)) - O(n.log(n))
// ---> non-stable, in-place, non-adaptive
// TIME COMPLEXITY: O(log(n)) because the times we call recursion can not greater than the height of heap - which is log(n)
// BEST CASE: O(1)
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

// TIME COMPLEXITY: O(nlog(n)) because the cost to build max heap is O(n.log(n)) (BEST CASE is O(n)) and to sequently get the maximum element to the end of
// array is O(nlog(n)).
// BEST CASE is all the elements are equal ---> O(n)
void heapSort(int* a, int n) {
    // build max heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(a, n, i);

    // sequently get the maximum element to the end of array and re-heapify the array
    for (int i = 0; i < n - 1; ++i) {
        std::swap(a[0], a[n - i - 1]);
        heapify(a, n - i - 1, 0);
    }
}

// ----------------------------------------

void heapify(int* a, int n, int parrent, int& compare) {
    int largest = parrent;
    int l = 2 * parrent + 1;
    int r = l + 1;

    if ((++compare && l < n) && (++compare && a[l] > a[largest]))
        largest = l;
    if ((++compare && r < n) && (++compare && a[r] > a[largest]))
        largest = r;

    if (++compare && largest != parrent) {
        std::swap(a[largest], a[parrent]);
        heapify(a, n, largest, compare);
    }
}

void heapSort(int* a, int n, int& compare) {
    // build max heap
    for (int i = n / 2 - 1; ++compare && i >= 0; --i)
        heapify(a, n, i, compare);

    // sequently get the maximum element to the end of array and re-heapify the array
    for (int i = 0; ++compare && i < n - 1; ++i) {
        std::swap(a[0], a[n - i - 1]);
        heapify(a, n - i - 1, 0, compare);
    }
}