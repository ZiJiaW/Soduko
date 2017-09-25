// Soduko.cpp: 定义控制台应用程序的入口点。
#include"stdafx.h"
using namespace std;
int main(int argc, char *argv[])
{
    char *result = new char[1000000 * 81 + 1];
    char *q = new char[1000000 * (81 * 2 + 1)];
	if (argc != 3)
	{
		cerr << "illegal input!" << endl;
		return 0;
	}
    if (strcmp(argv[1], "-s") == 0)
    {
        vector<int(*)[9]> ProblemSet = SodukoInput(argv[2]);//"-s" "e:\\visual studio 2017 project\\Soduko\\Soduko\\sudokuProblem.txt"
        int i = 0;
        FILE * file;
        file = fopen("sudoku.txt", "w");
        for (auto p = ProblemSet.begin(); p != ProblemSet.end(); ++p, ++i)
        {
            SudokuSolve solution;
            solution.ProblemInit(*p);
            if (!solution.Solve(0, 0))
            {
                cout << "No Solution in problem NO." << i + 1 << endl;
                return 0;
            }
            int(*r)[9] = solution.getSolution();
            for (int k = 0; k < 9; ++k)
            {
                for (int l = 0; l < 9; ++l)
                {
                    result[9 * k + l + 81 * i] = char(r[k][l] + '0');
                }
            }
        }
        SudokuOutput(result, i * 81, q);
        fputs(q, file);
        fclose(file);
    }
    else if (strcmp(argv[1], "-c") == 0)//"-c" "1000000"
    {
        if (!IsDigit(argv[2]))
        {
            cerr << "illegal input!" << endl;
            return 0;
        }
        FILE *file;
        file = fopen("sudoku.txt", "w");
        SudokuMaker r;
        r.RequestInit(atoi(argv[2]));
        r.fill(0, 1, result);
        SudokuOutput(result, atoi(argv[2]) * 81, q);
        fputs(q, file);
        fclose(file);
    }
    else
        cerr << "illegal input!" << endl;
    delete(result);
    delete(q);
	return 0;
}

