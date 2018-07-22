#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR FILE);
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertMasks(BYTE* intensity, int width, int height);
int* HistogramFunc(BYTE* intensity, int width, int height);
BYTE* thresholding(BYTE * intensity, int width, int height);
BYTE* historize(BYTE* intensity, int width, int height);



