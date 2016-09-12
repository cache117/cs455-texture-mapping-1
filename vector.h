//
// Created by cstaheli on 9/12/2016.
//

#ifndef TEXTURE_MAPPING_VECTOR_H
#define TEXTURE_MAPPING_VECTOR_H


class Vector
{
    Vector(double x, double y, double z, double w) : x(x), y(y), z(z), w(w)
    {

    }
    Vector(double x, double y, double z) : Vector(x, y, z, 1)
    {

    }
private:
    double x, y, z, w;
};


#endif //TEXTURE_MAPPING_VECTOR_H
