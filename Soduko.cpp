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
	
	if (argc != 3)
	{
		cout << "illegal input!" << endl;
		return 0;
	}
 //   cout << strcmp(argv[1], "-s") << endl;
    if (strcmp(argv[1], "-s") == 0)
    {
 //       cout << "ok" << endl;
        vector<int(*)[9]> ProblemSet = SodukoInput(argv[2]);//"-s" "e:\\visual studio 2017 project\\Soduko\\Soduko\\sudokuProblem.txt"
        for (auto p = ProblemSet.begin(); p != ProblemSet.end(); ++p)
        {
 //           cout << "ok" << endl;
            /*
            for (int i = 0; i < 9; ++i)
            {
                for (int j = 0; j < 9; ++j)
                {
                    if (j == 8)
                        cout << (*p)[i][j] << endl;
                    else
                        cout << (*p)[i][j] << ' ';
                }
            }
            */
            //cout << endl;
            SudokuSolve solution;
            solution.ProblemInit(*p);
            //cout << solution.check(0, 1, 5) << endl;
            if (!solution.Solve(0, 0))
            {
                cout << "No Solution!" << endl;
                return 0;
            }
            if (p + 1 == ProblemSet.end())
                SudokuOutput(solution.getSolution(), false);
            else
                SudokuOutput(solution.getSolution(), true);
        }
    }
    else if (strcmp(argv[1], "-c") == 0)//"-c" "20"
    {
//        cout << "ok" << endl;
        if (!IsDigit(argv[2]))
        {
            cout << "illegal input!" << endl;
            return 0;
        }
        SudokuMaker r;
        r.RequestInit(atoi(argv[2]));
        r.fill(0, 1);
    }
    else
        cout << "illegal input!" << endl;
	return 0;
}

