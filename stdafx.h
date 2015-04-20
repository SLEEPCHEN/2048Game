// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <random>
#include <stack>

const int MartrixSize = 4;
bool EventHandler(DWORD eventType);
inline void PrintMartrix(int (&arr)[MartrixSize][MartrixSize]);
void StepToUp(int (&arr)[MartrixSize][MartrixSize]);
void StepToDown(int (&arr)[MartrixSize][MartrixSize]);
void StepToLeft(int (&arr)[MartrixSize][MartrixSize]);
void StepToRight(int (&arr)[MartrixSize][MartrixSize]);
bool RandomGenerate(int (&arr)[MartrixSize][MartrixSize]);
int GetMax(int (&arr)[MartrixSize][MartrixSize]);

// TODO: 在此处引用程序需要的其他头文件
