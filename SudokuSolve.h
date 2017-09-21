#pragma once
#ifndef SudokuSolve_H
#define SudokuSolve_H
using namespace std;
class SudokuSolve {
public:
	bool Solve(int r, int l);
	bool check(int r, int l, int num);
	void ProblemInit(int p[9][9]);
	void showSolution();
private:
	int problem[9][9];
};
#endif // !SudokuSolve_H
