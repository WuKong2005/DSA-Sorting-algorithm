#pragma once

#include <cmath>
#include <time.h>
#include <cstdlib>
#include <algorithm>

int const NUMBER_DATA_ORDER = 4;

enum DATA_ORDER
{
    RANDOM_DATA,
    NEARLY_SORTED_DATA,
    SORTED_DATA,
    REVERSE_DATA
};

void GenerateData(int a[], int n, int dataType);
