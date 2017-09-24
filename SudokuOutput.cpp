#include "stdafx.h"
using namespace std;
void SudokuOutput(int p[9][9], bool flag, fstream &file)
{
    if (!file.is_open())
        cerr << "fail to open file!" << endl;
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (j == 8)
                    file << p[i][j] << endl;
                else
                    file << p[i][j] << ' ';
            }
        }
        if (flag)
            file << endl;
    }
}