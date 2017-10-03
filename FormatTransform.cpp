#include "stdafx.h"
#include "FormatTransform.h"
using namespace std;
void FormatTransform(char *from, int maxnum, char *to)
{
    int j = 0, i = 0;
    while (i < maxnum)
    {
        if (i == maxnum - 1)
        {
            to[j] = from[i];
            to[j + 1] = '\0';
        }
        else if (i % 81 == 80)
        {
            to[j] = from[i];
            to[j + 1] = '\n';
            to[j + 2] = '\n';
            j += 3;
        }
        else if (i % 9 == 8)
        {
            to[j] = from[i];
            to[j + 1] = '\n';
            j += 2;
        }
        else
        {
            to[j] = from[i];
            to[j + 1] = ' ';
            j += 2;
        }
        ++i;
    }
}