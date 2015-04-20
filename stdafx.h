// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
