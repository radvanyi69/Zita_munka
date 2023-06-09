#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED
#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
using namespace genv;

struct szin
{
protected:
    int r, g, b;
public:

    int Get_Red();

    void Set_Red(int red);
    int Get_Green();

    void Set_Green(int green);
    int Get_Blue();
    void Set_Blue(int blue);
};

class _lista:public szin, public widget
{
protected:
    int lX, lY;
    int height, width;
    bool focus;
    int topitemindex;
    int maxitem;
    int fontmeret;
    string font;
    bool _lenyitva;
    vector<string> items;
    int sormagassag;
    bool gorgetes;
    void Remove(int index);
    void Update(int index, string ujelem);
public:
    int itemindex;
     _lista(vector<string> elemek);
     int Get_lX();
     void Set_lX(int x);
     int Get_lY();
     void Set_lY(int y);
     int Get_height();
     void Set_height(int Height);
     int Get_width();
     void Set_width(int Width);
     void Set_Items(vector<string> elemek);
     void Set_maxitem(int Maxitem);
     int Get_maxitem();
     bool Get_lenyitva();
     void Rajzol();
     void intoItems();
     void Add_item_to_items(string s);
     void Reset();

};

class beviteliEX: public _lista
{
private:

    int posX, posY;
    int bevheight, bevwidth;
    string Text;
    int fontmeret;
    string font;
    int tok;
    bool bevitelifocus;
protected:

public:
    static beviteliEX& instance();
    beviteliEX(int x, int y, vector<string> elemek);
    bool Focused();
    bool Get_nyitva();
    void Set_list_items(vector<string> items);
    void rajzol();
    void listaRajzol();
    void Set_bevwidth(int w);
    void Set_bevheigth(int h);
    void TextKiir();
    string Get_Text();
    void TextTorol();
    bool rajtavan_bevitelin(int ex, int ey);
    int rajtavan_listaelemen(int ex, int ey);
    bool rajtavan_lenyiton(int ex, int ey);
    bool rajtavanlistan(int ex,int ey);
    void handle(genv::event e);
    bool rajtavan(int box1x, int box1y,int box2x, int box2y, int ex, int ey);
    void lista_elem_Remove(int index);
    void lista_elem_Update(int index, string ujelem);
    void lista_Reset();
    void Cserel(string kulcs, string ertek);
};



#endif // KIVALASZTO_HPP_INCLUDED
