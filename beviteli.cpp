#include "beviteli.hpp"
#include "graphics.hpp"
#include "kivalaszto.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

beviteli::beviteli(int x, int y):szin()
{
    X0 = x;
    Y0 = y;
    width = 150;
    height = 20;
    focused = false;
}

bool beviteli::Focused()
{
    return focused;
}

string beviteli::Gettext()
{
    return Text;
}

void beviteli::Settext(string t)
{
    Text = t;
}

void beviteli::beviteli::SetWidth(int w)
{
    width = w;
    rajzol();
}

void beviteli::beviteli::SetHeight(int h)
{
    height = h;
    rajzol();
}

void beviteli::beviteli::torol()
{
    gout << move_to(X0+2, Y0+2) << color(0,0,0) << box(width, height);
    gout << refresh;
}

void beviteli::beviteli::rajzol()
{
    if (focused)
    {
        r = 255;
        g = 200;
        b = 0;
    }
    else
    {
        r = 220;
        g = 220;
        b = 220;
    }


    gout << move_to(0,0) << color(r, g, b) << move_to(X0, Y0)
         << box_to(X0+width, Y0+height) ;
}

bool beviteli::rajtavan(int ex, int ey)
{
    int box1x = X0;
    int box1y = Y0;
    int box2x = X0+width;
    int box2y = Y0+height;
    bool rajta=false;
    if(ex<=box2x && ex>=box1x && ey<=box2y && ey>=box1y)
    {
        rajta=true;
    }
    return rajta;
}

void beviteli::TextKiir()
{
    TextTorol();
    gout << move_to(0,0) << color(0, 0, 0) << move_to(X0, Y0)
         << text(Text) ;
}

void beviteli::TextTorol()
{
    rajzol();
}

void beviteli::handle(genv::event ev)
{
    if (ev.button == btn_left)
    {
        focused = rajtavan(ev.pos_x, ev.pos_y);
        torol();
        rajzol();
    }
    if (ev.keycode > 0 && focused)
    {
        Text = Text + ev.keyutf8;
        TextKiir();
    }
    if ((ev.keycode == key_backspace) && focused)
    {
        string s = "";
        for (int i = 0; i < Text.length()-1; i++)
        {
            s = s + Text[i];
        }
        Text = s;
        TextTorol();
        TextKiir();
    }
    if (ev.keycode == key_delete && focused)
    {
        Text = "";
        TextTorol();
    }
}
