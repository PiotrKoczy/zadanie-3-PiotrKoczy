#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Macierz2x2.hh"
#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#define WYMIAR_PROSTOKATA = 4
const int wymiarProst WYMIAR_PROSTOKATA;
using namespace std;

/*
*
* Plik zawiera definicję klasy opisującej prostokąt oraz zestaw narzędzi do operacji na nim.
*
*
* Klasa Prostokat modeluje pojęcie prostokąta jako WYMIAR_PROSTOKATA wektorów. 
* Zawiera zapowiedzi metod operujących na nim, metody obsługi strumienia, 
* zapisu oraz przeciążenia operatora []
*
*/

class Prostokat
{
  Wektor Prostokat[wymiarProst];

public:
  void WczytajProstokat(string &);
  void Przesuniecie(Wektor);
  void ObrocProstokat(Macierz2x2);
  void ObliczDlugosc();
  void WspolrzedneDoStrumienia(std::ostream &, double);
  bool ZapiszPlik(string, double);
  Wektor &operator[](int idx);
  Wektor operator[](int idx) const;
};

/*Przeciazenie operatora << pozwala wyświetlić współrzędne wierzchołków prostokąta*/
std::ostream &operator<<(std::ostream &sout, const Prostokat &Prostokat);

#endif
