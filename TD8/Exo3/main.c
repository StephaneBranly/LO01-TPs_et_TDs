#include <stdio.h>


void cartesienEnPolaire(float x, float y, float *r, float *theta)
{

}

void polaireEnCartesien(float r, float theta, float *x, float *y)
{

}


void deplace(float *x, float *y, float r)
{
    float theta_p,r_p;

    cartesienEnPolaire(*x,*y,&theta_p,&r_p);

    r_p -= r;

    polaireEnCartesien(r_p,theta_p,x,y);
}
