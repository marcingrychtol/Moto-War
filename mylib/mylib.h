#ifndef mylib_h
#define mylib_h
#include <string>

using namespace std;

class Karta;
class Gracz;
class Krupier;

class Karta
{
	public:

         AnsiString getPath(); //pobiera sciezke do mmediow
         AnsiString getAudio(); //pobiera sciezke do dŸwiêku
         AnsiString getName(); //pobiera nazwe auta
         AnsiString getValStr(int i) const; // pobiera dane do przycisków

         float getVal(int i); // pobiera przekonwertowane dane do porównania
         
         void autoWybor (int diff, bool pending); // dokonuje wyboru karty przez komputer
	 void setNr(int nr); //do ustawiania numeru karty
	 void setVal(int indeks, AnsiString parametr); //do ustawiania parametrów podczas czytania z pliku

	private:

         AnsiString bufor;
         AnsiString val[8]; //przechowuje parametry string do przycisków
         AnsiString name; //nazwa pojazdu
         AnsiString mmedia; //multimedia, nazwa pliku z foto i glosem, taka sama

         int ranking[8][2]; // tablica rankingów
         int rankBufor;  //bufor do sortowania
         int rankLicznik[3]; //przecowuje liczbe parametrow w danym progu rankingu (poziomie trudnosci)

         bool rankSortFlag; //zabezp. przed ponownym sortowaniem
};

class Gracz
{
	public:

         void plusNrRozdania(int ileKartG1, int ileKartG2);
         void resetNrRozdania();
	 void setTalia (int a[]);
         void setIleKart (int a);
         void push (int karty[], int ile); //dopisuje karty do talii wygranego

         int getValue() const;
         int getCard(); //zwraca numer pierwszej karty
         int getCard(int i);
         int getIleKart() const;
         int pop ();//przesuwa taliê i zwraca talia[0]
         int getNrRozdania() const;

	private:

         static int nr_rozdania;

         int buforG;
	 int ile_kartG;
         int taliaG[16]; //tablica zawieraj¹ca numery posiadanych kart
         int typgry[3]; //tryb, przeciwnik i poziom trudnosci
};

class Krupier
{
        public:

         void tasujRozdaj(Gracz &g1, Gracz &g2); //tasuje karty, rozdaje talia1 i talia2, czysci talia0
         void clearTK();
         void nowa_karta(bool turaNowaKarta, Karta k[], Gracz &g1, Gracz &g2); //wysy³amy czyja tura i wyswietlamy karte
         void pushTK (int karta); //dodaje karty na stol, do talii0
         void porownanie(int value, Karta k[], Gracz &g1, Gracz &g2, bool &turaPorownanie); //value to parametr do porownania
         void clearScreen();
         void start(); //ustawia wartosc gra_rozpoczeta (flaga)
         void stop();

         bool pending(); //zwraca wartosc gra_rozpoczeta (flaga)

        private:

         int taliaK[16]; //talia g³ówna przed tasowaniem, talia trzymajaca karty w grze
         int taliaKG1[16]; //talia gracza 1
         int taliaKG2[16]; //talia gracza 2
         int ile_kartK; //ile kart jest w talia0
         int buforK;    //bufor dyzurny, trzeba czyscic po wykonaniu dzialan
         int los1, los2;

         bool gra_rozpoczeta;
};




#endif