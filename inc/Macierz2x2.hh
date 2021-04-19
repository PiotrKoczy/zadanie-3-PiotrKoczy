#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2
{

  Wektor2D Tab[2];
  double kat;
  int ilosc;

public:
  int getIlosc();
  void InicjalizujMacierz();
  void KatObrotu();
  Wektor2D operator[](int idx) const;
  Wektor2D &operator[](int idx);
  Wektor2D operator*(Wektor2D wktrprim);
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */

std::ostream &operator<<(std::ostream &Strm, const Macierz2x2 &Mac);

#endif
