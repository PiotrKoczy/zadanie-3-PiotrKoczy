#include "Wektor.hh"
using namespace std;

/*Operator przeciążenia wpisuje wartości ze strumienia wejściowego do tablicy wektor*/
std::istream &operator>>(std::istream &sin, Wektor &Wektor)
{
    int wymiar WYMIAR_WEKTORA;
    for (int index = 0; index < wymiar; index++)
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
void Wektor::setWektor()
{
    cout << "Podaj wektor przesuniecia: " << endl;
    for (int index = 0; index < wymiarWekt; index++)
        cin >> wektor[index];
}

/*indeksowanie stałego wektora*/
double Wektor::operator[](int index) const
{
    return wektor[index];
}

/*indeksowanie referencji do wektora*/
double &Wektor::operator[](int index)
{
    // index=100;
    // assert((std::is_same<int, std::int64_t>::value));
    // assert((index < wymiarWekt, "indeks wektora poza zakresem"));
    if (index >= 0 && index < wymiarWekt)
        return wektor[index];
    else
    {
        cout << "Wektor poza zakresem\n";
        return wektor[0];
    }
}

/*Operator przeciążenia wypisuje wartości tablicy wektor na strumień wyjściowy*/
std::ostream &operator<<(std::ostream &Strm, const Wektor Wektor)
{
    for (int index = 0; index < wymiarWekt; index++)
    {
        Strm << Wektor[index] << "  ";
        if (index == wymiarWekt)
        {
            Strm << Wektor[index] << endl;
            return Strm;
        }
    }
    return Strm;
}

/*operator przeciążenia + (dodawanie wektorów)*/
Wektor Wektor::operator+(const Wektor arg2)
{
    Wektor wynik;
    for (int index = 0; index < wymiarWekt; index++)
        wynik[index] = wektor[index] + arg2[index];
    return wynik;
}

/*operator przeciążenia - (odejmowanie wektorów)*/
Wektor Wektor::operator-(const Wektor arg2)
{
    Wektor wynik;
    for (int index = 0; index < wymiarWekt; index++)
        wynik[index] = wektor[index] - arg2[index];
    return wynik;
}
