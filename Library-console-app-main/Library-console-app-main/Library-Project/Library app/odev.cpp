/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:Proje/Tasarým
**				ÖÐRENCÝ ADI...............:Sinan Bavli
**				ÖÐRENCÝ NUMARASI.:G201210381
**				DERS GRUBU…………:2.ÖÐRETÝM B
****************************************************************************/



#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sal.h>
#include <time.h>
#pragma optimize) "l", on ) 
#pragma warning(disable : 4996);

using namespace std;
//OKUYUCULAR SINIFI
class Readers {
public:

	string TcNo;
	string Rname;
	string Rsurname;
	string RmemNo;
	string Phone;
	string Bdate;
	string Job;
	string Capacity;

	void ShowReaders() {
		cout << TcNo << " " << Rname << " " << Rsurname << " " << RmemNo << " " << Phone << " " << Bdate << " " << Job << " " << Capacity << endl;
	}
};

//KÝTAPLAR SINIFI
class Books {
public:
	string ISBN;
	string Bname;
	string Aname;
	string Asurname;
	string Topic;
	string Type;
	string PageCount;

	void showBooks() {
		cout << ISBN << " " << Bname << " " << Aname << " " << Asurname << " " << Topic << " " << Type << " " << PageCount << "\n";
	}
};

//ÖDÜNÇ SINIFI
class Borrow{
public:
	string BorrowDate;
	string ReturnDate;
	Readers r;
	Books b;


	void showBorrowed() {
		cout << r.TcNo << " " << b.ISBN << " " << b.Bname << " " << BorrowDate <<  endl;
	}

};
//KULLANICILAR SINIFI
class User {

public:
	string UserName;
	string Password;
	string Entry;
	string Exit;
};

Readers r;
Books b;
User u;
Borrow bo;

//OKUYUCU KONTROL
bool ReaderControl(string Tc) {
	bool ctrl = 0;
	ifstream FileReader("readers.txt", ios::in);

	while (!FileReader.eof()) {
		FileReader >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
		if (Tc == r.TcNo) {
			ctrl = 1;
		}
	}
	FileReader.close();
	return ctrl;
}
//KÝTAP KONTROL
bool BookControl(string isbn) {
	bool ctrl = 0;
	ifstream FileBooks("books.txt");
	while (!FileBooks.eof()) {
		FileBooks >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
		if (b.ISBN == isbn) {
			ctrl = 1;
		}
	}
	FileBooks.close();
	return ctrl;
}

//OKUYUCU EKLEME
void AddReader() {
	ofstream WriteReader("readers.txt", ios::app);
	cout << "enter TC:"; cin >> r.TcNo;
	cout << "enter readername:"; cin >> r.Rname;
	cout << "enter readersurname:"; cin >> r.Rsurname;
	cout << "enter memberno:"; cin >> r.RmemNo;
	cout << "enter phonenumber:"; cin >> r.Phone;
	cout << "enter Birthday:"; cin >> r.Bdate;
	cout << "enter job:"; cin >> r.Job;
	cout << "enter BookCapacity:"; cin >> r.Capacity;
	WriteReader << r.TcNo << " \t" << r.Rname << " \t" << r.Rsurname << " \t" << r.RmemNo << "\t" << r.Phone << "\t " << r.Bdate << "\t " << r.Job << " \t" << r.Capacity << "\n";
	WriteReader.close();
}


