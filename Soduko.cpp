// Soduko.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"SodukoInput.h"
using namespace std;
int main(int argc, char *argv[])
{
	/*
	if (argc != 3)
	{
		cout << "illegal input" << endl;
		return -1;
	}*/
//	if (strcmp(argv[1], "-s"))
	{
		vector<int(*)[9]> ProblemSet = SodukoInput("e:\\visual studio 2017 project\\Soduko\\Soduko\\sudoku.txt");
		for (auto p : ProblemSet)
		{
			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; ++j)
				{
					if (j == 8)
						cout << p[i][j] << endl;
					else
						cout << p[i][j] << ' ';
				}
			}
		}
	}
	return 0;
}

