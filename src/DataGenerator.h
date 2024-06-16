#pragma once

#include <cmath>
#include <time.h>
#include <cstdlib>

enum DATA_ORDER {
    RANDOM_DATA,
    SORTED_DATA,
    REVERSE_DATA,
    NEARLY_SORTED_DATA
};

void GenerateData(int a[], int n, int dataType);
