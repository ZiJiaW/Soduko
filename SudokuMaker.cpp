#include "stdafx.h"
using namespace std;
void SudokuMaker::RequestInit(int n)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
<<<<<<< HEAD
            Matrix[i][j] = 0;
        }
    }
    Matrix[0][0] = FirstNumber;
    maxnum = n;
    count = 0;
}
bool SudokuMaker::Check(int r, int l, int num)
=======
            M[i][j] = 0;
        }
    }
    M[0][0] = FirstNumber;
    maxnum = n;
    count = 0;
}
bool SudokuMaker::check(int r, int l, int num)
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
{
    int a = 3 * (r / 3);
    int b = 3 * (l / 3);
    for (int i = 0; i < 9; ++i)
    {
<<<<<<< HEAD
        if (i != r && Matrix[i][l] == num)
            return false;
        if (i != l && Matrix[r][i] == num)
=======
        if (i != r && M[i][l] == num)
            return false;
        if (i != l && M[r][i] == num)
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
            return false;
    }
    for (int i = a; i < a + 3; ++i)
    {
        for (int j = b; j < b + 3; ++j)
        {
<<<<<<< HEAD
            if ((i != r || j != l) && Matrix[i][j] == num)
=======
            if ((i != r || j != l) && M[i][j] == num)
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
                return false;
        }
    }
    return true;
}
<<<<<<< HEAD
bool SudokuMaker::Fill(int r, int l, char *ret)
=======
bool SudokuMaker::fill(int r, int l, char *ret)
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
{
    int nr = l == 8 ? r + 1 : r;
    int nl = l == 8 ? 0 : l + 1;
    for (int k = 1; k < 10; ++k)
    {
<<<<<<< HEAD
        if (!SudokuMaker::Check(r, l, k))
            continue;
        Matrix[r][l] = k;
=======
        if (!SudokuMaker::check(r, l, k))
            continue;
        M[r][l] = k;
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
        if (r == 8 && l == 8)//到达最后一个位置
        {
            count++;
            if (count == maxnum)//若已生成要求数目的数独终局，则输出终局并结束递归
            {
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
<<<<<<< HEAD
                        ret[9 * i + j + 81 * (count-1)] = char(Matrix[i][j] + '0');
=======
                        ret[9 * i + j + 81 * (count-1)] = char(M[i][j] + '0');
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
                    }
                }
                return true;
            }
            else
            {
                //生成数目不够，则输出并恢复[r,l]处的值，并试填下一个
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
<<<<<<< HEAD
                        ret[9 * i + j + 81 * (count-1)] = char(Matrix[i][j] + '0');
                    }
                }
                Matrix[r][l] = 0;
=======
                        ret[9 * i + j + 81 * (count-1)] = char(M[i][j] + '0');
                    }
                }
                M[r][l] = 0;
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
                continue;
            }
        }
        else 
        {
<<<<<<< HEAD
            if (SudokuMaker::Fill(nr, nl, ret))//递归求解下一个位置
                return true;
            else
            {
                Matrix[r][l] = 0;
=======
            if (SudokuMaker::fill(nr, nl, ret))//递归求解下一个位置
                return true;
            else
            {
                M[r][l] = 0;
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
                continue;
            }
        }
    }
    return false;
<<<<<<< HEAD
}

void SudokuMaker::StartGenerating(char *ret)
{
    SudokuMaker::Fill(0, 1, ret);
=======
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
}