#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Macierz.hh"
#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#define WYMIAR_PROSTOKATA = 4
#define ROZMIAR_WEKTORA = 2
const int wymiarProst WYMIAR_PROSTOKATA;
const unsigned int ROZMIAR ROZMIAR_WEKTORA;
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
  Wektor<ROZMIAR> Prostokat[wymiarProst];

public:
  void WczytajProstokat(string &);
  void Przesuniecie(Wektor<ROZMIAR>);
  void ObrocProstokat(Macierz<ROZMIAR>);
  void ObliczDlugosc();
  void WspolrzedneDoStrumienia(std::ostream &, double);
  bool ZapiszPlik(string, double);
  Wektor<ROZMIAR> &operator[](int idx);
  Wektor<ROZMIAR> operator[](int idx) const;
};

/*Przeciazenie operatora << pozwala wyświetlić współrzędne wierzchołków prostokąta*/
std::ostream &operator<<(std::ostream &sout, const Prostokat &Prostokat);

#endif
