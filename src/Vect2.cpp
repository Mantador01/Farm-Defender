#include "Vect2.h"

#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

Vect2::Vect2()
{
    x = 0;
    y = 0;
}

Vect2::~Vect2()
{
}


Vect2::Vect2(float a, float b)
{ 	x=a;
	y=b;
}


Vect2 Vect2::operator+(Vect2 a)
{
    return make_Vect2(a.x+x , a.y+y);
}

Vect2 Vect2::operator-(Vect2 a)
{
    return make_Vect2(a.x-x , a.y-y);
}

Vect2 Vect2::operator*(float a)
{
    return make_Vect2(a*x , a*y);
}

Vect2 Vect2::make_Vect2(float x, float y)
{
    Vect2 a;
    a.x=x;
    a.y=y;
    return a;
}

float Vect2::distance(Vect2 a, Vect2 b)
{
    float d;
    int dx, dy;
    dx = a.x-b.x;
    dy = a.y-b.y;
    d = sqrt(dx*dx + dy*dy);
    return d;
}
