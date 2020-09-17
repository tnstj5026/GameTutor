#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

// 윈도우의 초기 크기
#define DEFAULT_WIDTH  1200
#define DEFAULT_HEIGHT 720

// 크기를 변수로 저장
int width = DEFAULT_WIDTH;
int height = DEFAULT_HEIGHT;

void drawDisplay(float x_size, float y_size, float pos_x, float pos_y)
{
	glBegin(GL_QUADS);

	glTexCoord2i(0, 1); glVertex2i(pos_x, pos_y);
	glTexCoord2i(0, 0); glVertex2i(pos_x, pos_y + y_size); 
	glTexCoord2i(1, 0); glVertex2i(pos_x + x_size, pos_y + y_size);
	glTexCoord2i(1, 1); glVertex2i(pos_x + x_size, pos_y);
	glEnd();
}