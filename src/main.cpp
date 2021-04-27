#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Wektor.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

int main()
{
   Prostokat Prostokat;        // To tylko przykladowe definicje zmiennej
   PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                               // rysunku prostokata
   string sNazwaPliku;
   Macierz2x2 Macierz;
   Wektor wktr;
   char wybor = '0';

   Prostokat.WczytajProstokat(sNazwaPliku);
   const char *constNazwaPliku = sNazwaPliku.c_str();

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
   Lacze.DodajNazwePliku(constNazwaPliku, PzG::RR_Ciagly, 2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
   Lacze.DodajNazwePliku(constNazwaPliku, PzG::RR_Punktowy, 2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
   Lacze.ZmienTrybRys(PzG::TR_2D);

   while (wybor != 'k')
   {
      cout << "Podaj opcję (h- home) > ";
      cout << endl;
      cin >> wybor;

      switch (wybor)
      {
      case 'h':
         cout << endl;
         cout << "  Co dla Ciebie zrobić?" << endl;
         cout << "p - przesunięcie prostokąta o podany wektor" << endl;
         cout << "o - obró† prostokąta o podany kąt" << endl;
         cout << "w - wyswietlenie współrzędnych wierzchołków" << endl;
         cout << "m - wyswietlenie macierzy obrotu" << endl;
         cout << "s - wyswietlenie prostokątu" << endl;
         cout << "k - zakończenie działania programu" << endl
              << endl;
         break;
      case 'o':
      //assert(("There are five lights", 2 + 2 == 5));
         Macierz.KatObrotu();
         Macierz.InicjalizujMacierz();
         Prostokat.ObrocProstokat(Macierz);
         if (!Prostokat.ZapiszPlik(constNazwaPliku, 0))
            return 1;
         Prostokat.ObliczDlugosc();
         Lacze.Rysuj();
         cin.ignore(numeric_limits<int>::max(), '\n');
         break;
      case 'w':
         cout << Prostokat;
         if (!Prostokat.ZapiszPlik(constNazwaPliku, 0))
            return 1;
         break;
      case 'm':
         cout << "Macierz 2x2:";
         cout << endl;
         cout << Macierz;
         break;

      case 'p':
         wktr.setWektor();
         Prostokat.Przesuniecie(wktr);
         if (!Prostokat.ZapiszPlik(constNazwaPliku, 0))
            return 1;
         Lacze.Rysuj();
         cin.ignore(numeric_limits<int>::max(), '\n');
         break;
      case 's':
         Lacze.Rysuj();
         cin.ignore(numeric_limits<int>::max(), '\n');
         break;
      case 'k':
         break;
      default:
         cout << "Podano błędną opcję!";
         cout << endl;
         break;
      }
   }
   return 0;
}
