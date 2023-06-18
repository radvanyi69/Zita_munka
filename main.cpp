#include "graphics.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "kivalaszto.hpp"
#include "beviteli.hpp"
#include "nyomogomb.hpp"


using namespace genv;
using namespace std;

int main()
{
    gout.open(800,600);
    gout << font("LiberationSans-Regular.ttf",16);

    vector<string> tartalom ;
    tartalom.push_back("almafa");
    tartalom.push_back("kortepalinka");
    tartalom.push_back("almafa hordo");
    tartalom.push_back("eperpuding");

    vector<string> tart2;
    tart2.push_back("matematika");
    tart2.push_back("fizika");
    tart2.push_back("angol nyelv");
    tart2.push_back("informatika");
    tart2.push_back("rajz");
    tart2.push_back("ének");
    tart2.push_back("testnevelés");
    tart2.push_back("német nyelv");
    tart2.push_back("ebédidő");
    tart2.push_back("vacsora");
    tart2.push_back("érettségi");
    tart2.push_back("dolgozat");


    beviteliEX beex1 = beviteliEX(100, 50, tartalom);
    beex1.Set_maxitem(7);
    beex1.rajzol();

    beviteliEX beex2 = beviteliEX(350, 50, tart2);
    beex2.Set_maxitem(9);
    beex2.Set_bevwidth(200);
    beex2.rajzol();

    beviteli edit = beviteli(100, 200);
    edit.rajzol();

    Nyomogomb btn = Nyomogomb(600, 50, 80, 30);
    btn.Setfelirat ("Töröl");
    btn.rajzol();

    Nyomogomb btnUpdate = Nyomogomb(600, 100, 80, 30);
    btnUpdate.Setfelirat("Módosít");
    btnUpdate.rajzol();

    Nyomogomb btnUj = Nyomogomb(600, 150, 80, 30);
    btnUj.Setfelirat("Uj");
    btnUj.rajzol();

    Nyomogomb btnReset = Nyomogomb(600, 200, 80, 30);
    btnReset.Setfelirat("Reset");
    btnReset.rajzol();

    Nyomogomb btnCsere = Nyomogomb(600, 250, 80, 30);
    btnCsere.Setfelirat("Csere");
    btnCsere.rajzol();


    gout << refresh;
    event ev;
    string egy = "";
    string sUpdate = "";
    string sUj = "";
    int itemi = 0;
//    int szam=11;
//    double szam2=(double)szam/10;

    string kulcs="";
    string ertek="";

    while(gin >> ev && ev.keycode!=key_escape)
    {
        beex1.handle(ev);
        beex2.handle(ev);
        edit.handle(ev);
        btn.handle(ev);
        btnUpdate.handle(ev);
        btnUj.handle(ev);
        btnReset.handle(ev);
        btnCsere.handle(ev);

        if (ev.button == btn_left)
        {
            if (beex1.Focused())
            {
                egy = beex1.Get_Text();
                //itemi = beex1.itemindex;
            }

            if (beex2.Focused())
            {
                egy = beex2.Get_Text();
                itemi = beex2.itemindex;
            }
            if (edit.Focused()) egy = edit.Gettext();
            if (btn.focused())
            {
                beex2.lista_elem_Remove(itemi);         //torles
                if(beex2.Get_lenyitva())
                {
                    beex2.listaRajzol();
                    beex2.listaRajzol();
                }
                else{beex2.listaRajzol();}

            }
            if (btnUpdate.focused())
            {
                sUpdate = beex2.Get_Text() + " " + beex1.Get_Text();
                beex2.lista_elem_Update(itemi, sUpdate);
            }
            if (btnUj.focused())
            {
                sUj = edit.Gettext();
                beex2.Add_item_to_items(sUj);
                if(beex2.Get_lenyitva())
                {
                    beex2.listaRajzol();
                    beex2.listaRajzol();
                }
                else{beex2.listaRajzol();}

            }

            if(btnReset.focused())
            {
                beex2.lista_Reset();
                if(beex2.Get_lenyitva())
                {
                    beex2.listaRajzol();
                    beex2.listaRajzol();
                }
                else{beex2.listaRajzol();}

            }

            if(btnCsere.focused())
            {
                kulcs=edit.Gettext();
                ertek=beex1.Get_Text();
                beex2.Cserel(kulcs, ertek);
                  if(beex2.Get_lenyitva())
                {
                    beex2.listaRajzol();
                    beex2.listaRajzol();
                }
                else{beex2.listaRajzol();}

            }


        }

        gout << refresh;
    }
    return 0;
}
