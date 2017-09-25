#include "stdafx.h"
using namespace std;
void SudokuMaker::RequestInit(int n)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            M[i][j] = 0;
        }
    }
    M[0][0] = FirstNumber;
    maxnum = n;
    count = 0;
}
bool SudokuMaker::check(int r, int l, int num)
{
    int a = 3 * (r / 3);
    int b = 3 * (l / 3);
    for (int i = 0; i < 9; ++i)
    {
        if (i != r && M[i][l] == num)
            return false;
        if (i != l && M[r][i] == num)
            return false;
    }
    for (int i = a; i < a + 3; ++i)
    {
        for (int j = b; j < b + 3; ++j)
        {
            if ((i != r || j != l) && M[i][j] == num)
                return false;
        }
    }
    return true;
}
bool SudokuMaker::fill(int r, int l, char *ret)
{
    int nr = l == 8 ? r + 1 : r;
    int nl = l == 8 ? 0 : l + 1;
    for (int k = 1; k < 10; ++k)
    {
        if (!SudokuMaker::check(r, l, k))
            continue;
        M[r][l] = k;
        if (r == 8 && l == 8)//�������һ��λ��
        {
            count++;
            if (count == maxnum)//��������Ҫ����Ŀ�������վ֣�������վֲ������ݹ�
            {
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        ret[9 * i + j + 81 * (count-1)] = char(M[i][j] + '0');
                    }
                }
                return true;
            }
            else
            {
                //������Ŀ��������������ָ�[r,l]����ֵ����������һ��
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        ret[9 * i + j + 81 * (count-1)] = char(M[i][j] + '0');
                    }
                }
                M[r][l] = 0;
                continue;
            }
        }
        else 
        {
            if (SudokuMaker::fill(nr, nl, ret))//�ݹ������һ��λ��
                return true;
            else
            {
                M[r][l] = 0;
                continue;
            }
        }
    }
    return false;
}