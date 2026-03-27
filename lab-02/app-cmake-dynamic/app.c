#include "test.h"

int a[] = {1, 2, 3, 4, 2};

int main (void)
{
    int len = sizeof(a) / sizeof(int);

    Print(SumArray(a, len));

    return 0;
}

