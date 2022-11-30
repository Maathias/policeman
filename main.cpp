#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Zdarzenie.h"

using namespace std;

vector<Zdarzenie> zdarzenia;

int _czy_istnieje(string id) {
  for (int i = 0; i < zdarzenia.size(); i++) {
    if (zdarzenia[i].id == id) {
      return i;
    }
  }

  return -1;
}

Zdarzenie _wprowadz() {
  Zdarzenie nowe;

  bool ok = true;

  do {

    if (!ok) {
      cout << "Wprowadzono niepoprawne dane\n ";
    }

    ok = false;

    cin.ignore(10, '\n');

    cout << "id: ";
    getline(cin, nowe.id);
    if (nowe.id.length() > 50)
      continue;

    cout << "oficer: ";
    getline(cin, nowe.oficer);
    if (nowe.oficer.length() > 256)
      continue;

    cout << "typ [s/z/k]: ";
    string typ;
    getline(cin, typ);
    nowe.typ = typ[0];
    if (nowe.typ != 's' && nowe.typ != 'z' && nowe.typ != 'k' &&
        nowe.typ != '-')
      continue;

    cout << "data: ";
    getline(cin, nowe.data);

    cout << "oskarzony: ";
    getline(cin, nowe.oskarzony);

    cout << "poszkodowany: ";
    getline(cin, nowe.poszkodowany);

    cout << "swiadek: ";
    getline(cin, nowe.swiadek);

    cout << "miejsce: ";
    getline(cin, nowe.miejsce);
    if (nowe.oficer.length() > 50)
      continue;

    cout << "pojazdy: ";
    getline(cin, nowe.pojazdy);
    if (nowe.oficer.length() > 1000)
      continue;

    ok = true;

  } while (!ok);

  return nowe;
}

void dodaj_zdarzenie() {
  cout << "Wprowadź dane nowego incydentu \n";

  Zdarzenie nowe = _wprowadz();

  if (_czy_istnieje(nowe.id) == -1) {
    zdarzenia.push_back(nowe);
    cout << "Dodano zdarzenie \n";
  } else {
    cout << "Zdarzenie o takim id już istnieje \n";
  }
}

void usun_zdarzenie() {
  string id;

  cout << "Podaj incydentu do usunięcia: ";

  cin >> id;

  cout << "Usuwanie \"" << id << "\"\n";

  int cel = _czy_istnieje(id);

  if (cel >= 0) {
    zdarzenia.erase(zdarzenia.begin() + cel);
    cout << "Usunięto incydent \n";
  } else {
    cout << "Nie znaleziono incydentu o id \"" << id << "\"\n";
  }
}

void _wyswietl(Zdarzenie target) {
  cout << "id: " << target.id << "\n";

  cout << "oficer: " << target.oficer << "\n";

  cout << "typ: " << target.typ << "\n";

  cout << "data: " << target.data << "\n";

  cout << "oskarzony: " << target.oskarzony << "\n";

  cout << "poszkodowany: " << target.poszkodowany << "\n";

  cout << "swiadek: " << target.swiadek << "\n";

  cout << "miejsce: " << target.miejsce << "\n";

  cout << "pojazdy: " << target.pojazdy << "\n";
}

void zmien_zdarzenie() {
  string id;

  cout << "Podaj id incydentu do edycji: ";

  cin >> id;

  int cel = _czy_istnieje(id);

  if (cel >= 0) {
    Zdarzenie stare = zdarzenia[cel], nowe, wynik;

    cout << "Aktualne dane zdarzenia: \n";

    _wyswietl(stare);

    cout << "Wprowadź nowe dane (\"-\" omija właściwość): \n";

    nowe = _wprowadz();

    wynik.id = (nowe.id != "-") ? nowe.id : stare.id;
    wynik.oficer = (nowe.oficer != "-") ? nowe.oficer : stare.oficer;
    wynik.typ = (nowe.typ != '-') ? nowe.typ : stare.typ;
    wynik.data = (nowe.data != "-") ? nowe.data : stare.data;
    wynik.oskarzony =
        (nowe.oskarzony != "-") ? nowe.oskarzony : stare.oskarzony;
    wynik.poszkodowany =
        (nowe.poszkodowany != "-") ? nowe.poszkodowany : stare.poszkodowany;
    wynik.swiadek = (nowe.swiadek != "-") ? nowe.swiadek : stare.swiadek;
    wynik.miejsce = (nowe.miejsce != "-") ? nowe.miejsce : stare.miejsce;
    wynik.pojazdy = (nowe.pojazdy != "-") ? nowe.pojazdy : stare.pojazdy;

    cout << "Uaktualnione zdarzenie: \n";

    _wyswietl(wynik);

    if (_czy_istnieje(wynik.id) != -1) {
      cout << "Zdarzenie o takim id już istnieje \n";
      return;
    }

    char ok;

    cout << "Czy nowe zdarzenie jest poprawne? [T/n]: ";
    cin >> ok;

    if ((char)tolower(ok) == 't') {
      zdarzenia[cel] = wynik;
      cout << "Zmieniono zdarzenie \n";
    } else {
      cout << "Anulowano zmiany \n";
    }

  } else {
    cout << "Dany incydent nie istnieje \n";
  }
}

