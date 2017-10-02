#include "stdafx.h"
using namespace std;
const int maxNum = 1000000;
char result[maxNum * 81 + 1];
char finalresult[maxNum*(81 * 2 + 1)];
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "illegal input!1" << endl;
        return 0;
    }
    if (strcmp(argv[1], "-s") == 0)
    {
        vector<int(*)[9]> ProblemSet = SudokuInput(argv[2]);
        int i = 0;
        FILE * file;
        fopen_s(&file, "sudoku.txt", "w");
        for (auto p = ProblemSet.begin(); p != ProblemSet.end(); ++p, ++i)
        {
            SudokuSolver solution;
            solution.ProblemInit(*p);
            if (!solution.StartSolving())
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
        FormatTransform(result, i * 81, finalresult);
        fputs(finalresult, file);
        fclose(file);
    }
    else if (strcmp(argv[1], "-c") == 0)//"-c" "1000000"
    {
        if (!IsDigit(argv[2]))
        {
            cerr << "illegal input!2" << endl;
            return 0;
        }
        FILE *file;
        fopen_s(&file, "sudoku.txt", "w");
        SudokuMaker r;
        r.RequestInit(atoi(argv[2]));
        r.StartGenerating(result);
        FormatTransform(result, atoi(argv[2]) * 81, finalresult);
        fputs(finalresult, file);
        fclose(file);
    }
    else
        cerr << "illegal input!3" << endl;
    return 0;
}