//OKUYUCU GÜNCELLEME
void UpdateReader(string Tc) {
	ifstream FileReader;
	FileReader.open("readers.txt");
	ofstream FileTemp;
	FileTemp.open("temp.txt", ios::app);

	bool c = 0;
	if (ReaderControl(Tc) == 0) {
		cout << "There is no reader with this Tc!!" << endl;
	}
	else {
		c = 1;
		while (true) {
			if (FileReader.eof()) break;
			FileReader >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
			if (r.TcNo == Tc) {
				r.ShowReaders();
				cout << "1 update TC" << endl;
				cout << "2 update Readername" << endl;
				cout << "3 update ReaderSurname" << endl;
				cout << "4 update MemberNo" << endl;
				cout << "5 update phoneNumber" << endl;
				cout << "6 update Birthday" << endl;
				cout << "7 update Job" << endl;
				cout << "8 update BookCapacity" << endl;
				cout << "9 to exit" << endl;

				while (true) {
					int a;
					cout << "select an option:"; cin >> a;
					if (a == 1) {
						cout << "input new Tc no:"; cin >> r.TcNo;
					}
					if (a == 2) {
						cout << "input new name:"; cin >> r.Rname;
					}
					if (a == 3) {
						cout << "input new surname:"; cin >> r.Rsurname;
					}
					if (a == 4) {
						cout << "input new memberNo:"; cin >> r.RmemNo;
					}
					if (a == 5) {
						cout << "input new phoneNum:"; cin >> r.Phone;
					}
					if (a == 6) {
						cout << "input new birtday:"; cin >> r.Bdate;
					}
					if (a == 7) {
						cout << "input new job:"; cin >> r.Job;
					}
					if (a == 8) {
						cout << "input new bookcapacity:"; cin >> r.Capacity;
					}
					if (a == 9) {
						if (FileReader.eof())  break;
						FileTemp << r.TcNo << "\t" << r.Rname << "\t" << r.Rsurname << "\t " << r.RmemNo << "\t" << r.Phone << "\t " << r.Bdate << "\t" << r.Job << "\t" << r.Capacity << endl;
						goto exit1;
					}

				}

				if (FileReader.eof())  break;
				FileTemp << r.TcNo << "\t" << r.Rname << "\t" << r.Rsurname << "\t" << r.RmemNo << "\t" << r.Phone << "\t" << r.Bdate << "\t" << r.Job << "\t" << r.Capacity << endl;


			}
			else {
				if (FileReader.eof())  break;
				FileTemp << r.TcNo << "\t" << r.Rname << "\t" << r.Rsurname << "\t" << r.RmemNo << "\t" << r.Phone << "\t" << r.Bdate << " \t" << r.Job << "\t " << r.Capacity << endl;
			}

		}

	exit1:
		FileReader.close();
		FileTemp.close();
		if (c == 1) {
			remove("readers.txt");
			rename("temp.txt", "readers.txt");
		}
		else {
			remove("temp.txt");
		}
	}

}

//KÝTAP EKLEME
void AddBook() {
	ofstream BookFile("books.txt", ios::app);
	cout << "enter ISBN:"; cin >> b.ISBN;
	cout << "enter bookname:"; cin >> b.Bname;
	cout << "enter authorname:"; cin >> b.Aname;
	cout << "enter authorsurname:"; cin >> b.Asurname;
	cout << "enter topic:"; cin >> b.Topic;
	cout << "enter type:"; cin >> b.Type;
	cout << "enter pagecount:"; cin >> b.PageCount;
	BookFile << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
	BookFile.close();
}

//KÝTAP GÜNCELLEME
void UpdateBook(string isbn) {

	bool c = 0;
	if (BookControl(isbn) == 0) {
		cout << "There is no book with this ISBN!!" << endl;
	}
	else {
		ifstream FileBook;
		FileBook.open("books.txt");
		ofstream FileTemp;
		FileTemp.open("Btemp.txt", ios::app);

		c = 1;
		while (true) {
			if (FileBook.eof()) break;
			FileBook >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
			if (b.ISBN == isbn) {
				b.showBooks();
				cout << "1 update ISBN" << endl;
				cout << "2 update bookName" << endl;
				cout << "3 update AuthorName" << endl;
				cout << "4 update AuthorSurname" << endl;
				cout << "5 update topic" << endl;
				cout << "6 update type" << endl;
				cout << "7 update pagecount" << endl;
				cout << "8 to exit:" << endl;
				while (true) {

					int a;
					cout << "input your subchoice:"; cin >> a;
					if (a == 1) {
						cout << "input new isbn:"; cin >> b.ISBN;
					}
					if (a == 2) {
						cout << "input new bookname:"; cin >> b.Bname;
					}
					if (a == 3) {
						cout << "input new author name:"; cin >> b.Aname;
					}
					if (a == 4) {
						cout << "input new author surname:"; cin >> b.Asurname;
					}
					if (a == 5) {
						cout << "input new  topic:"; cin >> b.Topic;
					}
					if (a == 6) {
						cout << "input new type:"; cin >> b.Type;
					}
					if (a == 7) {
						cout << "input new page count:"; cin >> b.PageCount;
					}
					if (a == 8) {
						if (FileBook.eof()) break;
						FileTemp << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
						goto exit;
					}

				}
				if (FileBook.eof()) break;
				FileTemp << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";

			}
			else {
				if (FileBook.eof()) break;
				FileTemp << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";

			}

		}
	exit:
		FileBook.close();
		FileTemp.close();
		if (c == 1) {
			remove("books.txt");
			rename("Btemp.txt", "books.txt");
		}
		else {
			remove("Btemp.txt");
		}

	}

}

