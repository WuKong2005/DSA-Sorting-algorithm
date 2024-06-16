#include <shellSort.h>

void shellSort(int a[], int n)
{
    // Start with the large gap equal to half the number of elements in the array (n/2)
    int gap = n / 2;
    // Loop until the gap is greater than 0
    while (gap > 0)
    {
        // Iterate through each element from gap to the end of the array
        for (int i = gap; i < n; i++)
        {
            // Save the current value of a[i] into temp
            int temp = a[i];
            // Find the correct position to insert a[i] in the gap-sorted array
            int j = i;
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            // Place temp (the initial value of a[i]) into its correct position
            a[j] = temp;
        }
        // Reduce the gap by half
        gap /= 2; 
    }
}

void shellSort(int a[], int n, long long &comparisons)
{
    comparisons = 0;
    // Start with the large gap equal to half the number of elements in the array (n/2)
    int gap = n / 2;
    // Loop until the gap is greater than 0
    while (++comparisons && (gap > 0))
    {
        // Iterate through each element from gap to the end of the array
        for (int i = gap; ++comparisons && (i < n); i++)
        {
            // Save the current value of a[i] into temp
            int temp = a[i];
            // Find the correct position to insert a[i] in the gap-sorted array
            int j = i;
            while ((++comparisons && (j >= gap)) && (++comparisons && (a[j - gap] > temp)))
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            // Place temp (the initial value of a[i]) into its correct position
            a[j] = temp;
        }
        // Reduce the gap by half
        gap /= 2; 
    }
}