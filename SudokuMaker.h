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
    bool fill(int r, int l, char *ret);//�ݹ�����
    bool check(int r, int l, int num);//�ж���[r,l]������num�Ƿ������������
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
    void RequestInit(int n);//��ʼ������
private:
    int maxnum;//��Ҫ���ɵ������վ���
    int count;//��ǰ�����ɵ������վ���
<<<<<<< HEAD
    int Matrix[9][9];//ά������������
    bool Check(int r, int l, int num);//�ж���[r,l]������num�Ƿ������������
    bool Fill(int r, int l, char *ret);//�ݹ�����
=======
    int M[9][9];//ά������������
>>>>>>> ec2137a00db2bb2af1a748e82166cc33c221a969
};
#endif // !SudokuMaker_H
