#pragma once
#ifndef SodukoInput_H
#define SodukoInput_H
using namespace std;
vector<int(*)[9]> SudokuInput(char * filename);
bool IsDigit(char *in);
#endif // !SodukoInput_H