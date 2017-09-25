#pragma once
#ifndef SudokuMaker_H
#define SudokuMaker_H
#define FirstNumber (9+6)%9+1
using namespace std;
class SudokuMaker {
public:
    bool fill(int r, int l, char *ret);//�ݹ�����
    bool check(int r, int l, int num);//�ж���[r,l]������num�Ƿ������������
    void RequestInit(int n);//��ʼ������
private:
    int maxnum;//��Ҫ���ɵ������վ���
    int count;//��ǰ�����ɵ������վ���
    int M[9][9];//ά������������
};
#endif // !SudokuMaker_H
