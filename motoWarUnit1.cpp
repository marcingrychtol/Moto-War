//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include <string>
#include <iostream>

#include "motoWarUnit1.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "mylib.h"

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Karta karta[16];//bazowa tablica kart do wczytywania
Krupier krupier;
Gracz gracz[2];

bool tura; //0 dla gracz1, 1 dla gracz2

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GameEnd1Click(TObject *Sender)
{
        if (krupier.pending())
        {
             krupier.stop();
             gracz[0].resetNrRozdania();

             Form1->CounterMain1->Caption = gracz[0].getNrRozdania();

             Form1->ModeBox1->Enabled=true;
             Form1->OppBox1->Enabled=true;
             Form1->DiffBox1->Enabled=(!Form1->OppBox1->ItemIndex);

             krupier.clearScreen();

             Form1->GameEnd1->Enabled = false;
             Form1->GameNew1->Enabled = true;

             Informer1->Caption="PodpowiedŸ: wybierz typ gry, przeciwnika i kliknij: Nowa gra.";

             ShowMessage("Zakoñczono grê");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GameNew1Click(TObject *Sender)
{
    if (!krupier.pending())
    {
        Form1->ModeBox1->Enabled=false;
        Form1->OppBox1->Enabled=false;
        Form1->DiffBox1->Enabled=false;

        ShowMessage("Rozpoczêto now¹ grê");

        krupier.start();
        gracz[0].plusNrRozdania(gracz[0].getIleKart(), gracz[1].getIleKart());
        krupier.tasujRozdaj(gracz[0], gracz[1]);
        tura = rand()%2;

        if (tura ==0)
        {
                ShowMessage("Zaczyna Gracz 1");
                Form1->Tura1->Caption= ("Gracz 1");

        }
        if (tura ==1)
        {
                ShowMessage("Zaczyna Gracz 2");
                Form1->Tura1->Caption= ("Gracz 2");
        }

        Form1->CardTacho1->Caption=( IntToStr( gracz[tura].getIleKart() ) + " /16" );
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        Informer1->Caption="PodpowiedŸ: wybierz teraz parametr, którym zagrasz. Klikniêcie w przycisk parametru zatwierdza wybór.";

        Form1->GameEnd1->Enabled = true;
        Form1->GameNew1->Enabled = false;
    }

    if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
    karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
       srand(time(NULL));

       fstream in_karty("MW_karty.txt");
       int nrlinii_plik = 1;
       int nrlinii_karta = 1;
       AnsiString liniaA;
       string liniaS;

       while(getline(in_karty,liniaS))
       {
                liniaA = liniaS.c_str();
                karta[ (nrlinii_plik - 1) /18 ].setVal(nrlinii_karta,liniaA);
                if(nrlinii_karta==18) nrlinii_karta=0;
                nrlinii_karta++;
                nrlinii_plik++;
       }

       in_karty.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Volume1Click(TObject *Sender)
{
        krupier.porownanie(0, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Volume2Click(TObject *Sender)
{
        krupier.porownanie(0, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Power1Click(TObject *Sender)
{
        krupier.porownanie(1, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Power2Click(TObject *Sender)
{
        krupier.porownanie(1, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Torque1Click(TObject *Sender)
{
        krupier.porownanie(2, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Torque2Click(TObject *Sender)
{
        krupier.porownanie(2, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Speed1Click(TObject *Sender)
{
        krupier.porownanie(3, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Speed2Click(TObject *Sender)
{
        krupier.porownanie(3, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Weight1Click(TObject *Sender)
{
        krupier.porownanie(4, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Weight2Click(TObject *Sender)
{
        krupier.porownanie(4, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Acc1Click(TObject *Sender)
{
        krupier.porownanie(5, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Acc2Click(TObject *Sender)
{
        krupier.porownanie(5, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Eco1Click(TObject *Sender)
{
        krupier.porownanie(6, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Eco2Click(TObject *Sender)
{
        krupier.porownanie(6, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Price1Click(TObject *Sender)
{
        krupier.porownanie(7, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Price2Click(TObject *Sender)
{
        krupier.porownanie(7, karta, gracz[0], gracz[1], tura);
        krupier.nowa_karta(tura, karta, gracz[0], gracz[1]);

        if (tura == 1 && Form1->OppBox1->ItemIndex == 0)
        karta[gracz[1].getCard()].autoWybor(Form1->DiffBox1->ItemIndex, krupier.pending());
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TestSound1Click(TObject *Sender)
{
        sndPlaySound( karta[ gracz[tura].getCard() ].getAudio().c_str() ,SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TestSound2Click(TObject *Sender)
{
        sndPlaySound( karta[ gracz[tura].getCard() ].getAudio().c_str() ,SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OppBox1Click(TObject *Sender)
{
        if (Form1->OppBox1->ItemIndex == 0)
        Form1->DiffBox1->Enabled = true;

        if (Form1->OppBox1->ItemIndex == 1)
        Form1->DiffBox1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Author1Click(TObject *Sender)
{
        Form2->ShowModal();
}
//---------------------------------------------------------------------------

