#pragma once

#include <stdio.h>
#include <MMsystem.h> // ���� �̿� ���� ���� ���̺귯��
#pragma comment(lib,"winmm.lib") // ���� ��� ���̺귯�� ���� ���� ���� 

bool music=false;

void sub_menu1(int id) // ��� ����
{
	switch(id)
	{
		case 1: printf("upper case 'A'\n");
				break;
		case 2: printf("upper case 'B'\n");
				break;
	}
}

void sub_menu2(int id) // ���� �� ����
{
	switch(id)
	{
		case 1: printf("lower case 'a'\n");
				break;
		case 2: printf("lower case 'b'\n");
				break;
	}
}

void top_menu(int id) // �޴� ����
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