//KÝTAP ÖDÜNÇ ALMA
void BorrowBook(string tc) {

	time_t timer;
	time(&timer);
	

	if (ReaderControl(tc) == 0) {
		cout << "There is no reader with this Tc no!!!" << endl;
	}
	else {
		cout << "**Books**" << endl;
		ifstream ShowBooks("books.txt", ios::in);
		while (true) {
			ShowBooks >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
			if (ShowBooks.eof()) break;
			b.showBooks();
		}
		ShowBooks.close();
		string isbn;
		cout << "input isbn to borrow book:"; cin >> isbn;
		if (BookControl(isbn) == 0) {
			cout << "There is no book with this Isbn!!" << endl;
		}
		else {
			ifstream BookFile;
			BookFile.open("books.txt");
			ifstream Bookfile1("books.txt", ios::in);
			ofstream BorrowedFile;
			BorrowedFile.open("borrowed.txt", ios::app);
			ofstream TempBook;
			TempBook.open("tempB.txt", ios::app);
			ofstream ReturnBook;
			ReturnBook.open("tempBooks.txt", ios::app);
			bo.BorrowDate = ctime(&timer);
			bo.BorrowDate.erase(bo.BorrowDate.end() - 1);
			while (true) {
				BookFile >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
				if (BookFile.eof()) break;
				if (b.ISBN == isbn) {
					BorrowedFile << tc << "\t" << b.ISBN << "\t" << b.Bname << "\t" << bo.BorrowDate << "\t";
					ReturnBook << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
				}

				while (true) {

					Bookfile1 >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
					if (Bookfile1.eof()) break;
					if (b.ISBN != isbn) {
						TempBook << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
					}

				}

			}
			Bookfile1.close();
			TempBook.close();
			BookFile.close();
			BorrowedFile.close();
			ReturnBook.close();
			remove("books.txt");
			rename("tempB.txt", "books.txt");
		}
	}


}

//KÝTAP SÝLME
void deleteBook(string isbn) {

	
	if (BookControl(isbn) == 0) {
		cout << "There is no book with this ISBN" << endl;
	}
	else {
		
		ifstream bookDel("books.txt", ios::in);
		ofstream newBooks;
		newBooks.open("booktemp.txt", ios::app);



		while (true) {
			bookDel >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
			if (bookDel.eof()) break;
			if (b.ISBN != isbn) {
				newBooks << b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
			}

		}
		bookDel.close();
		newBooks.close();
		remove("books.txt");
		rename("booktemp.txt", "books.txt");

	}
}

//KÝTAP ÝADE
void ReturnBook(string tc) {
	time_t timer;
	time(&timer);


	if (ReaderControl(tc) == 0) {
		cout << "There is no reader with this Tc no!!!" << endl;
	}
	else {
		
		cout << "**Borroweds**" << endl;
		ifstream ShowBorroweds("borrowed.txt", ios::in);
		string line;
		while (getline(ShowBorroweds,line)) {
			cout << line << endl;
			if (ShowBorroweds.eof()) break;
			
		}
		ShowBorroweds.close();
		cout << endl;
		string isbn;
		cout << "enter ISBN to return the book:"; cin >> isbn;
		bo.ReturnDate = ctime(&timer);
		bo.ReturnDate.erase(bo.ReturnDate.end() - 1);
		ofstream BorrowFile("borrowedReturn.txt", ios::app);
		ifstream BorrofileRead("borrowed.txt", ios::in);
		while (true) {
			if (BorrofileRead.eof()) break;
			BorrofileRead >> r.TcNo >> b.ISBN >> b.Bname  >>bo.BorrowDate;
			if (b.ISBN == isbn) {
				BorrowFile << r.TcNo << "\t" << b.ISBN << "\t" << b.Bname << "\t" << bo.ReturnDate << "\n";
			}
		}
		cin.ignore();
		BorrowFile.close();
		

		
		ofstream newBooks;
		newBooks.open("booktemp.txt", ios::app);
		ofstream WriteBooks("books.txt", ios::app);
		ifstream TowriteBooks("tempbooks.txt", ios::in);
		while (true) {
			TowriteBooks>> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
			if (TowriteBooks.eof()) break;
			if (b.ISBN == isbn) {
				WriteBooks<< b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
			}

			if (b.ISBN !=isbn ) {
				newBooks<< b.ISBN << "\t" << b.Bname << "\t" << b.Aname << "\t" << b.Asurname << "\t" << b.Topic << "\t" << b.Type << "\t" << b.PageCount << "\n";
			}
		}
		newBooks.close();
		WriteBooks.close();
		TowriteBooks.close();
		remove("tempbooks.txt");
		rename("booktemp.txt", "tempbooks.txt");
	}
}

