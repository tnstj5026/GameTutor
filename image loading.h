#pragma once // 라이브러리를 중복해서 포함하지 않도록 설정

#include <stdio.h> // 파일 입출력 함수가 포함된 표준 입출력 라이브러리
#include <Windows.h> // 비트맵 데이터에 대해 정의되어 있는 라이브러리
#include <glut.h> // 이미지 처리와 관련된 함수들의 라이브러리

#define GL_BGRA 0x80E1 // 이미지 픽셀의 포맷 중 하나로 32비트 bmp 파일이 가지는 정보형태

GLuint LoadTexture(const char* filename) // 그림의 색상과 좌표 값을 불러와서 저장해두는 함수
{
	FILE *fp = fopen(filename, "rb"); // 사용자가 원하는 경로의 이미지 파일 선택
	if(!fp) // 파일 로딩이 실패한 경우
	{
		return -1; // 그림 저장 메모리는 0부터 시작하는데 해당함수가 메모리 순서를 반환해야 하므로 실패시에 음수 반환
	}

	BITMAPFILEHEADER bfh; // 비트맵 이미지 파일 헤더
	BITMAPINFOHEADER bih; // 비트맵 이미지 정보 헤더

	// 파일을 통해 비트값 로딩
	fread(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);
	fread(&bih, 1, sizeof(BITMAPINFOHEADER), fp);
	fseek(fp, bfh.bfOffBits, SEEK_SET);// 중간에 더미값이 있을수도 있으니 정확하게 이렇게해서 데이타 시작 바이트를 찾아가자

	int internalFormat=GL_BGRA; // 내부 포맷은 32비트로 지정 (Alpha값 사용 목적)

	if(bih.biBitCount != 32) // 32비트 파일이 아닌 경우 파일로딩 실패로 간주
	{
		fclose(fp);
		return -1;
	} 

	GLuint texture; // 저장된 그림 순서 변수

	unsigned char *data = new unsigned char[bih.biSizeImage]; // 비트맵의 색상 정보를 저장하는 배열
	fread(data, 1, bih.biSizeImage, fp); // 파일에서 데이터를 로딩

	// 이미지의 색 정보를 메모리에 넘겨주는 과정
	glGenTextures(1, &texture); // 저장할 공간의 순서 할당
	glBindTexture(GL_TEXTURE_2D, texture); // 저장할 공간 준비
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bih.biWidth, bih.biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, data); // 확보된 공간에 데이터 전송
	// 이미지 이용관련 설정
	(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	fclose(fp); // 파일 닫기

	return texture; // 저장된 이미지 정보의 메모리 공간 상 순서 반환
}

void FreeTexture(GLuint texture) // 해당 순서의 이미지 메모리를 해제하는 함수
{
	glDeleteTextures(1, &texture);
}