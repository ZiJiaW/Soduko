#pragma once
#ifndef SudokuSolve_H
#define SudokuSolve_H
using namespace std;
class SudokuSolver {
public:
    bool StartSolving();
    void ProblemInit(int p[][9]);//��ʼ��
    void GetSolution(int p[][9]);//���ؽ�
private:
    int problem[9][9];
    bool Solve(int r, int l);//�ݹ�����
    bool Check(int r, int l, int num);//����ͬ��ͬ��ͬ���Ƿ�����num
};
#endif // !SudokuSolve_H