//OKUYUCU SÝLME
void deleteReader(string tc) {
	bool ctrl = 0;
	if (ReaderControl(tc) == 0) {
		cout << "There is no reader with this TCno!" << endl;
	}
	else {
		ifstream delReader("readers.txt", ios::in);
		ofstream Tempreader("rtemp.txt", ios::app);

		while (true) {
			if (delReader.eof()) break;
			delReader>> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
			if (r.TcNo != tc) {
				Tempreader<< r.TcNo << "\t" << r.Rname << "\t" << r.Rsurname << "\t " << r.RmemNo << "\t" << r.Phone << "\t " << r.Bdate << "\t" << r.Job << "\t" << r.Capacity << endl;
			}
		}

		delReader.close();
		Tempreader.close();
		remove("readers.txt");
		rename("rtemp.txt","readers.txt");

		
	}
}




int main()
{
	cout << "**********Library System***********" << "\n\n\n";

	Books b;
	Readers r;
	Borrow bo;
	User u;
	time_t timer;
	time(&timer);

y:
	ifstream Users("users.txt", ios::in);

	while (true) {
		string p, n;
		cout << "enter your username:"; cin >> n;
		cout << "enter your password:"; cin >> p;

		while (true) {
			if (Users.eof()) break;
			Users >> u.UserName >> u.Password;
			if (u.UserName == n && u.Password == p) {
				Sleep(500);
				goto x;
			}
			else {
				char ans;
				cout << "Press 'y' to try again or Press 'no' to exit:"; cin >> ans;
				if (ans == 'y') {
					goto y;
				}
				else if (ans == 'n') {
					Sleep(500);
					return 0;
				}
				else {
					cout << "undefined character!" << endl;
					Sleep(500);
					return 0;
				}
			}
		}

	}
x:
	Users.close();

	while (true) {
		cout << "**********Options************" << endl;
		cout << "press 1 to sign up reader" << endl;
		cout << "press 2 to update reader" << endl;
		cout << "press 3 to delete reader" << endl;
		cout << "press 4 to see reader's book list" << endl;
		cout << "press 5 to borrow book" << endl;
		cout << "press 6 to return book" << endl;
		cout << "press 7 to add book" << endl;
		cout << "press 8 to delete book" << endl;
		cout << "press 9 to edit book" << endl;
		cout << "press 'e' to  exit" << endl << endl << endl;
		char option;
		cout << "select an option:"; cin >> option;

		if (option == '1') {
			AddReader();
		}

		if (option == '2') {
			ifstream FileRead("readers.txt");
			cout << "**readers**" << endl;
			while (true) {
				FileRead >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
				if (FileRead.eof()) break;
				r.ShowReaders();
			}
			FileRead.close();
			string tc;
			cout << "enter TCno to update reader:"; cin >> tc;
			UpdateReader(tc);

		}
		if (option == '3') {
			ifstream FileRead("readers.txt");
			cout << "**readers**" << endl;
			while (true) {
				FileRead >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
				if (FileRead.eof()) break;
				r.ShowReaders();
			}
			FileRead.close();
			string tc;
			cout << "enter Tcno to delete reader:"; cin >> tc;
		}
		if (option == '4') {

		}
		if (option == '5') {
			ifstream FileRead("readers.txt", ios::in);
			cout << "**readers**" << endl;
			while (true) {
				FileRead >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
				if (FileRead.eof()) break;
				r.ShowReaders();
			}
			FileRead.close();
			string tc;
			cout << "enter TCno to borrow book:"; cin >> tc;
			BorrowBook(tc);
		}
		if (option == '6') {
			ifstream FileRead("readers.txt", ios::in);
			cout << "**readers**" << endl;
			while (true) {
				FileRead >> r.TcNo >> r.Rname >> r.Rsurname >> r.RmemNo >> r.Phone >> r.Bdate >> r.Job >> r.Capacity;
				if (FileRead.eof()) break;
				r.ShowReaders();
			}
			FileRead.close();
			string tc;
			cout << "enter TCno to return book:"; cin >> tc;
			ReturnBook(tc);
		}
		if (option == '7') {
			AddBook();
		}
		if (option == '8') {
			ifstream FileBook("books.txt");
			cout << "**Books**" << endl;
			while (true) {
				FileBook >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
				if (FileBook.eof()) break;
				b.showBooks();
			}
			FileBook.close();
			string a;
			cout << "enter ISBN to delete book:"; cin >> a;
			deleteBook(a);
		}
		if (option == '9') {
			ifstream FileBook("books.txt");
			cout << "**Books**" << endl;
			while (true) {
				FileBook >> b.ISBN >> b.Bname >> b.Aname >> b.Asurname >> b.Topic >> b.Type >> b.PageCount;
				if (FileBook.eof()) break;
				b.showBooks();
			}
			FileBook.close();
			string isb;
			cout << "enter Isbn to update book:"; cin >> isb;
			UpdateBook(isb);
		}
		if (option == 'e') {
			break;
		}


	}

	return 0;

}
