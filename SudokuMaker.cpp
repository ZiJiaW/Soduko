#include "stdafx.h"
using namespace std;
void SudokuMaker::RequestInit(int n)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            Matrix[i][j] = 0;
        }
    }
    Matrix[0][0] = FirstNumber;
    maxnum = n;
    count = 0;
}
bool SudokuMaker::Check(int r, int l, int num)
{
    int a = 3 * (r / 3);
    int b = 3 * (l / 3);
    for (int i = 0; i < 9; ++i)
    {
        if (i != r && Matrix[i][l] == num)
            return false;
        if (i != l && Matrix[r][i] == num)
            return false;
    }
    for (int i = a; i < a + 3; ++i)
    {
        for (int j = b; j < b + 3; ++j)
        {
            if ((i != r || j != l) && Matrix[i][j] == num)
                return false;
        }
    }
    return true;
}
bool SudokuMaker::Fill(int r, int l, char *ret)
{
    int nr = l == 8 ? r + 1 : r;
    int nl = l == 8 ? 0 : l + 1;
    for (int k = 1; k < 10; ++k)
    {
        if (!Check(r, l, k))
            continue;
        Matrix[r][l] = k;
        if (r == 8 && l == 8)//�������һ��λ��
        {
            count++;
            if (count == maxnum)//��������Ҫ����Ŀ�������վ֣�������վֲ������ݹ�
            {
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        ret[9 * i + j + 81 * (count - 1)] = char(Matrix[i][j] + '0');
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
                        ret[9 * i + j + 81 * (count - 1)] = char(Matrix[i][j] + '0');
                    }
                }
                Matrix[r][l] = 0;
                continue;
            }
        }
        else
        {
            if (Fill(nr, nl, ret))//�ݹ������һ��λ��
                return true;
            else
            {
                Matrix[r][l] = 0;
                continue;
            }
        }
    }
    return false;
}
void SudokuMaker::StartGenerating(char *ret)
{
    Fill(0, 1, ret);
}