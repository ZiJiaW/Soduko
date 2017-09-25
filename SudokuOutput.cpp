#include "stdafx.h"
using namespace std;
void SudokuOutput(char *ret,int maxnum, char *ret2)
{
    int j = 0, i = 0;
    while (i < maxnum)
    {
        if (i == maxnum - 1)
        {
            ret2[j] = ret[i];
            ret2[j + 1] = '\0';
        }
        else if (i % 81 == 80)
        {
            ret2[j] = ret[i];
            ret2[j + 1] = '\n';
            ret2[j + 2] = '\n';
            j += 3;
        }
        else if (i % 9 == 8)
        {
            ret2[j] = ret[i];
            ret2[j + 1] = '\n';
            j += 2;
        }
        else
        {
            ret2[j] = ret[i];
            ret2[j + 1] = ' ';
            j += 2;
        }
        ++i;
    }
}