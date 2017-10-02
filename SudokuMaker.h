#pragma once
#ifndef SudokuMaker_H
#define SudokuMaker_H
#define FirstNumber (9+6)%9+1
using namespace std;
class SudokuMaker {
public:
    void StartGenerating(char *ret);
    void RequestInit(int n);//初始化需求
private:
    int maxnum;//需要生成的数独终局数
    int count;//当前已生成的数独终局数
    int Matrix[9][9];//维护的数独棋盘
    bool Fill(int r, int l, char *ret);//递归填数
    bool Check(int r, int l, int num);//判断在[r,l]处放入num是否符合数独规则
};
#endif // !SudokuMaker_H
