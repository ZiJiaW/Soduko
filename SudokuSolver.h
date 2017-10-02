#pragma once
#ifndef SudokuSolve_H
#define SudokuSolve_H
using namespace std;
class SudokuSolver {
public:
    bool StartSolving();
	void ProblemInit(int p[9][9]);//初始化
    int (*GetSolution())[9];//返回解
private:
	int problem[9][9];
    bool Check(int r, int l, int num);//测试同行同宫同列是否已有num
    bool Solve(int r, int l);//递归填数
};
#endif // !SudokuSolve_H