vector<int> _filtruj(char typ) {

  vector<int> pasujace;

  for (int i = 0; i < zdarzenia.size(); i++) {
    if (zdarzenia[i].typ == typ) {
      pasujace.push_back(i);
    }
  }

  return pasujace;
}

vector<int> _wyszukaj(string id) {

  vector<int> pasujace;

  for (int i = 0; i < zdarzenia.size(); i++) {
    if ((zdarzenia[i].id.find(id) != string::npos) || id == "*") {
      pasujace.push_back(i);
    }
  }

  return pasujace;
}

void wyszukaj_zdarzenie() {
  char wybor;

  cout << "Wyszukiwanie(id)/Filtrowanie(typ) ? [w/f]: ";
  cin >> wybor;

  wybor = (char)tolower(wybor);

  vector<int> wyniki;

  if (wybor == 'w') {
    string id;
    cout << "id: ";
    cin >> id;
    wyniki = _wyszukaj(id);
  } else if (wybor == 'f') {
    char typ;
    cout << "typ: ";
    cin >> typ;
    wyniki = _filtruj(typ);
  } else {
    cout << "Anulowano \n";
    return;
  }

  cout << "Znalezione zdarzenia: \n";

  for (int i = 0; i < wyniki.size(); i++) {
    cout << " > " << zdarzenia.at(wyniki[i]).id << "\n";
  }
}

void _zapis() {
  ofstream Baza("baza.csv", ofstream::out | ofstream::trunc);

  for (int i = 0; i < zdarzenia.size(); i++) {
    Baza << zdarzenia[i].id << "," << zdarzenia[i].oficer << ","
         << zdarzenia[i].typ << "," << zdarzenia[i].data << ","
         << zdarzenia[i].oskarzony << "," << zdarzenia[i].poszkodowany << ","
         << zdarzenia[i].swiadek << "," << zdarzenia[i].miejsce << ","
         << zdarzenia[i].pojazdy << "\n";
  }

  Baza.close();
}

void wczytaj_baza() {

  cout << "Wczytywanie bazy \n";

  string linia;
  ifstream Baza("baza.csv");

  while (getline(Baza, linia)) {
    stringstream ss(linia);
    vector<string> kolumny;

    while (ss.good()) {
      string kolumna;
      getline(ss, kolumna, ',');
      kolumny.push_back(kolumna);
    }

    Zdarzenie nowe;

    nowe.id = kolumny[0];
    nowe.oficer = kolumny[1];
    nowe.typ = kolumny[2][0];
    nowe.data = kolumny[3];
    nowe.oskarzony = kolumny[4];
    nowe.poszkodowany = kolumny[5];
    nowe.swiadek = kolumny[6];
    nowe.miejsce = kolumny[7];
    nowe.pojazdy = kolumny[8];

    zdarzenia.push_back(nowe);
  }

  cout << "Baza wczytana \n";
}

void zapisz_baza() {
  cout << "Zapisywanie bazy \n";
  _zapis();
  cout << "Zapisano \n";
}

void _clear() {
#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif
}

void pokaz() {
  cout << "Podaj id incydentu: ";

  string id;

  cin >> id;

  int cel = _czy_istnieje(id);
  if (cel != -1) {
    _wyswietl(zdarzenia[cel]);
  } else {
    cout << "Podany incydent nie istnieje \n";
  }
}

void menu() {
  cout << "\n===================================================== \n";
  cout << "\t\t MENU \t \n";
  cout << "===================================================== \n";
  cout << " 1.Dodaj zdarzenie \n";
  cout << " 2.Usun zdarzenie \n";
  cout << " 3.Zmien dane zdarzenia \n";
  cout << " 4.Wyszukaj/filtruj produkt po id/typie \n";
  cout << " 5.Wczytaj baze z pliku \n";
  cout << " 6.Zapisz baze do pliku \n";
  cout << " 7.Wyswietl incydent \n";
  cout << "\n";
  cout << " 0.Wyjscie \n";
}

int main() {
  int wybor;

  do {

    menu();

    cout << "Prosze wskazac czynnosc (1-6): ";
    cin >> wybor;

    _clear();

    switch (wybor) {
    case 1:
      dodaj_zdarzenie();
      break;
    case 2:
      usun_zdarzenie();
      break;
    case 3:
      zmien_zdarzenie();
      break;
    case 4:
      wyszukaj_zdarzenie();
      break;
    case 5:
      wczytaj_baza();
      break;
    case 6:
      zapisz_baza();
      break;
    case 7:
      pokaz();
      break;
    case 0:
      break;

    default:
      cout << "ERROR! Prosze wybrac jeszcze raz! \n";
      break;
    }

  } while (wybor != 0);

  return 0;
}