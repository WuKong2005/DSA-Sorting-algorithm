#include <shakerSort.h>

void shakerSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped)
    {
        swapped = false;
        // Traverse the array from left to right, same as the bubble sort
        for (int i = start; i < end; i++)
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
        swapped = false;
        end--;
        // Traverse the array from right to left, same as the bubble sort
        for (int i = end - 1; i >= start; i--)
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        start++;
    }
}


void shakerSort(int a[], int n, long long &comparisons)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (++comparisons && swapped)
    {
        swapped = false;
        for (int i = start; ++comparisons && (i < end); i++)
            if (++comparisons && (a[i] > a[i + 1]))
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        if (++comparisons && !swapped)
            break;
        swapped = false;
        end--;
        for (int i = end - 1; ++comparisons && (i >= start); i--)
            if (++comparisons && (a[i] > a[i + 1]))
            {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        start++;
    }
}
