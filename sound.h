#pragma once
#pragma comment(lib,"winmm")
#include <mmsystem.h>
#include "Digitalv.h"

MCI_OPEN_PARMS mciOpen;   // MCI_OPEN_PARAMS ����ü ���� 
MCI_PLAY_PARMS mciPlay; 
DWORD dwID;

void bgm_start(LPCWSTR filename)
{
	// ���� ����
	mciOpen.lpstrDeviceType = L"mpegvideo";  // mpegvideo : mp3, waveaudio : wav, avivideo : avi
	mciOpen.lpstrElementName = filename; // �����̸�
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE|MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

	// ���
	dwID = mciOpen.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay); 
	//MCI_NOTIFY : �⺻, MCI_DGV_PLAY_REPEAT : �ݺ�
}

void bgm_restart()
{
	//�ٽý���
	mciSendCommandW(dwID, MCI_RESUME, 0, NULL); 
}

void bgm_pause()
{
	// �Ͻ�����
	mciSendCommand(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay); 
}

void bgm_stop()
{
	// ����
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
}