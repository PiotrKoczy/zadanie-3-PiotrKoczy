#include "Wektor2D.hh"

using namespace std;

/*Operator przeciążenia wpisuje wartości ze strumienia wejściowego do tablicy wektor*/
std::istream &operator>>(std::istream &sin, Wektor2D &Wektor)
{

    sin >> Wektor[0];
    if (sin.fail())
    {
        return sin;
    }
    sin >> Wektor[1];
    if (sin.fail())
    {
        return sin;
    }
    return sin;
}

/*funkcja zapisu wektora*/
void Wektor2D::setWektor()
{
    cout << "Podaj wektor przesuniecia: " << endl;
    cin >> wektor[0];
    cin >> wektor[1];
}

/*indeksowanie stałego wektora*/
double Wektor2D::operator[](int index) const
{
    return wektor[index];
}

/*indeksowanie referencji do wektora*/
double &Wektor2D::operator[](int index)
{
    return wektor[index];
}

/*Operator przeciążenia wypisuje wartości tablicy wektor na strumień wyjściowy*/
std::ostream &operator<<(std::ostream &Strm, const Wektor2D Wektor)
{
    Strm << Wektor[0] << "  ";
    Strm << Wektor[1] << endl;
    return Strm;
}
/*operator przeciążenia + (dodawanie wektorów)*/
Wektor2D Wektor2D::operator+(const Wektor2D arg2)
{
    Wektor2D wynik;
    wynik[0] = wektor[0] + arg2[0];
    wynik[1] = wektor[1] + arg2[1];
    return wynik;
}
/*operator przeciążenia - (odejmowanie wektorów)*/
Wektor2D Wektor2D::operator-(const Wektor2D arg2)
{
    Wektor2D wynik;
    wynik[0] = wektor[0] - arg2[0];
    wynik[1] = wektor[1] - arg2[1];
    return wynik;
}

