#ifndef ZDARZENIE_H
#define ZDARZENIE_H

#include <string>

using namespace std;

struct Zdarzenie
{
  string id;
  string oficer;
  char typ;
  string data;
  string oskarzony;
  string poszkodowany;
  string swiadek;
  string miejsce;
  string pojazdy;
};

#endif