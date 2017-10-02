#pragma once
#ifndef SudokuMaker_H
#define SudokuMaker_H
<<<<<<< HEAD
const int FirstNumber = (9 + 6) % 9 + 1;
using namespace std;
class SudokuMaker {
public:
    void StartGenerating(char *ret);
=======
#define FirstNumber (9+6)%9+1
using namespace std;
class SudokuMaker {
public:
    bool fill(int r, int l, char *ret);//递归填数
    bool check(int r, int l, int num);//判断在[r,l]处放入num是否符合数独规则
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
    void RequestInit(int n);//初始化需求
private:
    int maxnum;//需要生成的数独终局数
    int count;//当前已生成的数独终局数
<<<<<<< HEAD
    int Matrix[9][9];//维护的数独棋盘
    bool Check(int r, int l, int num);//判断在[r,l]处放入num是否符合数独规则
    bool Fill(int r, int l, char *ret);//递归填数
=======
    int M[9][9];//维护的数独棋盘
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
};
#endif // !SudokuMaker_H
