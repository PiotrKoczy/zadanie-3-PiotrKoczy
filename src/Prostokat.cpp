#include "Prostokat.hh"

using namespace std;

/*
Pobiera nazwę pliku od użytkownika oraz współrzedne prostokąta, które zapisuje w tablicy.
*/
void Prostokat::WczytajProstokat(string &sNazwaPliku)
{
  double x_coord, y_coord;

  cout << "Podaj nazwę pliku do zapisywania współrzędnych: ";
  cin >> sNazwaPliku;
  cout << endl;

  for (int index = 0; index < 4; index++)
  {
    cout << "Podaj współrzędne ";
    if (index == 0)
      cout << "lewego dolnego wierzchołka" << endl;
    else if (index == 1)
      cout << "prawego dolnego wierzchołka" << endl;
    else if (index == 2)
      cout << "prawego górnego wierzchołka" << endl;
    else if (index == 3)
      cout << "lewego górnego wierzchołka" << endl;
    else if (index == 4)
      cout << "piątego wierzchołka" << endl;

    cin >> x_coord;
    cin >> y_coord;

    Prostokat[index][0] = x_coord;
    Prostokat[index][1] = y_coord;
  }
  ZapiszPlik(sNazwaPliku, 0);
}

/*Funkcja zapisuje współrzędne prostokąta do pliku*/
bool Prostokat::ZapiszPlik(string sNazwaPliku, double Przesuniecie)
{

  ofstream zapisz;
  zapisz.open(sNazwaPliku);

  if (!zapisz.is_open())
  {
    cerr << ":'( Operacja otwarcia do zapisu pliku \"" << sNazwaPliku << "\"" << endl;
    cerr << "    nie powiodla sie." << endl;
    return false;
  }
  WspolrzedneDoStrumienia(zapisz, Przesuniecie);

  zapisz.close();
  return !zapisz.fail();
}

/*Funkcja obraca prostokąt podaną ilość razy */
void Prostokat::ObrocProstokat(Macierz<ROZMIAR> Macierz)
{
  for (int index = 0; index < Macierz.getIlosc(); index++)
  {
    for (int index = 0; index < wymiarProst; index++)
      Prostokat[index] = Macierz * Prostokat[index];
  }
}

/*Przesuniecie prostokata o podany wektor */
void Prostokat::Przesuniecie(Wektor<ROZMIAR> Wektor)
{
  for (int index = 0; index < wymiarProst; index++)
    Prostokat[index] = Prostokat[index] + Wektor;
}

/*Funkcja oblicza długości boków i sprawdza czy długość naprzeciwległych jest identyczna*/
void Prostokat::ObliczDlugosc()
{
  double a, b, c, d;
  double epsilon = 0.00001;

  a = sqrt(pow((Prostokat[0][0] - Prostokat[1][0]), 2) + pow((Prostokat[0][1] - Prostokat[1][1]), 2));
  b = sqrt(pow((Prostokat[1][0] - Prostokat[2][0]), 2) + pow((Prostokat[1][1] - Prostokat[2][1]), 2));
  c = sqrt(pow((Prostokat[2][0] - Prostokat[3][0]), 2) + pow((Prostokat[2][1] - Prostokat[3][1]), 2));
  d = sqrt(pow((Prostokat[3][0] - Prostokat[0][0]), 2) + pow((Prostokat[3][1] - Prostokat[0][1]), 2));

  cout << endl;
  cout << "Dlugosci bokow to: ";
  cout << endl;
  cout << "a = " << fixed << setprecision(10) << a << endl;
  cout << "b = " << fixed << setprecision(10) << b << endl;
  cout << "c = " << fixed << setprecision(10) << c << endl;
  cout << "d = " << fixed << setprecision(10) << d << endl;
  if (fabs((a - c)) < epsilon && fabs((b - d)) < epsilon)
  {
    cout << "Długości przeciwleglych boków są równe.";
    cout << endl;
  }
  else
  {
    cout << "Uwaga: Długości przeciwległych boków różnią się.";
    cout << endl;
  }
}

void Prostokat::WspolrzedneDoStrumienia(ostream &StrmWy, double Przesuniecie)
{
  int rozmiar = ROZMIAR;
  for (int i = 0; i < wymiarProst; i++)
  {
    for (int j = 0; j < rozmiar; j++)
    {
      StrmWy << setw(16) << fixed << setprecision(10) << Prostokat[i][j] + Przesuniecie;
    }
    StrmWy << endl;
  }
}

/*indeksowanie stałego prostokata*/
Wektor<ROZMIAR> Prostokat::operator[](int index) const
{
  return Prostokat[index];
}

/*indeksowanie referencji do prostokata*/
Wektor<ROZMIAR> &Prostokat::operator[](int index)
{
  return Prostokat[index];
}

/*Przeciazenie pozwala wyświetlić współrzędne prostokąta*/
std::ostream &operator<<(std::ostream &StrmWy, const Prostokat &Prostokat)
{
  StrmWy << endl;
  for (int i = 0; i < wymiarProst; i++)
  {
    StrmWy << "Współrzędne wierzchołka " << i+1 << " = " << fixed << setprecision(10) << Prostokat[i][0] << "  " << fixed << setprecision(10) << Prostokat[i][1] << endl;
  }
  return StrmWy;
}