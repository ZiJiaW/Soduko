// Soduko.cpp: 定义控制台应用程序的入口点。
#include"stdafx.h"
#include<ctime>
using namespace std;
int main(int argc, char *argv[])
{
//    time_t begin;
//    time_t end;
//    begin = time(NULL);
	if (argc != 3)
	{
		cerr << "illegal input!" << endl;
		return 0;
	}
    if (strcmp(argv[1], "-s") == 0)
    {
        vector<int(*)[9]> ProblemSet = SodukoInput(argv[2]);//"-s" "e:\\visual studio 2017 project\\Soduko\\Soduko\\sudokuProblem.txt"
        //fstream file("Sudoku.txt", fstream::out | fstream::app);
        for (auto p = ProblemSet.begin(); p != ProblemSet.end(); ++p)
        {
            SudokuSolve solution;
            solution.ProblemInit(*p);
            if (!solution.Solve(0, 0))
            {
                cout << "No Solution!" << endl;
                return 0;
            }
            freopen("sudoku.txt", "w", stdout);
            if (p + 1 == ProblemSet.end())
                SudokuOutput(solution.getSolution(), false);
            else
                SudokuOutput(solution.getSolution(), true);
            fclose(stdout);
        }
        //file.close();
    }
    else if (strcmp(argv[1], "-c") == 0)//"-c" "10000"
    {
        //fstream file("Sudoku.txt", fstream::out | fstream::app);
        if (!IsDigit(argv[2]))
        {
            cerr << "illegal input!" << endl;
            return 0;
        }
        SudokuMaker r;
        freopen("sudoku.txt", "w", stdout);
        r.RequestInit(atoi(argv[2]));
        r.fill(0, 1);
        fclose(stdout);
        //file.close();
    }
    else
        cerr << "illegal input!" << endl;
 //   end = time(NULL);
 //   cout << end - begin << 's' << endl;
	return 0;
}

