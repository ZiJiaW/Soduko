#pragma once
#ifndef SudokuSolve_H
#define SudokuSolve_H
using namespace std;
class SudokuSolve {
public:
	bool Solve(int r, int l);//�ݹ�����
	bool check(int r, int l, int num);//����ͬ��ͬ��ͬ���Ƿ�����num
	void ProblemInit(int p[9][9]);//��ʼ��
    int(*getSolution())[9];//���ؽ�
private:
	int problem[9][9];
};
#endif // !SudokuSolve_H
