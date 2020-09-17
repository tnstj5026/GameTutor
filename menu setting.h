#pragma once

#include <stdio.h>
#include <MMsystem.h> // 사운드 이용 관련 정보 라이브러리
#pragma comment(lib,"winmm.lib") // 사운드 재생 라이브러리 직접 참조 설정 

bool music=false;

void sub_menu1(int id) // 모드 선택
{
	switch(id)
	{
		case 1: printf("upper case 'A'\n");
				break;
		case 2: printf("upper case 'B'\n");
				break;
	}
}

void sub_menu2(int id) // 조명 색 선택
{
	switch(id)
	{
		case 1: printf("lower case 'a'\n");
				break;
		case 2: printf("lower case 'b'\n");
				break;
	}
}

void top_menu(int id) // 메뉴 선택
{
	switch(id)
	{
		case 1: if(music==false)
				{
					PlaySound(TEXT("BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
					music=true;
				}
				else
				{
					PlaySound(NULL,NULL,NULL);
					music=false;
				}
				break;
	}
}