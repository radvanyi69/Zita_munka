#include "graphics.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "kivalaszto.hpp"
#include "beviteli.hpp"


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

    gout << refresh;
    event ev;
    string egy = "";
    while(gin >> ev && ev.keycode!=key_escape)
    {
        beex1.handle(ev);
        beex2.handle(ev);
        edit.handle(ev);

        if (ev.button == btn_left)
        {
            if (beex1.Focused())
            {
                egy = beex1.Get_Text();
            }

            if (beex2.Focused())
            {
                egy = beex2.Get_Text();
            }
            if (edit.Focused()) egy = edit.Gettext();
        }

        gout << refresh;
    }
    return 0;
}
