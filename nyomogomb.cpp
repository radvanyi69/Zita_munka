#include "szamlalo.hpp"
#include "graphics.hpp"
#include "nyomogomb.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

Nyomogomb :: Nyomogomb(int x0, int y0,int sx0,int sy0)
{
    x=x0;
    y=y0;
    sx=sx0;
    sy=sy0;
}
void Nyomogomb::Setfelirat(string f)
{
    felirat=f;
    rajzol();
}

void Nyomogomb::rajzol()
{
    int szeles = gout.twidth(felirat);
    gout << color(100, 100, 100) << move_to(x, y)
             << box(sx, sy)<<color(255,255,255)<< move_to(x+(sx-szeles)/2,y+8)<< text(felirat);
}

bool Nyomogomb:: rajtavane(int ex, int ey)
{
    bool rajta=false;
        if(x<=ex && x+sx>=ex && y <=ey&& y+sy >=ey)
        {
            rajta=true;
        }
        return rajta;
}

void Nyomogomb::handle(genv::event ev)
{

    if(ev.button==btn_left)
    {
        fokusz=rajtavane(ev.pos_x,ev.pos_y);

    }
}

bool Nyomogomb::focused()
{
    return fokusz;
}

