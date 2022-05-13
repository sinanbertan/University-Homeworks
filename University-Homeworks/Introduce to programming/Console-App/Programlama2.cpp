/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI:2
**				ÖÐRENCÝ ADI:SÝNAN BAVLÝ
**				ÖÐRENCÝ NUMARASI:G201210381
**				DERS GRUBU:2.Ö B
****************************************************************************/





#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
using namespace std;


class Roof {
private:
	int roofheight;
	int width;
	int x;
	int y;

public:
	char tool ='*';
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}


	void setRoofheight(int rh) {
		this->roofheight = rh;
	}
	int getRoofheight() {
		return roofheight;
	}

	void drawR(int h, int w, int x, int y) {
		
		roofheight = h;
		width = w;
		this->x = x;
		this->y = y;
		int z = 1;
		for (int i = 0; i <roofheight ; i++) {
			gotoxy(x + roofheight- 1-i, y + i);
			for (int j = 0; j <= width-roofheight*2+2*i+2; j++) {
				Sleep(15);
				cout << tool;
			}
		}
	}
	
	
	
	

	
};

class Floor{
private:
	int height;
	int width;
	int x;
	int y;
	
public:
	char tool = 219;
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void drawF(int h, int w, int x, int y) {
		height = h;
		width = w;
		this->x = x;
		this->y = y;
		for (int i = 0; i <= width; i++) {
			gotoxy(x + i, y);
			Sleep(15);
			cout << tool;
		}

		for (int i = 0; i <= height; i++) {
			gotoxy(x + width, y + i);
			Sleep(15);
			cout << tool << endl;
		}

		for (int i = 0; i <= width; i++) {
			gotoxy(x + width- i, y +height);
			Sleep(15);
			cout << tool;
		}

		for (int i = 0; i <= height; i++) {
			gotoxy(x, y+i);
			Sleep(15);
			cout << tool << endl;
		}
	}
	


	


};

class Door {
private:
	int height;
	int width;
	int x;
	int y;

public:
	void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	char tool = '#';
	void drawD(int h,int w,int x, int y ) {
		height = h;
		width = w;
		this->x = x;
		this->y = y;

		for (int i = 0; i < height; i++) {
			gotoxy(x, y - i);
			for (int j = 0; j <= width; j++) {
				Sleep(20);
				cout << tool;
			}

		}
	}

};

class Home:public Door,public Floor,public Roof {

private:
	int height;
	int width;
	int x;
	int y;
public:
	
	void setHeight(int h) {
		this->height = h;
	}
	int getHeight() {
		return height;
	}
	void setWidth(int w) {
		this->width = w;
	}
	int getWidth() {
		return width;
	}

	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}

	void setY(int y) {
		this->y = y;
	}
	int getY() {
		return height;
	}
	Roof r;
	Floor f;
	Door d;
	void start() {
		r.drawR(getRoofheight(),width,x,y);
		f.drawF(height,width,x,y+getRoofheight());
		d.drawD(height / 3, width / 4, x + width / 3, y +getRoofheight()+height);
	}


};

int main()
{
	
	Home home;
	
	
	int yk;
	int gn;
	int x1;
	int y1;
	int cyk;

	cout << "yukseklik giriniz:"; cin >> yk;
	cout << "genislik giriniz:"; cin >> gn;
	cout << "cati yuksekligi:"; cin >> cyk;
	cout << "x koordinatini giriniz:"; cin >> x1;
	cout << "y koordinatini giriniz"; cin >> y1;

	home.setHeight(yk);
	home.setWidth(gn);
	home.setX(x1);
	home.setY(y1);
	home.setRoofheight(cyk);

	home.start();
	cout << "\n\n\n\n\n\n\n\n\n";

	
	
	
	
	return 0;
}

