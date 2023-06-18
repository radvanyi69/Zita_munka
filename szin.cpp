#include <szin.h>

struct szin
{
protected:
    int r, g, b;
public:
    szin(int red, int green, int blue)
    {
        if (red>=0 && red <=255 && green>=0 && green <=255 && blue>=0 && blue <=255)
        {
            r = red;
            g = green;
            b = blue;
        }
        else
        {
            r = 200;
            g = 200;
            b = 200;
        }
    }
    int Get_Red()
    {
        return r;
    }

    void Set_Red(int red)
    {
        r = red;
    }
    int Get_Green()
    {
        return g;
    }

    void Set_Green(int green)
    {
        g = green;
    }
    int Get_Blue()
    {
        return b;
    }

    void Set_Blue(int blue)
    {
        b = blue;
    }
};
