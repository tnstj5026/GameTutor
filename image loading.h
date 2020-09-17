#pragma once // ���̺귯���� �ߺ��ؼ� �������� �ʵ��� ����

#include <stdio.h> // ���� ����� �Լ��� ���Ե� ǥ�� ����� ���̺귯��
#include <Windows.h> // ��Ʈ�� �����Ϳ� ���� ���ǵǾ� �ִ� ���̺귯��
#include <glut.h> // �̹��� ó���� ���õ� �Լ����� ���̺귯��

#define GL_BGRA 0x80E1 // �̹��� �ȼ��� ���� �� �ϳ��� 32��Ʈ bmp ������ ������ ��������

GLuint LoadTexture(const char* filename) // �׸��� ����� ��ǥ ���� �ҷ��ͼ� �����صδ� �Լ�
{
	FILE *fp = fopen(filename, "rb"); // ����ڰ� ���ϴ� ����� �̹��� ���� ����
	if(!fp) // ���� �ε��� ������ ���
	{
		return -1; // �׸� ���� �޸𸮴� 0���� �����ϴµ� �ش��Լ��� �޸� ������ ��ȯ�ؾ� �ϹǷ� ���нÿ� ���� ��ȯ
	}

	BITMAPFILEHEADER bfh; // ��Ʈ�� �̹��� ���� ���
	BITMAPINFOHEADER bih; // ��Ʈ�� �̹��� ���� ���

	// ������ ���� ��Ʈ�� �ε�
	fread(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);
	fread(&bih, 1, sizeof(BITMAPINFOHEADER), fp);
	fseek(fp, bfh.bfOffBits, SEEK_SET);// �߰��� ���̰��� �������� ������ ��Ȯ�ϰ� �̷����ؼ� ����Ÿ ���� ����Ʈ�� ã�ư���

	int internalFormat=GL_BGRA; // ���� ������ 32��Ʈ�� ���� (Alpha�� ��� ����)

	if(bih.biBitCount != 32) // 32��Ʈ ������ �ƴ� ��� ���Ϸε� ���з� ����
	{
		fclose(fp);
		return -1;
	} 

	GLuint texture; // ����� �׸� ���� ����

	unsigned char *data = new unsigned char[bih.biSizeImage]; // ��Ʈ���� ���� ������ �����ϴ� �迭
	fread(data, 1, bih.biSizeImage, fp); // ���Ͽ��� �����͸� �ε�

	// �̹����� �� ������ �޸𸮿� �Ѱ��ִ� ����
	glGenTextures(1, &texture); // ������ ������ ���� �Ҵ�
	glBindTexture(GL_TEXTURE_2D, texture); // ������ ���� �غ�
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bih.biWidth, bih.biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, data); // Ȯ���� ������ ������ ����
	// �̹��� �̿���� ����
	(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	fclose(fp); // ���� �ݱ�

	return texture; // ����� �̹��� ������ �޸� ���� �� ���� ��ȯ
}

void FreeTexture(GLuint texture) // �ش� ������ �̹��� �޸𸮸� �����ϴ� �Լ�
{
	glDeleteTextures(1, &texture);
}