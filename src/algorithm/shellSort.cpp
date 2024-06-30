#include <shellSort.h>

void shellSort(int a[], int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        // Iterate through each element from gap to the end of the array, similar to insertion sort
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 2; 
    }
}

void shellSort(int a[], int n, long long &comparisons)
{
    int gap = n / 2;
    while (++comparisons && (gap > 0))
    {
        for (int i = gap; ++comparisons && (i < n); i++)
        {
            int temp = a[i];
            int j = i;
            while ((++comparisons && (j >= gap)) && (++comparisons && (a[j - gap] > temp)))
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 2; 
    }
}