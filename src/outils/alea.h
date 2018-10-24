#ifndef alea_h
#define alea_h
#pragma once

#include <random>

class generateurAlea
{

public :
    generateurAlea(int minimum = 0, int maximum = 1);

    void setMin(int minimum);
    void setMax(int minimum);
    void setBornes(int minimum, int maximum);


    int alea();
    int alea(int minimum, int maximum);

private :

    int min,max;
    int champsReel;

    std::mt19937 gen = std::mt19937((std::random_device())());
    std::uniform_int_distribution<> dis;

};

class generateurAleaF{

public :
    generateurAleaF(float minimum = 0.f, float maximum = 1.f);

    void setMin(float minimum);
    void setMax(float maximum);
    void setBornes(float minimum, float maximum);

    float alea();
    float alea(float minimum, float maximum);

private :

    float min, max;
    float champsReel;

    std::mt19937 gen = std::mt19937((std::random_device())());
    std::uniform_real_distribution<> dis;

};

#endif /* alea_h */
