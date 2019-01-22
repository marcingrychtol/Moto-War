#include <vcl.h>
#include "mylib.h"
#include <cstdlib>
#include <string>
#include <math.h>
#include "motoWarUnit1.h"
#include "mmsystem.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Karta::setVal (int indeks, AnsiString parametr)
{
	if (indeks==1)
        {
                mmedia=parametr;
                rankSortFlag = 0;
        }
	else if (indeks==2) name=parametr;
	else if(indeks>=3 && indeks<=18 && indeks%2==1)
	{
		val[(indeks-3)/2]=parametr;
		
	}
	else if(indeks>=3 && indeks<=18 && indeks%2==0)
	{
		ranking[(indeks-4)/2][0]=atoi(parametr.c_str());
	}

        for (int i = 0; i<8; i++)
        {
                ranking[i][1] = i;
        }
	
}
//-----------------------------------------------------------------------------

AnsiString Karta::getPath()
{
	return "img/"+mmedia+".jpg";
}
//-----------------------------------------------------------------------------

AnsiString Karta::getAudio()
{
	return "snd/"+mmedia+".wav";
}
//-----------------------------------------------------------------------------

AnsiString Karta::getName()
{
	return name;
}
//-----------------------------------------------------------------------------

float Karta::getVal(int i)
{
	return atof(val[i].c_str());
}
//-----------------------------------------------------------------------------

AnsiString Karta::getValStr (int i) const
{
	return val[i];
}
//-----------------------------------------------------------------------------

