#include <shakerSort.h>

void shakerSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped)
    {
        // Reset the swapped flag at the start of each iteration
        swapped = false;
        // Traverse the array from left to right, same as the bubble sort
        for (int i = start; i < end; i++)
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;
        // Reset the swapped flag for the next pass
        swapped = false;
        // Reduce the end index because the last element is now in the correct position
        end--;
        // Traverse the array from right to left, same as the bubble sort
        for (int i = end - 1; i >= start; i--)
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        // Increase start index because the first element is now in the correct position
        start++;
    }
}


void shakerSort(int a[], int n, long long &comparisons)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    comparisons = 0;
    while (swapped)
    {
        // Reset the swapped flag at the start of each iteration
        swapped = false;
        // Traverse the array from left to right, same as the bubble sort
        for (int i = start; ++comparisons && (i < end); i++)
            if (++comparisons && (a[i] > a[i + 1]))
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;
        // Reset the swapped flag for the next pass
        swapped = false;
        // Reduce the end index because the last element is now in the correct position
        end--;
        // Traverse the array from right to left, same as the bubble sort
        for (int i = end - 1; ++comparisons && (i >= start); i--)
            if (++comparisons && (a[i] > a[i + 1]))
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        // Increase start index because the first element is now in the correct position
        start++;
    }
}
