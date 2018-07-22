#include<iostream>
#include<Windows.h>
#include<math.h>
#include "imge.h"
using namespace std;

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR FILE)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(FILE, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

					 // read file header
	if (ReadFile(file, &bmpheader, sizeof(BITMAPFILEHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof(BITMAPINFOHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB') {
		CloseHandle(file);
		return NULL;
	}
	// get image measurements
	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB) {
		CloseHandle(file);
		return NULL;
	}
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		CloseHandle(file);
		return NULL;
	}

	// create buffer to hold the data
	size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[size];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Buffer, size, &bytesread, NULL) == false) {
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}
//LOADPMB

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer,
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}

	return newbuf;
}
//ConvertBMPToIntensity

BYTE* ConvertMasks(BYTE* Buffer, int width, int height) {
	
	int row, col, i;
	BYTE *p0, *p1, *p2;

	BYTE* newbuf2 = new BYTE[width*height];

	//int mean[3 * 3] = { 1 / 9,1 / 9,1 / 9,1 / 9,1 / 9,1 / 9,1 / 9,1 / 9,1 / 9 };
	int Gauss[3 * 3]{ 1/4 , 1/2 , 1/4 , 1/2 , 1 , 1/2 , 1/4 , 1/2 , 1/4 };

	p0 = Buffer;
	p1 = p0 + width;
	p2 = p1 + width;
	for (i = 0; i < 3; i++)
		*newbuf2 = p0[i] + p1[i] + p2[i];


	for (row = 0; row< height; row++)
		for (col = 0; col < width; col++)
		{
			//newbuf2 += intensity[row - 1, col - 1] * mean[row - 1, col - 1];
			newbuf2 += Buffer[row - 1, col - 1] * Gauss[row - 1, col - 1];
		}

	return newbuf2;
}
//ConvertMask

int* HistogramFunc(BYTE * intensity, int width, int height)
{
	int* hist = new int[width*height];

	for (int i = 0; i < width*height; i++)
		hist[i] = 0;

	for (int i= 0; i < width*height; i++){
		hist[intensity[i]]++;
         }
	return hist;
}
//HistogramFunc

BYTE* historize(BYTE * intensity, int width, int height)
{
	BYTE* buff = new BYTE[width * height];

	for (int i = 0; i < width * height; i++)
		buff[i] = 0;


	int t_low = 50;
	int t_high = 100;

	for (int i = 0; i <  width * height; i++)
	{
		if (intensity[i] <= t_low)
			buff[i] = 0;
		if (intensity[i] >= t_high)
			buff[i] = 255;
		if (intensity[i] > t_low && intensity[i] < t_high)
			buff[i] = 1;
	}

	for (int i = 0; i <  width * height; i++)
		if (buff[i] == 1)
			if (buff[i - width + 1] == 255 && buff[i + width - 1] == 255)
				buff[i] = 255;

	return buff;
}
////historize

BYTE* thresholding(BYTE* intensity, int width, int height){

	int* hist2 = new int[width*height];
	for (int i = 0; i < width * height; i++)
		hist2[i] = 0;

	

	BYTE* binary = new BYTE[width * height];
	hist2 = HistogramFunc(intensity, width, height);

	int t1 = 0, t2 = 255, t12 = 1, t22 = 1;
	int a = 0, b = 0;

	while (1)
	{
		for (int i = 0; i < 255; i++)
		{
			if (-(t1 - i) < (t2 - i))
				hist2[i] = 1;
			else
				hist2[i] = 2;
		}
		for (int j = 0; j < 255; j++)
			if (hist2[j] == 1)
				a = a + j, b++;
		t12 = a / b, a = 0, b = 0;

		for (int k = 0; k < 255; k++)
			if (hist2[k] == 2)
				a = a + k, b++;
		t22 = a / b, a = 0, b = 0;

		if (t1 == t12 && t2 == t22)
			break;
		else
		{
			t1 = t12, t12 = 0;
			t2 = t22, t22 = 0;
		}
	}

	int T = t12+ abs(t12 - t22) / 2;
	//int T = sqrt((t12 - t22)*(t22-t12));

	for (int x = 0; x < width*height; x++)
		binary[x] = 0;

	for (int i = 0; i < width*height; i++)
		if (intensity[i] >= T)
			binary[i] = 255;
		else
			binary[i] = 0;

	return binary;
}
//thresholding
