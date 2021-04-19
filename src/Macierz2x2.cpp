#include "Macierz2x2.hh"

#define PI 3.141592
using namespace std;

/*
 Inicjalizacja macierzy w układzie współrzędnych
*/

void Macierz2x2::InicjalizujMacierz()
{

  Tab[0][0] = cos(kat * PI / 180.0);
  Tab[0][1] = -sin(kat * PI / 180.0);
  Tab[1][0] = sin(kat * PI / 180.0);
  Tab[1][1] = cos(kat * PI / 180.0);
}

/*Podanie wartości kąta oraz liczby obrotów*/
void Macierz2x2::KatObrotu()
{
  cout << "Podaj kąt, o który chcesz obrócić prostokąt: ";
  cin >> kat;
  cout << endl;
  cout << "Podaj ilość obrotów: ";
  cout << endl;
  cin >> ilosc;
}

int Macierz2x2::getIlosc()
{
  return ilosc;
}

Wektor2D Macierz2x2::operator*(Wektor2D WektorPRIM)
{
  Wektor2D tmpWektor;
  tmpWektor[0] = WektorPRIM[0] * Tab[0][0] + WektorPRIM[1] * Tab[0][1];
  tmpWektor[1] = WektorPRIM[0] * Tab[1][0] + WektorPRIM[1] * Tab[1][1];
  return tmpWektor;
}


Wektor2D Macierz2x2::operator[](int index) const
{
  return Tab[index];
}

Wektor2D &Macierz2x2::operator[](int index)
{
  return Tab[index];
}

std::ostream &operator<<(std::ostream &StrmWy, const Macierz2x2 &Macierz)
{
  StrmWy << "| " << Macierz[0][0] << " " << Macierz[0][1] << " |";
  StrmWy << endl;
  StrmWy << "| " << Macierz[1][0] << " " << Macierz[1][1] << " |";
  StrmWy << endl;
  return StrmWy;
}

