// stdafx.cpp : 只包括标准包含文件的源文件
// 2048Game.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

extern const int MartrixSize;

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用


inline void PrintMartrix(int (&arr)[MartrixSize][MartrixSize])
{
	std::cout << "/------|------|------|------\\" << std::endl;
	for(int i=0;i<4;++i)
	{
		std::cout << '|' ;
		for(int j=0;j<4;++j)
		{
			if(arr[i][j]!=0)
				std::cout << std::setw(6) << arr[i][j] << '|';
			else
				std::cout << std::setw(7) << '|';
		}
		std::cout << std::endl;
		if(i!=3)
			std::cout << "|------|------|------|------|" << std::endl;
	}
	std::cout << "\\------|------|------|------/" << std::endl;
}
void StepToUp(int (&arr)[MartrixSize][MartrixSize])
{
	int k,temp;
	for(int i=0;i<MartrixSize;++i)
	{
		k = 0;
		for(int j=0;j<MartrixSize;++j)
		{
			if(arr[j][i]!=0)
				arr[k++][i] = arr[j][i];
		}
		while(k < MartrixSize)
		{
			arr[k++][i] = 0;
		}

		k = 0;
		for(int j=0;j<MartrixSize-1;++j)
		{
			if(arr[j][i]!=0 && arr[j][i]==arr[j+1][i])
			{
				temp = arr[j][i]<<1;
				arr[j][i] = 0;
				arr[j+1][i] = 0;
				arr[k][i] = temp;
				++k;
				++j;
			}
			else if(arr[j][i]!=0 && arr[j][i]!=arr[j+1][i])
			{
				temp = arr[j][i];
				arr[j][i] = 0;
				arr[k][i] = temp;
				++k;
			}
		}
		if(arr[MartrixSize-1][i]!=0)
		{
			temp = arr[MartrixSize-1][i];
			arr[MartrixSize-1][i] = 0;
			arr[k][i] = temp;
		}
	}
	if(!RandomGenerate(arr))
	{
		std::cout << "Game Over! Your Score is " << GetMax(arr) << std::endl;
		exit(0);
	}
	system("cls");
	PrintMartrix(arr);
}
void StepToDown(int (&arr)[MartrixSize][MartrixSize])
{
	int k,temp;
	for(int i=0;i<MartrixSize;++i)
	{
		k = MartrixSize-1;
		for(int j=MartrixSize-1;j>=0;--j)
		{
			if(arr[j][i]!=0)
				arr[k--][i] = arr[j][i];
		}
		while(k >= 0)
		{
			arr[k--][i] = 0;
		}

		k = MartrixSize-1;
		for(int j=MartrixSize-1;j>0;--j)
		{
			if(arr[j][i]!=0 && arr[j][i]==arr[j-1][i])
			{
				temp = arr[j][i]<<1;
				arr[j][i] = 0;
				arr[j-1][i] = 0;
				arr[k][i] = temp;
				--k;
				--j;
			}
			else if(arr[j][i]!=0 && arr[j][i]!=arr[j-1][i])
			{
				temp = arr[j][i];
				arr[j][i] = 0;
				arr[k][i] = temp;
				--k;
			}
		}
		if(arr[0][i]!=0)
		{
			temp = arr[0][i];
			arr[0][i] = 0;
			arr[k][i] = temp;
		}
	}
	if(!RandomGenerate(arr))
	{
		std::cout << "Game Over! Your Score is " << GetMax(arr) << std::endl;
		exit(0);
	}
	system("cls");
	PrintMartrix(arr);
}
void StepToLeft(int (&arr)[MartrixSize][MartrixSize])
{
	int k,temp;
	for(int i=0;i<MartrixSize;++i)
	{
		k = 0;
		for(int j=0;j<MartrixSize;++j)
		{
			if(arr[i][j]!=0)
				arr[i][k++] = arr[i][j];
		}
		while(k < MartrixSize)
		{
			arr[i][k++] = 0;
		}

		k = 0;
		for(int j=0;j<MartrixSize-1;++j)
		{
			if(arr[i][j]!=0 && arr[i][j]==arr[i][j+1])
			{
				temp = arr[i][j]<<1;
				arr[i][j] = 0;
				arr[i][j+1] = 0;
				arr[i][k] = temp;
				++k;
				++j;
			}
			else if(arr[i][j]!=0 && arr[i][j]!=arr[i][j+1])
			{
				temp = arr[i][j];
				arr[i][j] = 0;
				arr[i][k] = temp;
				++k;
			}
		}
		if(arr[i][MartrixSize-1]!=0)
		{
			temp = arr[i][MartrixSize-1];
			arr[i][MartrixSize-1] = 0;
			arr[i][k] = temp;
		}
	}
	if(!RandomGenerate(arr))
	{
		std::cout << "Game Over! Your Score is " << GetMax(arr) << std::endl;
		exit(0);
	}
	system("cls");
	PrintMartrix(arr);
}
void StepToRight(int (&arr)[MartrixSize][MartrixSize])
{
	int k,temp;
	for(int i=0;i<MartrixSize;++i)
	{
		k = MartrixSize-1;
		for(int j=MartrixSize-1;j>=0;--j)
		{
			if(arr[i][j]!=0)
				arr[i][k--] = arr[i][j];
		}
		while(k >= 0)
		{
			arr[i][k--] = 0;
		}

		k = MartrixSize-1;
		for(int j=MartrixSize-1;j>0;--j)
		{
			if(arr[i][j]!=0 && arr[i][j]==arr[i][j-1])
			{
				temp = arr[i][j]<<1;
				arr[i][j] = 0;
				arr[i][j-1] = 0;
				arr[i][k] = temp;
				--k;
				--j;
			}
			else if(arr[i][j]!=0 && arr[i][j]!=arr[i][j-1])
			{
				temp = arr[i][j];
				arr[i][j] = 0;
				arr[i][k] = temp;
				--k;
			}
		}
		if(arr[i][0]!=0)
		{
			temp = arr[i][0];
			arr[i][0] = 0;
			arr[i][k] = temp;
		}
	}
	if(!RandomGenerate(arr))
	{
		std::cout << "Game Over! Your Score is " << GetMax(arr) << std::endl;
		exit(0);
	}
	system("cls");
	PrintMartrix(arr);
}

int GetMax(int (&arr)[MartrixSize][MartrixSize])
{
	int maxVal = 0;
	for(int i=0;i<MartrixSize;++i)
	{
		for(int j=0;j<MartrixSize;++j)
		{
			if(arr[i][j]>maxVal)
				maxVal = arr[i][j];
		}
	}
	return maxVal;
}
bool RandomGenerate(int (&arr)[MartrixSize][MartrixSize])
{
	std::uniform_int_distribution<unsigned> u(0,MartrixSize-1);
	std::default_random_engine e(time(0));

	int row = u(e),colum = u(e);
	int i = 0;
	while(arr[row][colum]!=0)
	{
		row = u(e),colum = u(e);
		++i;
		if(i>100)
			return false;
	}
	arr[row][colum] = 2;
	return true;
}
bool EventHandler(DWORD eventType)
{
	std::cout << "0000000000\n";
	switch(eventType)
	{
	case VK_UP:
		std::cout << "UP\n";
		break;
	case VK_DOWN:
		std::cout << "DOWN\n";
		break;
	case VK_LEFT:
		std::cout << "LEFT\n";
		break;
	case VK_RIGHT:
		std::cout << "RIGHT\n";
		break;
	default:
		std::cout << "OTHER\n";
		break;
	}
	return true;
}