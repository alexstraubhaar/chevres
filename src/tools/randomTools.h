#ifndef randomTools_h
#define randomTools_h
#pragma once

#include <random>

class RandomGenerator{

public :
    RandomGenerator(int minimum = 0, int maximum = 1);

    void setMin(int minimum);
    void setMax(int minimum);
    void setBornes(int minimum, int maximum);


    int rnd();
    int rnd(int minimum, int maximum);

private :

    int min,max;
    int delta;

    std::mt19937 gen = std::mt19937((std::random_device())());
    std::uniform_int_distribution<> dis;

};

class RandomGenerator_float{

public :
    RandomGenerator_float(float minimum = 0.f, float maximum = 1.f);

    void setMin(float minimum);
    void setMax(float maximum);
    void setBornes(float minimum, float maximum);

    float rnd();
    float rnd(float minimum, float maximum);

private :

    float min, max;
    float delta;

    std::mt19937 gen = std::mt19937((std::random_device())());
    std::uniform_real_distribution<> dis;

};

#endif /* randomTools_h */
