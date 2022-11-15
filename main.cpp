#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "Zdarzenie.h"

using namespace std;

vector<Zdarzenie> zdarzenia;

void dodaj_zdarzenie()
{
	cout << "dodaj_zdarzenie\n";

	Zdarzenie nowe;

	cout << "id: ";
  cin >> nowe.id;
	
  // cout << "oficer: ";
  // cin >> nowe.oficer;

  // cout << "typ: ";
  // cin >> nowe.typ;

  // cout << "data: ";
  // cin >> nowe.data;

  // cout << "oskarzony: ";
  // cin >> nowe.oskarzony;

  // cout << "poszkodowany: ";
  // cin >> nowe.poszkodowany;

  // cout << "swiadek: ";
  // cin >> nowe.swiadek;

  // cout << "miejsce: ";
  // cin >> nowe.miejsce;

  // cout << "pojazdy: ";
  // cin >> nowe.pojazdy;

	zdarzenia.push_back(nowe);
}

void usun_zdarzenie()
{
	cout << "usun_zdarzenie\n";
}

void zmien_zdarzenie()
{
	cout << "zmien_zdarzenie\n";
}

void wyszukaj_zdarzenie()
{
	int targetIndex = 0;

	cout << "wyszukaj_zdarzenie\n";
	cout << "nr zdarzenia: ";
	cin >> targetIndex;

	Zdarzenie target = zdarzenia.at(targetIndex);

	cout << target.id << endl;
}

void wyszukaj_baza()
{
	cout << "wyszukaj_baza\n";
}

void wczytaj_baza()
{
	cout << "wczytaj_baza\n";
}

void menu()
{
	cout << "===================================================== \n";
	cout << " \t\tMENU \t \n ";
	cout << "===================================================== \n";
	cout << " 1.Dodaj zdarzenie\n";
	cout << " 2.Usun zdarzenie\n";
	cout << " 3.Zmien dane zdarzenia \n";
	cout << " 4.Wyszukaj/filtruj produkt po id/typie \n";
	cout << " 5.Wyszukaj przy uzyciu bazy danych \n";
	cout << " 6.Wczytaj za pomoca bazy danych \n";
	cout << " 7.Wyjscie \n";
}

int main()
{
	string st[20];
	int itemcount = 0;

	menu();

	int wybor;
	string potwierdz;
	do
	{
		cout << "Prosze wskazac czynnosc (1-6): ";
		cin >> wybor;
		switch (wybor)
		{
		case 1: dodaj_zdarzenie(); break;
		case 2: usun_zdarzenie(); break;
		case 3: zmien_zdarzenie(); break;
		case 4: wyszukaj_zdarzenie(); break;
		case 5: wyszukaj_baza(); break;
		case 6: wczytaj_baza(); break;
		case 7: return 0;
		default: cout << "ERROR! Prosze wybrac jeszcze raz! \n"; break;
		}
		cout << "Prosze wcisnac t/T do kontynuacji: ";
		cin >> potwierdz;
	} while (potwierdz == "t" || potwierdz == "T");
	return 0;
}