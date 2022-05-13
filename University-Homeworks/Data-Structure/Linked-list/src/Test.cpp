/**
* @file Test.cpp
* @description ana kaynak dosya
* @course 1.Öğretim C grubu
* @assignment 1.Ödev
* @date 14/11/2021
* @author Sinan Bavli-sinan.bavli@ogr.sakarya.edu.tr
*/

#include "List.hpp"
#include <fstream>

int main(){
	List *names = new List();
	int opt=0;
	string name;
	int index;
	string a;
	//doc altında ki text dosyasını okuma ve listeye ekleme kodu
	ifstream fileName(".//doc//names.txt");
	while(getline(fileName,a)){
		names->add(a+"<->");
	};
	
	
	do{
		system("CLS");
		
		
		cout<<"1.Girilen konuma isim ekle:"<<endl;
		cout<<"2.Girilen konumdan ilgili ismi sil:"<<endl;
		cout<<"3.Mevcut isimleri listele:"<<endl;
		cout<<"4.Mevcut isimleri temizle:"<<endl;
		cout<<"5.Cikis yap:"<<endl;
		cout<<"Secim:";
		cin>>opt;
		system("CLS");
		switch(opt){
			case 1:
					cout<<"Konum:";
					cin>>index;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,name);
					names->insert(index,name+"<->");
			break;
			case 2:
					cout<<"Konum:";
					cin>>index;
					names->removeAt(index);	
			break;
			case 3:			
				cout<<*names<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 4:
				names->clear();
				cout<<endl<<"Bütün isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			break;
		
			case 5:
			break;
			default:
				cout<<endl<<"Yanlis secim.."<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(opt != 14);
	delete names;
	return 0;
}