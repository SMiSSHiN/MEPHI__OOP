#include <iostream> 
#include <math.h>

#include "cissoidDiocles.h"

namespace curves{

    CissoidDiocles::CissoidDiocles(double rad) 
    {
        if(rad < 0)
            throw std::runtime_error("invalid radius");
        radius = rad;
    }

    double CissoidDiocles::distance(double fi) const{

        if(fi < -PI/2 || fi > PI/2)
            throw std::runtime_error("invalid angle");

        return (2*radius*pow(sin(fi), 3)/cos(fi));
    }

    CissoidDiocles& CissoidDiocles::setRad(double rad)
    {
        if(rad <= 0)
            throw std::runtime_error("invalid radius");
        radius = rad;

        return *this; // ???
    }

    Point CissoidDiocles::y(double x) const
    {   
        if(x < 0 || x >= 2*radius)
            throw std::runtime_error("illegal argument x");

        int y = sqrt(pow(x, 3)/(2*radius - x));

        Point res;
        res.x = y;
        res.y = (-1) * y;

        return res;
    }

    double CissoidDiocles::volume() const
    {
        return (12*pow(PI, 2)*pow(radius, 3));
    }

    double CissoidDiocles::k_parabola() const
    {
        return 8*radius;
    }

}
