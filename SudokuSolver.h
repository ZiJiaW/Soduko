#pragma once
#ifndef SudokuSolve_H
#define SudokuSolve_H
using namespace std;
class SudokuSolver {
public:
    bool StartSolving();
	void ProblemInit(int p[9][9]);//��ʼ��
    int (*GetSolution())[9];//���ؽ�
private:
	int problem[9][9];
    bool Check(int r, int l, int num);//����ͬ��ͬ��ͬ���Ƿ�����num
    bool Solve(int r, int l);//�ݹ�����
};
#endif // !SudokuSolve_H
