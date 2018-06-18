#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;


int main()
{
	GdiplusStartupInput gdiplusstartupinput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, nullptr);

	wstring infilename(L"atom.jpg");
	string outfilename("color.txt");
	//¶ÁÍ¼Æ¬
	Bitmap* bmp = new Bitmap(infilename.c_str());
	UINT height = bmp->GetHeight();
	UINT width = bmp->GetWidth();
	cout << "width " << width << ", height " << height << endl;

	Color color;
	ofstream fout(outfilename.c_str());

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++) {
			bmp->GetPixel(x, y, &color);
			fout << x << "	" << y << "	"
				<< (int)color.GetRed() << "	"
				<< (int)color.GetGreen() << "	"
				<< (int)color.GetBlue() << endl;
		}

	fout.close();

	delete bmp;
	GdiplusShutdown(gdiplustoken);
	return 0;
}