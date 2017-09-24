#pragma once
#ifndef SudokuMaker_H
#define SudokuMaker_H
#define FirstNumber (9+6)%9+1
using namespace std;
class SudokuMaker {
public:
    bool fill(int r, int l, fstream &file);
    bool check(int r, int l, int num);
    void RequestInit(int n);
private:
    int maxnum;
    int count;
    int M[9][9];
};
#endif // !SudokuMaker_H