void Karta::autoWybor(int diff, bool pending)
{
        if (rankSortFlag == 0 && diff<3)
        {
                rankSortFlag = 1;

                for (int i=0; i<7; i++)
                {
                        for (int l=0; l<7-i;l++)
                        {
                                if (ranking[l][0]>ranking[l+1][0])
                                {
                                        rankBufor = ranking[l][0];
                                        ranking[l][0] = ranking[l+1][0];
                                        ranking[l+1][0] = rankBufor;

                                        rankBufor = ranking[l][1];
                                        ranking[l][1] = ranking[l+1][1];
                                        ranking[l+1][1] = rankBufor;
                                }
                        }
                }

                for (int j = 0; j<3; j++)
                {
                        rankLicznik[j] = ( (j+1)*2) -1;  //1..3..5 (z ilu losuje)

                        for (int k = rankLicznik[j]-1 ; k<7; k++)
                        {
                          if (ranking[rankLicznik[j]-1][0] == ranking[k+1][0])
                          rankLicznik[j]++;
                        }
                }
                
        }

        if (diff<3)rankBufor = ranking[ ( rand()%(rankLicznik[diff]) ) ][1];

        else rankBufor = ranking[rand()%8][1];

        Application->ProcessMessages();Sleep(700);
        if (pending)
        {
                if (rankBufor == 0) Form1->Volume2->Click();
                if (rankBufor == 1) Form1->Power2->Click();
                if (rankBufor == 2) Form1->Torque2->Click();
                if (rankBufor == 3) Form1->Speed2->Click();
                if (rankBufor == 4) Form1->Weight2->Click();
                if (rankBufor == 5) Form1->Acc2->Click();
                if (rankBufor == 6) Form1->Eco2->Click();
                if (rankBufor == 7) Form1->Price2->Click();
        }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


int Gracz::getIleKart() const
{
        return ile_kartG;
}
//-----------------------------------------------------------------------------

void Gracz::setTalia(int a[])
{
        for (int i=0; i<16; i++)
        {
                taliaG[i]=a[i];
        }
}
//-----------------------------------------------------------------------------

void Gracz::setIleKart (int a)
{
        ile_kartG=a;
}
//-----------------------------------------------------------------------------

int Gracz::pop()
{
        buforG = taliaG[0];

        if (ile_kartG > 0)
        {
                for (int i=0; i<ile_kartG; i++)
                {
                        taliaG[i]=taliaG[i+1];
                }

                ile_kartG--;
        }

        return buforG;
}
//-----------------------------------------------------------------------------

void Gracz::push (int karty[], int ile)
{
        if (ile_kartG < 16)
        {
                for (int i = 0; i<ile; i++)
                {
                        taliaG[ile_kartG] = karty[i];
                        ile_kartG++;
                }
        }
}
//-----------------------------------------------------------------------------

int Gracz::getCard()
{
        return taliaG[0];
}
//-----------------------------------------------------------------------------

int Gracz::getCard(int i)
{
        return taliaG[i];
}
//-----------------------------------------------------------------------------

int Gracz::nr_rozdania = 0;  //inicjacja statycznego obiektu
//-----------------------------------------------------------------------------

void Gracz::plusNrRozdania(int ileKartG1, int ileKartG2)
{
        nr_rozdania++;
        Form1->CounterMain1->Caption = nr_rozdania;
        if (Form1->ModeBox1->ItemIndex == 1 && nr_rozdania == 10)
        {
                ShowMessage("Ostatnie rozdanie!");
        }
        if (Form1->ModeBox1->ItemIndex == 1 && nr_rozdania > 10)
        {
                if (ileKartG1 > ileKartG2)
                {
                        ShowMessage("Grê wygra³ Gracz 1!");
                }
                else if (ileKartG1 < ileKartG2)
                {
                        ShowMessage("Grê wygra³ Gracz 2!");
                }
                else
                {
                        ShowMessage("Gra zakoñczona remisem!");
                }

                Form1->GameEnd1->Click();
        }
}
//-----------------------------------------------------------------------------

void Gracz::resetNrRozdania()
{
        nr_rozdania = 0;
}
//-----------------------------------------------------------------------------

int Gracz::getNrRozdania() const
{
        return nr_rozdania;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Krupier::start()
{
        gra_rozpoczeta = 1;
}
//-----------------------------------------------------------------------------

void Krupier::stop()
{
        gra_rozpoczeta = 0;
}
//-----------------------------------------------------------------------------

bool Krupier::pending()
{
        return gra_rozpoczeta;
}
//-----------------------------------------------------------------------------


void Krupier::tasujRozdaj(Gracz &g1, Gracz &g2)
{
        for (int i=0; i<16; i++) //tworzenie talii
        {
                taliaK[i]=i;
                taliaKG1[i]=taliaKG2[i]=-1;
        }

        for (int i = 0; i<100000; i++)
        {
                los1 = rand()%16;
                los2 = rand()%16;
                while (los1 == los2) //zapewnienie ró¿nych indeksów
                los2 = rand()%16;

                buforK = taliaK[los1];   //zamiana kart
                taliaK[los1] = taliaK[los2];
                taliaK[los2] = buforK;
                buforK=-1;
        }

        for (int i=0; i<8; i++)   //rozdzielenie potasowanej talii
        {
            taliaKG1[i]=taliaK[i];
            taliaKG2[i]=taliaK[i+8];
        }

        for (int i=0; i<16; i++)
        {
                taliaK[i]=-1; //czyszczenia talia0
        }

        ile_kartK = 0;  //ustawia ilosc kart w talii0

        g1.setTalia(taliaKG1);
        g2.setTalia(taliaKG2);
        g1.setIleKart(8);
        g2.setIleKart(8);
}
//-----------------------------------------------------------------------------

void Krupier::porownanie(int value, Karta k[],Gracz &g1, Gracz &g2, bool &turaPorownanie)
{

        pushTK(g2.pop()); //wedruje na indeks 0
        pushTK(g1.pop()); //wedruje na indeks 0, a g2 na indeks 1

        if (value < 4)
        {
                if ( k[taliaK[0]].getVal(value) > k[taliaK[1]].getVal(value) )
                {

                        if (g2.getIleKart() == 0)
                        {
                                ShowMessage("Grê wygra³ Gracz 1! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );
                                Form1->GameEnd1->Click();
                        }
                        else
                        {
                                ShowMessage("Wygra³ Gracz 1! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );

                                g1.push(taliaK, ile_kartK); //wysylamy talia0 do gracza1
                                clearTK();
                                turaPorownanie=0;

                                Form1->CardTacho1->Caption=( IntToStr( g1.getIleKart() ) + " /16" );
                                Form1->Tura1->Caption= ("Gracz 1");

                                g1.plusNrRozdania(g1.getIleKart(),g2.getIleKart());  //zmienna statyczna, niewazne ktory gracz
                        }

                }
                else if  ( k[taliaK[0]].getVal(value) < k[taliaK[1]].getVal(value) )
                {
                        if (g1.getIleKart() == 0)
                        {
                                ShowMessage("Grê wygra³ Gracz 2! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );
                                Form1->GameEnd1->Click();
                        }
                        else
                        {
                                ShowMessage("Wygra³ Gracz 2! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" -vs- "+
                                 k[taliaK[1]].getValStr(value) );

                                g2.push(taliaK, ile_kartK);  //wysylamy 1 do release czyli gracz2
                                clearTK();
                                turaPorownanie=1;

                                Form1->CardTacho1->Caption=( IntToStr( g2.getIleKart() ) + " /16" );
                                Form1->Tura1->Caption= ("Gracz 2");

                                g1.plusNrRozdania(g1.getIleKart(),g2.getIleKart());  //zmienna statyczna, niewazne ktory gracz
                        }


                }
                else if (g1.getIleKart() == 0)
                {
                        ShowMessage("Grê wygra³ Gracz 2");
                        Form1->GameEnd1->Click();
                }
                else if (g2.getIleKart() == 0)
                {
                        ShowMessage("Grê wygra³ Gracz 1");
                        Form1->GameEnd1->Click();
                }
                else
                {
                        ShowMessage("Remis, karty w grze. \nKontunuuj.");
                }
        }
        else if (value >= 4)
        {
                if ( k[taliaK[0]].getVal(value) < k[taliaK[1]].getVal(value) )
                {
                        if (g2.getIleKart() == 0)
                        {
                                ShowMessage("Grê wygra³ Gracz 1! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );
                                Form1->GameEnd1->Click();
                        }
                        else
                        {
                                ShowMessage("Wygra³ Gracz 1! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );

                                g1.push(taliaK, ile_kartK); //wysylamy 0 do release czyli gracz1
                                clearTK();
                                turaPorownanie=0;

                                Form1->CardTacho1->Caption=( IntToStr( g1.getIleKart() ) + " /16" );
                                Form1->Tura1->Caption= ("Gracz 1");

                                g1.plusNrRozdania(g1.getIleKart(),g2.getIleKart()); //zmienna statyczna, niewazne ktory gracz
                        }
                }
                else if  ( k[taliaK[0]].getVal(value) > k[taliaK[1]].getVal(value) )
                {
                        if (g1.getIleKart() == 0)
                        {
                                ShowMessage("Grê wygra³ Gracz 2! \n" +
                                 k[taliaK[0]].getName() +" --vs-- "+
                                 k[taliaK[1]].getName() +"\n"+
                                 k[taliaK[0]].getValStr(value) +" --vs-- "+
                                 k[taliaK[1]].getValStr(value) );
                                Form1->GameEnd1->Click();
                        }
                        else
                        {
                                ShowMessage("Wygra³ Gracz 2! \n" +
                                k[taliaK[0]].getName() +" --vs-- "+
                                k[taliaK[1]].getName() +"\n"+
                                k[taliaK[0]].getValStr(value) +" --vs-- "+
                                k[taliaK[1]].getValStr(value) );

                                g2.push(taliaK, ile_kartK);  //wysylamy 1 do release czyli gracz2
                                clearTK();
                                turaPorownanie=1;

                                Form1->CardTacho1->Caption=( IntToStr( g2.getIleKart() ) + " /16" );
                                Form1->Tura1->Caption= ("Gracz 2");

                                g1.plusNrRozdania(g1.getIleKart(),g2.getIleKart()); //zmienna statyczna, niewazne ktory gracz
                        }
                }
                else if (g1.getIleKart() == 0)
                {
                        ShowMessage("Grê wygra³ Gracz 2");
                        Form1->GameEnd1->Click();
                }
                else if (g2.getIleKart() == 0)
                {
                        ShowMessage("Grê wygra³ Gracz 1");
                        Form1->GameEnd1->Click();
                }
                else
                {
                        ShowMessage("Remis, karty w grze. \n Kontunuuj.");
                }
        }
}
//-----------------------------------------------------------------------------

void Krupier::pushTK (int karta)
{
        if (ile_kartK > 0)
        {
                for (int i = ile_kartK; i>0; i--)
                {
                        taliaK[i]=taliaK[i-1];
                }
        }
        
        taliaK[0]=karta;
        ile_kartK++;
}
//-----------------------------------------------------------------------------

void Krupier::clearTK()
{
        for (int i=0; i<ile_kartK; i++)
        {
                taliaK[i]=-1;
        }
        ile_kartK=0;
}
//---------------------------------------------------------------------------
void Krupier::nowa_karta (bool turaNowaKarta, Karta k[], Gracz &g1, Gracz &g2)
{
        if (turaNowaKarta == 0 && gra_rozpoczeta == 1)
        {
                Form1->CardPlayer1->Enabled = true;
                Form1->CardPlayer2->Enabled = false;

	        Form1->CarBlueprint1->Visible=true;
                Form1->TestSound1->Visible=true;
                Form1->Volume1->Visible=true;
                Form1->Power1->Visible=true;
                Form1->Torque1->Visible=true;
                Form1->Speed1->Visible=true;
                Form1->Weight1->Visible=true;
                Form1->Acc1->Visible=true;
                Form1->Eco1->Visible=true;
                Form1->Price1->Visible=true;

                Form1->VolumeLabel1->Visible=true;
                Form1->PowerLabel1->Visible=true;
                Form1->TorqueLabel1->Visible=true;
                Form1->SpeedLabel1->Visible=true;
                Form1->WeightLabel1->Visible=true;
                Form1->AccLabel1->Visible=true;
                Form1->EcoLabel1->Visible=true;
                Form1->PriceLabel1->Visible=true;

                Form1->CarTitle1->Caption = k[ g1.getCard() ].getName();
                Form1->CarBlueprint1->Transparent=false;
                Form1->CarBlueprint1->Picture->LoadFromFile( k[g1.getCard() ].getPath() );
                Form1->Volume1->Caption =   k[ g1.getCard() ].getValStr(0);
                Form1->Power1->Caption =    k[ g1.getCard() ].getValStr(1);
                Form1->Torque1->Caption =   k[ g1.getCard() ].getValStr(2);
                Form1->Speed1->Caption =    k[ g1.getCard() ].getValStr(3);
                Form1->Weight1->Caption =   k[ g1.getCard() ].getValStr(4);
                Form1->Acc1->Caption =      k[ g1.getCard() ].getValStr(5);
                Form1->Eco1->Caption =      k[ g1.getCard() ].getValStr(6);
                Form1->Price1->Caption =    k[ g1.getCard() ].getValStr(7);

                Form1->CarTitle2->Caption= "Karta Gracza 2";
                Form1->CarBlueprint2->Transparent=true;
	        Form1->CarBlueprint2->Picture->LoadFromFile("img/question.bmp");
                Form1->TestSound2->Visible=false;
                Form1->Volume2->Visible=false;
                Form1->Power2->Visible=false;
                Form1->Torque2->Visible=false;
                Form1->Speed2->Visible=false;
                Form1->Weight2->Visible=false;
                Form1->Acc2->Visible=false;
                Form1->Eco2->Visible=false;
                Form1->Price2->Visible=false;

                Form1->VolumeLabel2->Visible=false;
                Form1->PowerLabel2->Visible=false;
                Form1->TorqueLabel2->Visible=false;
                Form1->SpeedLabel2->Visible=false;
                Form1->WeightLabel2->Visible=false;
                Form1->AccLabel2->Visible=false;
                Form1->EcoLabel2->Visible=false;
                Form1->PriceLabel2->Visible=false;

                if (g1.getIleKart() >= 1) Form1->Image1->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 1) Form1->Image1->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 2) Form1->Image2->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 2) Form1->Image2->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 3) Form1->Image3->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 3) Form1->Image3->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 4) Form1->Image4->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 4) Form1->Image4->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 5) Form1->Image5->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 5) Form1->Image5->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 6) Form1->Image6->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 6) Form1->Image6->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 7) Form1->Image7->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 7) Form1->Image7->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 8) Form1->Image8->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 8) Form1->Image8->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 9) Form1->Image9->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 9) Form1->Image9->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 10) Form1->Image10->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 10) Form1->Image10->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 11) Form1->Image11->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 11) Form1->Image11->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 12) Form1->Image12->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 12) Form1->Image12->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 13) Form1->Image13->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 13) Form1->Image13->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 14) Form1->Image14->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 14) Form1->Image14->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 15) Form1->Image15->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 15) Form1->Image15->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() == 16) Form1->Image16->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 16) Form1->Image16->Picture->LoadFromFile("img/indicator/white.bmp");

        }

        else if (turaNowaKarta == 1  && gra_rozpoczeta == 1)
        {
                Form1->CardPlayer1->Enabled = false;
                Form1->CardPlayer2->Enabled = true;

	        Form1->CarBlueprint2->Visible=true;
                Form1->TestSound2->Visible=true;
                Form1->Volume2->Visible=true;
                Form1->Power2->Visible=true;
                Form1->Torque2->Visible=true;
                Form1->Speed2->Visible=true;
                Form1->Weight2->Visible=true;
                Form1->Acc2->Visible=true;
                Form1->Eco2->Visible=true;
                Form1->Price2->Visible=true;

                Form1->VolumeLabel2->Visible=true;
                Form1->PowerLabel2->Visible=true;
                Form1->TorqueLabel2->Visible=true;
                Form1->SpeedLabel2->Visible=true;
                Form1->WeightLabel2->Visible=true;
                Form1->AccLabel2->Visible=true;
                Form1->EcoLabel2->Visible=true;
                Form1->PriceLabel2->Visible=true;

                Form1->CarTitle2->Caption = k[ g2.getCard() ].getName();
                Form1->CarBlueprint1->Transparent=false;
                Form1->CarBlueprint2->Picture->LoadFromFile( k[g2.getCard() ].getPath() );
                Form1->Volume2->Caption =   k[ g2.getCard() ].getValStr(0);
                Form1->Power2->Caption =    k[ g2.getCard() ].getValStr(1);
                Form1->Torque2->Caption =   k[ g2.getCard() ].getValStr(2);
                Form1->Speed2->Caption =    k[ g2.getCard() ].getValStr(3);
                Form1->Weight2->Caption =   k[ g2.getCard() ].getValStr(4);
                Form1->Acc2->Caption =      k[ g2.getCard() ].getValStr(5);
                Form1->Eco2->Caption =      k[ g2.getCard() ].getValStr(6);
                Form1->Price2->Caption =    k[ g2.getCard() ].getValStr(7);

                if (!Form1->OppBox1->ItemIndex)
                {


                Form1->CarTitle1->Caption = k[ g1.getCard() ].getName();
                Form1->CarBlueprint1->Transparent=false;
                Form1->CarBlueprint1->Picture->LoadFromFile( k[g1.getCard() ].getPath() );
                Form1->Volume1->Caption =   k[ g1.getCard() ].getValStr(0);
                Form1->Power1->Caption =    k[ g1.getCard() ].getValStr(1);
                Form1->Torque1->Caption =   k[ g1.getCard() ].getValStr(2);
                Form1->Speed1->Caption =    k[ g1.getCard() ].getValStr(3);
                Form1->Weight1->Caption =   k[ g1.getCard() ].getValStr(4);
                Form1->Acc1->Caption =      k[ g1.getCard() ].getValStr(5);
                Form1->Eco1->Caption =      k[ g1.getCard() ].getValStr(6);
                Form1->Price1->Caption =    k[ g1.getCard() ].getValStr(7);

                if (g1.getIleKart() >= 1) Form1->Image1->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 1) Form1->Image1->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 2) Form1->Image2->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 2) Form1->Image2->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 3) Form1->Image3->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 3) Form1->Image3->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 4) Form1->Image4->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 4) Form1->Image4->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 5) Form1->Image5->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 5) Form1->Image5->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 6) Form1->Image6->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 6) Form1->Image6->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 7) Form1->Image7->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 7) Form1->Image7->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 8) Form1->Image8->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 8) Form1->Image8->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 9) Form1->Image9->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 9) Form1->Image9->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 10) Form1->Image10->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 10) Form1->Image10->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 11) Form1->Image11->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 11) Form1->Image11->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 12) Form1->Image12->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 12) Form1->Image12->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 13) Form1->Image13->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 13) Form1->Image13->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 14) Form1->Image14->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 14) Form1->Image14->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() >= 15) Form1->Image15->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 15) Form1->Image15->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g1.getIleKart() == 16) Form1->Image16->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g1.getIleKart() < 16) Form1->Image16->Picture->LoadFromFile("img/indicator/white.bmp");
                }

                if (Form1->OppBox1->ItemIndex)
                {
	        Form1->CarTitle1->Caption= "Karta Gracza 1";
                Form1->CarBlueprint1->Transparent=true;
	        Form1->CarBlueprint1->Picture->LoadFromFile("img/question.bmp");
                Form1->TestSound1->Visible=false;
                Form1->Volume1->Visible=false;
                Form1->Power1->Visible=false;
                Form1->Torque1->Visible=false;
                Form1->Speed1->Visible=false;
                Form1->Weight1->Visible=false;
                Form1->Acc1->Visible=false;
                Form1->Eco1->Visible=false;
                Form1->Price1->Visible=false;

                Form1->VolumeLabel1->Visible=false;
                Form1->PowerLabel1->Visible=false;
                Form1->TorqueLabel1->Visible=false;
                Form1->SpeedLabel1->Visible=false;
                Form1->WeightLabel1->Visible=false;
                Form1->AccLabel1->Visible=false;
                Form1->EcoLabel1->Visible=false;
                Form1->PriceLabel1->Visible=false;

                if (g2.getIleKart() >= 1) Form1->Image1->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 1) Form1->Image1->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 2) Form1->Image2->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 2) Form1->Image2->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 3) Form1->Image3->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 3) Form1->Image3->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 4) Form1->Image4->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 4) Form1->Image4->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 5) Form1->Image5->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 5) Form1->Image5->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 6) Form1->Image6->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 6) Form1->Image6->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 7) Form1->Image7->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 7) Form1->Image7->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 8) Form1->Image8->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 8) Form1->Image8->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 9) Form1->Image9->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 9) Form1->Image9->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 10) Form1->Image10->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 10) Form1->Image10->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 11) Form1->Image11->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 11) Form1->Image11->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 12) Form1->Image12->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 12) Form1->Image12->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 13) Form1->Image13->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 13) Form1->Image13->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 14) Form1->Image14->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 14) Form1->Image14->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() >= 15) Form1->Image15->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 15) Form1->Image15->Picture->LoadFromFile("img/indicator/white.bmp");

                if (g2.getIleKart() == 16) Form1->Image16->Picture->LoadFromFile("img/indicator/green.bmp");
                else if (g2.getIleKart() < 16) Form1->Image16->Picture->LoadFromFile("img/indicator/white.bmp");
                }
        }

        if (g1.getIleKart() == 1 || g2.getIleKart() ==1) ShowMessage("Karta meczowa!");
}
//-----------------------------------------------------------------------------

