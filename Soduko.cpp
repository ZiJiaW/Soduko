// Soduko.cpp: 定义控制台应用程序的入口点。
//
/*
9 5 8 3 6 7 1 2 4
2 3 7 4 5 1 9 6 8
1 4 6 9 2 8 3 5 7
6 1 2 8 7 4 5 9 3
5 7 3 6 1 9 4 8 2
4 8 9 2 3 5 6 7 1
7 2 4 5 9 3 8 1 6
8 9 1 7 4 6 2 3 5
3 6 5 1 8 2 7 4 9
*/
#include"stdafx.h"
using namespace std;
int main(int argc, char *argv[])
{
	/*
	if (argc != 3)
	{
		cout << "illegal input" << endl;
		return -1;
	}*/
//	if (strcmp(argv[1], "-s"))
	{
		vector<int(*)[9]> ProblemSet = SodukoInput("e:\\visual studio 2017 project\\Soduko\\Soduko\\sudoku.txt");
		for (auto p : ProblemSet)
		{
			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; ++j)
				{
					if (j == 8)
						cout << p[i][j] << endl;
					else
						cout << p[i][j] << ' ';
				}
			}
			cout << endl;
			SudokuSolve solution;
			solution.ProblemInit(p);
			//cout << solution.check(0, 1, 5) << endl;
			if (!solution.Solve(0, 0))
			{
				cout << "No Solution!" << endl;
				return 0;
			}
			solution.showSolution();
			cout << endl;
		}
	}
	return 0;
}

