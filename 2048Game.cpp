// 2048Game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern const int MartrixSize;

int _tmain(int argc, _TCHAR* argv[])
{
	//{
	//	std::uniform_int_distribution<unsigned> u(0,5);
	//	std::default_random_engine e(time(0));
	//	for(int i=0;i<10;++i)
	//		std::cout << u(e) << ' ';
	//	std::cout << std::endl;
	//	return 0;
	//}

	if(false)
	{
		int arr[MartrixSize][MartrixSize] = {{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};
		PrintMartrix(arr);
		StepToUp(arr);
		//PrintMartrix(arr);
		//StepToUp(arr);
		StepToDown(arr);
		//PrintMartrix(arr);
		StepToRight(arr);
		StepToLeft(arr);
		return 0;
	}

	{
		HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
		INPUT_RECORD keyrec;
		DWORD res;
		int arr[MartrixSize][MartrixSize] = {0};
		RandomGenerate(arr);
		RandomGenerate(arr);

		PrintMartrix(arr);

		while(true)
		{
			ReadConsoleInput(handle,&keyrec,1,&res);
			if(keyrec.EventType==KEY_EVENT)
			{
				switch(keyrec.Event.KeyEvent.wVirtualKeyCode)
				{
				
				case VK_UP:
					StepToUp(arr);
					break;
				case VK_DOWN:
					//std::cout << "DOWN\n";
					StepToDown(arr);
					break;
				case VK_LEFT:
					//std::cout << "LEFT\n";
					StepToLeft(arr);
					break;
				case VK_RIGHT:
					//std::cout << "RIGHT\n";
					StepToRight(arr);
					break;
				default:
					std::cout << "OTHER\n";
					break;
				}
			}
			ReadConsoleInput(handle,&keyrec,1,&res);//if I press UP one time, UP will be triggered two times,so I put two ReadConsoleInput Function to hand another UP. 
		}
		return 0;
	}
}
