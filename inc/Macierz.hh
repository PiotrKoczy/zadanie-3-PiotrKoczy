#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#define PI 3.14

#include <iostream>
#include <cmath>
#include <cassert>
#include "Wektor.hh"

/*
*
* Plik zawiera definicję klasy opisującej macierz 2x2 oraz zestaw narzędzi do jej obsługi.
*
*
* Klasa Macierz<Rozmiar> modeluje pojęcie macierzy jako dwuelementową tablicę wektorów (dwuwymiarowych).
* Zawiera zapowiedzi metod operujących na niej oraz przeciążenia operatorów [], *
*
*/
template<int Rozmiar>
class Macierz
{

  Wektor<Rozmiar> Tab[Rozmiar];
  double kat;
  int ilosc;

public:
  int getIlosc();
  void InicjalizujMacierz();
  void KatObrotu();
  Wektor<Rozmiar> operator[](int idx) const;
  Wektor<Rozmiar> &operator[](int idx);
  Wektor<Rozmiar> operator*(Wektor<Rozmiar> Wektor) const;
};

/*Przeciazenie pozwala wyświetlić macierz*/
template<int Rozmiar>
std::ostream &operator<<(std::ostream &sout, const Macierz<Rozmiar> &Macierz);

/*
 Inicjalizacja macierzy w układzie współrzędnych
*/
template<int Rozmiar>
void Macierz<Rozmiar>::InicjalizujMacierz()
{
  Tab[0][0] = cos(kat * PI / 180.0);
  Tab[0][1] = -sin(kat * PI / 180.0);
  Tab[1][0] = sin(kat * PI / 180.0);
  Tab[1][1] = cos(kat * PI / 180.0);
}

/*Podanie wartości kąta oraz liczby obrotów*/
template<int Rozmiar>
void Macierz<Rozmiar>::KatObrotu()
{
  cout << "Podaj kąt, o który chcesz obrócić prostokąt: ";
  cin >> kat;
  cout << endl;
  cout << "Podaj ilość obrotów: ";
  cout << endl;
  cin >> ilosc;
}

template<int Rozmiar>
int Macierz<Rozmiar>::getIlosc()
{
  return ilosc;
}

template<int Rozmiar>
Wektor<Rozmiar> Macierz<Rozmiar>::operator*(Wektor<Rozmiar> WektorPRIM) const //Usunąłem WektorTMP, sprawdzić czy działa
{
  Wektor<Rozmiar> Wektor;
  for (int i = 0; i < Rozmiar; ++i)
  {
    Wektor[i] = 0;
    for (int j = 0; j < Rozmiar; ++j)
    {
      Wektor[i] += Tab[i][j] * WektorPRIM[j];
    }
  }
  return Wektor;
}

template<int Rozmiar>
Wektor<Rozmiar> Macierz<Rozmiar>::operator[](int index) const
{
  return Tab[index];
}

template<int Rozmiar>
Wektor<Rozmiar> &Macierz<Rozmiar>::operator[](int index)
{
  return Tab[index];
}

template<int Rozmiar>
std::ostream &operator<<(std::ostream &StrmWy, const Macierz<Rozmiar> &Macierz)
{
  StrmWy << "| " << Macierz[0][0] << " " << Macierz[0][1] << " |";
  StrmWy << endl;
  StrmWy << "| " << Macierz[1][0] << " " << Macierz[1][1] << " |";
  StrmWy << endl;
  return StrmWy;
}


#endif
