#ifndef BEVITELI_HPP_INCLUDED
#define BEVITELI_HPP_INCLUDED
#include "graphics.hpp"
#include "kivalaszto.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
using namespace genv;


class beviteli: public szin
{
protected:
    int X0, Y0, height, width;
    string Text;
    bool focused;
public:
   beviteli(int x, int y);
   void Settext(string t);
   string Gettext();
   bool Focused();
   void SetWidth(int w);
   void SetHeight(int h);
   void rajzol();
   void torol();
   bool rajtavan(int ex, int ey);
   void TextKiir();
   void TextTorol();
   void handle(genv::event ev);
};

#endif // BEVITELI_HPP_INCLUDED
