#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include <cmath>
#include <cassert>
#include "Wektor.hh"


/*
Klasa Macierz2x2 modeluje pojęcie macierzy jako dwuelementową tablicę wektorów (dwuwymiarowych).
Zawiera zapowiedzi metod operujących na niej oraz przeciążenia operatorów [], *
 */
class Macierz2x2
{

  Wektor Tab[2];
  double kat;
  int ilosc;

public:
  int getIlosc();
  void InicjalizujMacierz();
  void KatObrotu();
  Wektor operator[](int idx) const;
  Wektor &operator[](int idx);
  Wektor operator*(Wektor WektorPRIM);
};

/*Przeciazenie pozwala wyświetlić macierz*/
std::ostream &operator<<(std::ostream &sout, const Macierz2x2 &Macierz);

#endif
