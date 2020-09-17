#pragma once
#pragma comment(lib,"winmm")
#include <mmsystem.h>
#include "Digitalv.h"

MCI_OPEN_PARMS mciOpen;   // MCI_OPEN_PARAMS 구조체 변수 
MCI_PLAY_PARMS mciPlay; 
DWORD dwID;

void bgm_start(LPCWSTR filename)
{
	// 파일 열기
	mciOpen.lpstrDeviceType = L"mpegvideo";  // mpegvideo : mp3, waveaudio : wav, avivideo : avi
	mciOpen.lpstrElementName = filename; // 파일이름
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE|MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

	// 재생
	dwID = mciOpen.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay); 
	//MCI_NOTIFY : 기본, MCI_DGV_PLAY_REPEAT : 반복
}

void bgm_restart()
{
	//다시시작
	mciSendCommandW(dwID, MCI_RESUME, 0, NULL); 
}

void bgm_pause()
{
	// 일시정지
	mciSendCommand(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay); 
}

void bgm_stop()
{
	// 정지
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
}