void Krupier::clearScreen()
{
                Form1->Tura1->Caption = "-";
                Form1->CardTacho1->Caption = "0 /16";

                Form1->CardPlayer1->Enabled = false;
                Form1->CardPlayer2->Enabled = false;

                Form1->CarTitle1->Caption= "Karta Gracza 1";
                Form1->CarBlueprint1->Transparent=true;
	        Form1->CarBlueprint1->Picture->LoadFromFile("img/question.bmp");
                Form1->CarBlueprint1->Visible=true;
                Form1->TestSound1->Visible=true;
                Form1->Volume1->Visible=true;
                Form1->Power1->Visible=true;
                Form1->Torque1->Visible=true;
                Form1->Speed1->Visible=true;
                Form1->Weight1->Visible=true;
                Form1->Acc1->Visible=true;
                Form1->Eco1->Visible=true;
                Form1->Price1->Visible=true;

                Form1->Volume1->Caption =   "?";
                Form1->Power1->Caption =    "?";
                Form1->Torque1->Caption =   "?";
                Form1->Speed1->Caption =    "?";
                Form1->Weight1->Caption =   "?";
                Form1->Acc1->Caption =      "?";
                Form1->Eco1->Caption =      "?";
                Form1->Price1->Caption =    "?";
                
                Form1->VolumeLabel1->Visible=true;
                Form1->PowerLabel1->Visible=true;
                Form1->TorqueLabel1->Visible=true;
                Form1->SpeedLabel1->Visible=true;
                Form1->WeightLabel1->Visible=true;
                Form1->AccLabel1->Visible=true;
                Form1->EcoLabel1->Visible=true;
                Form1->PriceLabel1->Visible=true;

                Form1->CarTitle2->Caption= "Karta Gracza 2";
                Form1->CarBlueprint2->Transparent=true;
	        Form1->CarBlueprint2->Picture->LoadFromFile("img/question.bmp");
                Form1->CarBlueprint2->Visible=true;
                Form1->TestSound2->Visible=true;
                Form1->Volume2->Visible=true;
                Form1->Power2->Visible=true;
                Form1->Torque2->Visible=true;
                Form1->Speed2->Visible=true;
                Form1->Weight2->Visible=true;
                Form1->Acc2->Visible=true;
                Form1->Eco2->Visible=true;
                Form1->Price2->Visible=true;

                Form1->VolumeLabel2->Visible=true;
                Form1->PowerLabel2->Visible=true;
                Form1->TorqueLabel2->Visible=true;
                Form1->SpeedLabel2->Visible=true;
                Form1->WeightLabel2->Visible=true;
                Form1->AccLabel2->Visible=true;
                Form1->EcoLabel2->Visible=true;
                Form1->PriceLabel2->Visible=true;

                Form1->Volume2->Caption =   "?";
                Form1->Power2->Caption =    "?";
                Form1->Torque2->Caption =   "?";
                Form1->Speed2->Caption =    "?";
                Form1->Weight2->Caption =   "?";
                Form1->Acc2->Caption =      "?";
                Form1->Eco2->Caption =      "?";
                Form1->Price2->Caption =    "?";

                Form1->Image1->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image2->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image3->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image4->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image5->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image6->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image7->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image8->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image9->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image10->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image11->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image12->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image13->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image14->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image15->Picture->LoadFromFile("img/indicator/white.bmp");
                Form1->Image16->Picture->LoadFromFile("img/indicator/white.bmp");
}
//-----------------------------------------------------------------------------

