#ifndef _CISSOIDDIOCLES_H
#define _CISSOIDDIOCLES_H

#include <math.h>

#define PI 3.14159 

namespace curves{

    struct Point{
        double x, y;
        Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
    };

    class CissoidDiocles{
    private:
        double radius;
    public:
        CissoidDiocles(double rad = 1);
        CissoidDiocles& setRad(double rad); // ???
        double getRad() const{ return radius; }

        double distance(double fi) const;
        Point y(double x) const;
        double k_asymptote() const{ return 2*radius; }
        double area() const{ return 2*PI*radius*radius; }
        double volume() const;
        double k_parabola() const;
    };

}

#endif