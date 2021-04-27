#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <fstream>
#include <cassert>
#define WYMIAR_WEKTORA = 2
const int wymiarWekt WYMIAR_WEKTORA;
using namespace std;


/*
*
* Plik zawiera definicję klasy Wektor modelującej pojęcie wektora
*
*
* Klasa Wektor modeluje pojęcie wektora jako tablicę WYMIAR_WEKTORA-elementową.
* Zawiera zapowiedzi metod operujących na nim oraz przeciążeń operatorów [], +, -
*
*/
class Wektor
{

  double wektor[wymiarWekt];

public:
  double operator[](int index) const;
  double &operator[](int index);
  void setWektor();

  Wektor operator+(Wektor);
  Wektor operator-(Wektor);
};

/*Przeciazenie operatora >> pozwala wczytać wektor ze strumienia wejściowego*/
std::istream &operator>>(std::istream &sin, Wektor &Wektor);

/*Przeciazenie operatora >> pozwala wyświetlić wektor przez strumień wyjściowy*/
std::ostream &operator<<(std::ostream &sout, const Wektor &Wektor);

#endif
