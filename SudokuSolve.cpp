#include "stdafx.h"
using namespace std;
void SudokuSolve::ProblemInit(int p[9][9])
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			problem[i][j] = p[i][j];
		}
	}
}
void SudokuSolve::showSolution()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (j == 8)
				cout << problem[i][j] << endl;
			else
				cout << problem[i][j] << ' ';
		}
	}
}
int (*SudokuSolve::getSolution())[9]
{
    int(*p)[9] = new int[9][9];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            p[i][j] = problem[i][j];
        }
    }
    return p;
}
/*
check if filling (r, l) with num is ok.
*/
bool SudokuSolve::check(int r, int l, int num)
{
	for (int i = 0; i < 9; ++i)
	{
		if (i != r && problem[i][l] == num)
			return false;
		if (i != l && problem[r][i] == num)
			return false;
	}
	for (int i = 3 * (r / 3); i < 3 * (r / 3) + 3; ++i)
	{
		for (int j = 3 * (l / 3); j < 3 * (l / 3) + 3; ++j)
		{
			if ((i != r || j != l) && problem[i][j] == num)
				return false;
		}
	}
	return true;
}
/*
recursively solve the problem.
*/
bool SudokuSolve::Solve(int r, int l)
{
	int nr = l == 8 ? r + 1 : r;
	int nl = l == 8 ? 0 : l + 1;
	if (problem[r][l] != 0 && nr < 9)//(r, l) already has a number
	{
		if (SudokuSolve::Solve(nr, nl))
			return true;
		else
			return false;
	}
	else if (problem[r][l] != 0 && nr >= 9)//problem solved
		return true;
	// now problem[i][j] == 0, try to fill it.
	for (int k = 1; k < 10; ++k)
	{
		if (!SudokuSolve::check(r, l, k))
			continue;
		problem[r][l] = k;
		if (r == 8 && l == 8)//problem solved
			return true;
		if (SudokuSolve::Solve(nr, nl))
			return true;
		else
			problem[r][l] = 0;//k is bad, try k+1.
	}
	return false;//can't find a k.
}