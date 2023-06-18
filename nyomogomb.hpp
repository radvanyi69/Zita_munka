#ifndef NYOMOGOMB_HPP_INCLUDED
#define NYOMOGOMB_HPP_INCLUDED

using namespace std;

struct Nyomogomb
{
    protected: int x,y,sx,sy;
    string felirat;
    bool fokusz;
    public:
        Nyomogomb(int x0, int y0, int sx0, int sy0);
        bool rajtavane(int ex, int ey);
        void handle(genv::event ev);
        void rajzol();
        void Setfelirat(string f);
        bool focused();

};

#endif // NYOMOGOMB_HPP_INCLUDED
