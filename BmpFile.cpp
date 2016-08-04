#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "BmpFile.h"


using namespace std;

BmpFile::BmpFile()
{
	pBmpBuf = NULL;
	bmpWidth = 0;
	bmpHeight = 0;
	pColorTable = NULL;
	biBitCount = 0;
	lineByte = 0;
}

BmpFile::BmpFile(char *bmpName)
{
	pBmpBuf = NULL;
	bmpWidth = 0;
	bmpHeight = 0;
	pColorTable = NULL;
	biBitCount = 0;
	lineByte = 0;
	readBmp(bmpName);
}

BmpFile::~BmpFile()
{
	if (pBmpBuf != NULL)
	{
		delete[]pBmpBuf;
	}

	if (pColorTable != NULL)
	{
		delete[]pColorTable;
	}
}

Vector3 BmpFile::getPixiv(int _x, int _y)
{
	if (pBmpBuf == NULL){
		printf("error in getPixiv where _x=%d  _y = %d \nthese no bmp\n", _x, _y);
		return Vector3(0);
	}

	if (_x >= bmpWidth || _y >= bmpHeight)
	{
		printf("error in getPixiv where \nbmpWidth:%d  bmpHeight:%d  and\n_x=%d  _y = %d\n", bmpWidth, bmpHeight, _x, _y);
		return Vector3(0);
	}

	int b = *(pBmpBuf + _y*lineByte + _x * 3);
	int g = *(pBmpBuf + _y*lineByte + _x * 3 + 1);
	int r = *(pBmpBuf + _y*lineByte + _x * 3 + 2);

	return Vector3(r, g, b);
}

bool BmpFile::readBmp(char *bmpName)
{
	FILE *fp;
	fopen_s(&fp, bmpName, "rb");//�����ƶ���ʽ��ָ����ͼ���ļ�

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER

	fseek(fp, sizeof(BITMAPFILEHEADER), 0);

	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��

	BITMAPINFOHEADER head;

	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ

	bmpWidth = head.biWidth;

	bmpHeight = head.biHeight;

	biBitCount = head.biBitCount;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����

	lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256

	if (biBitCount == 8)
	{

		//������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�

		pColorTable = new RGBQUAD[256];

		fread(pColorTable, sizeof(RGBQUAD), 256, fp);

	}

	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�

	pBmpBuf = new unsigned char[lineByte * bmpHeight];

	fread(pBmpBuf, 1, lineByte * bmpHeight, fp);

	fclose(fp);//�ر��ļ�

	return 1;//��ȡ�ļ��ɹ�
}


//����һ��ͼ��λͼ���ݡ����ߡ���ɫ��ָ�뼰ÿ������ռ��λ������Ϣ,����д��ָ���ļ���
bool BmpFile::saveBmp(char *bmpName)
{

	//���λͼ����ָ��Ϊ0����û�����ݴ��룬��������
	if (!pBmpBuf)
		return 0;

	//��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0

	int colorTablesize = 0;

	if (biBitCount == 8)
		colorTablesize = 1024;

	//���洢ͼ������ÿ���ֽ���Ϊ4�ı���

	int lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;

	//�Զ�����д�ķ�ʽ���ļ�
	FILE *fp;
	fopen_s(&fp, bmpName, "wb");

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ

	BITMAPFILEHEADER fileHead;

	fileHead.bfType = 0x4D42;//bmp����

	//bfSize��ͼ���ļ�4����ɲ���֮��

	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte*bmpHeight;

	fileHead.bfReserved1 = 0;

	fileHead.bfReserved2 = 0;

	//bfOffBits��ͼ���ļ�ǰ3����������ռ�֮��

	fileHead.bfOffBits = 54 + colorTablesize;

	//д�ļ�ͷ���ļ�

	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);

	//����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ

	BITMAPINFOHEADER head;

	head.biBitCount = biBitCount;

	head.biClrImportant = 0;

	head.biClrUsed = 0;

	head.biCompression = 0;

	head.biHeight = bmpHeight;

	head.biPlanes = 1;

	head.biSize = 40;

	head.biSizeImage = lineByte*bmpHeight;

	head.biWidth = bmpWidth;

	head.biXPelsPerMeter = 0;

	head.biYPelsPerMeter = 0;

	//дλͼ��Ϣͷ���ڴ�

	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);

	//����Ҷ�ͼ������ɫ��д���ļ� 

	if (biBitCount == 8)
		fwrite(pColorTable, sizeof(RGBQUAD), 256, fp);

	//дλͼ���ݽ��ļ�

	fwrite(pBmpBuf, bmpHeight*lineByte, 1, fp);

	//�ر��ļ�

	fclose(fp);

	return 1;

}

