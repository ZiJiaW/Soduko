#pragma once
#ifndef SudokuMaker_H
#define SudokuMaker_H
#define FirstNumber (9+6)%9+1
using namespace std;
class SudokuMaker {
public:
    void StartGenerating(char *ret);
    void RequestInit(int n);//��ʼ������
private:
    int maxnum;//��Ҫ���ɵ������վ���
    int count;//��ǰ�����ɵ������վ���
    int Matrix[9][9];//ά������������
    bool Fill(int r, int l, char *ret);//�ݹ�����
    bool Check(int r, int l, int num);//�ж���[r,l]������num�Ƿ������������
};
#endif // !SudokuMaker_H
