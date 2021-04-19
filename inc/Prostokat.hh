#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Macierz2x2.hh"
#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat
{
  Wektor2D Prostokat[4];

public:
  void WczytajProstokat(string &);
  void Przesuniecie(Wektor2D);
  void ObrocProstokat(Macierz2x2);
  void ObliczDlugosc();
  void WspolrzedneDoStrumienia(std::ostream &, double);
  bool ZapiszPlik(string, double);
  Wektor2D &operator[](int idx);
  Wektor2D operator[](int idx) const;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &StrmWy, const Prostokat &Prostokat);

#endif
