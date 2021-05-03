#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


/*
*
* Plik zawiera definicję klasy Wektor modelującej pojęcie wektora
*
*
* Klasa Wektor modeluje pojęcie wektora jako tablicę Rozmiar_WEKTORA-elementową.
* Zawiera zapowiedzi metod operujących na nim oraz przeciążeń operatorów [], +, -
*
*/
template<int Rozmiar>
class Wektor
{

  double Wsp[Rozmiar];

public:
Wektor();
  double operator[](int index) const;
  double &operator[](int index);
  void setWektor();

  Wektor<Rozmiar> operator+(Wektor<Rozmiar>);
  Wektor<Rozmiar> operator-(Wektor<Rozmiar>);
};

template<int Rozmiar>
Wektor<Rozmiar>::Wektor(){
  for (int index = 0; index < Rozmiar; ++index)
  Wsp[index] = 0;
}

/*Przeciazenie operatora >> pozwala wczytać wektor ze strumienia wejściowego*/
template<int Rozmiar>
std::istream &operator>>(std::istream &sin, Wektor<Rozmiar> &Wektor);

/*Przeciazenie operatora >> pozwala wyświetlić wektor przez strumień wyjściowy*/
template<int Rozmiar>
std::ostream &operator<<(std::ostream &sout, const Wektor<Rozmiar> &Wektor);

/*Operator przeciążenia wpisuje wartości ze strumienia wejściowego do tablicy wektor*/
template<int Rozmiar>
std::istream &operator>>(std::istream &sin, Wektor<Rozmiar> &Wektor)
{
    for (int index = 0; index < Rozmiar; index++)
    {
        sin >> Wektor[index];
        if (sin.fail())
        {
            return sin;
        }
        return sin;
    }
    return sin;
}

/*funkcja zapisu wektora*/
template<int Rozmiar>
void Wektor<Rozmiar>::setWektor()
{
    cout << "Podaj wektor przesuniecia: " << endl;
    for (int index = 0; index < Rozmiar; index++)
        cin >> Wsp[index];
}

/*indeksowanie stałego wektora*/
template<int Rozmiar>
double Wektor<Rozmiar>::operator[](int index) const
{
    return Wsp[index];
}

/*indeksowanie referencji do wektora*/
template<int Rozmiar>
double &Wektor<Rozmiar>::operator[](int index)
{
    // index=100;
    // assert((std::is_same<int, std::int64_t>::value));
    // assert((index < RozmiarWekt, "indeks wektora poza zakresem"));
    if (index >= 0 && index < Rozmiar)
        return Wsp[index];
    else
    {
        cout << "Wektor poza zakresem\n";
        return Wsp[0];
    }
}

/*Operator przeciążenia wypisuje wartości tablicy wektor na strumień wyjściowy*/
template<int Rozmiar>
std::ostream &operator<<(std::ostream &Strm, const Wektor<Rozmiar> Wektor)
{
    for (int index = 0; index < Rozmiar; index++)
    {
        Strm << Wektor[index] << "  ";
        if (index == Rozmiar)
        {
            Strm << Wektor[index] << endl;
            return Strm;
        }
    }
    return Strm;
}

/*operator przeciążenia + (dodawanie wektorów)*/
template<int Rozmiar>
Wektor<Rozmiar> Wektor<Rozmiar>::operator+(const Wektor<Rozmiar> arg2)
{
    Wektor wynik;
    for (int index = 0; index < Rozmiar; index++)
        wynik[index] = Wsp[index] + arg2[index];
    return wynik;
}

/*operator przeciążenia - (odejmowanie wektorów)*/
template<int Rozmiar>
Wektor<Rozmiar> Wektor<Rozmiar>::operator-(const Wektor<Rozmiar> arg2)
{
    Wektor wynik;
    for (int index = 0; index < Rozmiar; index++)
        wynik[index] = Wsp[index] - arg2[index];
    return wynik;
}


#endif
