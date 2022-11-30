https://www.javatpoint.com/cpp-vector-at-function

#### Rejestr wypadków

Zadanie polega na zaprojektowaniu oraz implementacji oprogramowania do zarządzania rejestrem wypadków drogowych policji. Każde akta sprawy charakteryzowane są następującym rekordem danych:

- **id incydentu** – tablica znaków o maksymalnej długości 50 znaków
- **oficer prowadzący** – tablica znaków o maksymalnej długości 256 znaków
- **typ** – jeden z typów: stłuczka, zderzenie, katastrofa lądowa itp.
- **data zdarzenia** – data w przyjętym formacie
- **oskarżony** – imię i nazwisko oskarżonego, puste jeżeli nie dotyczy
- **poszkodowany** – imię i nazwisko poszkodowanego, puste jeżeli nie dotyczy
- **świadek** – imię i nazwisko świadka
- **miejsce(droga,ulica)** – tablica znaków o maksymalnej długości 50 znaków
- **dane pojazdów biorących udział w zdarzeniu** – tablica znaków o maksymalnej długości 1000 znaków

Program powinien umożliwiać wykonywanie następujących czynności:

- ~~dodanie zdarzenia~~
- ~~usunięcie zdarzenia~~
- ~~zmianę danych zdarzenia~~
- ~~wyszukanie/filtrowanie produktu po id/typie~~
- \*wyszukiwanie przy użyciu bazy danych na dysku w postaci pliku
- wczytanie zapisanej bazy danych ze wskazanego pliku
