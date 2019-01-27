#include "randomTools.h"

// pour les int
RandomGenerator::RandomGenerator(int minimum, int maximum) /*: std::mt19937((std::random_device())())*/
{
    min = minimum;
    max = maximum;
    delta = maximum - minimum;

    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
}

void RandomGenerator::setMin(int minimum)
{
    min = minimum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    delta = max - min;
}

void RandomGenerator::setMax(int maximum)
{
    max = maximum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    delta = max - min;
}

void RandomGenerator::setBornes(int minimum, int maximum){
    min = minimum;
    max = maximum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    delta = max - min;
}

int RandomGenerator::rnd()
{
    return dis(gen);
}

int RandomGenerator::rnd(int minimum,int maximum)
{
    int champsVoulu = maximum - minimum;
    int ratio = champsVoulu / delta;
    return int(dis(gen)*ratio);
}

// pour les float
RandomGenerator_float::RandomGenerator_float(float minimum, float maximum) //
{
    min = minimum;
    max = maximum;
    delta = maximum - minimum;

    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
}

void RandomGenerator_float::setMin(float minimum)
{
    min = minimum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    delta = max - min;


}
void RandomGenerator_float::setMax(float maximum)
{
    max = maximum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    delta = max - min;

}

void RandomGenerator_float::setBornes(float minimum, float maximum)
{
    min = minimum;
    max = maximum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    delta = max - min;
}

float RandomGenerator_float::rnd()
{
    return (dis(gen));
}

float RandomGenerator_float::rnd(float minimum,float maximum)
{
    float champsVoulu = minimum - maximum;
    float ratio = champsVoulu / delta;
    return float(dis(gen)*ratio);
}
