#pragma once
#ifndef SodukoInput_H
#define SodukoInput_H
using namespace std;
vector<int(*)[9]> SodukoInput(char * filename);
bool IsDigit(char *in);
#endif // !SodukoInput_H
