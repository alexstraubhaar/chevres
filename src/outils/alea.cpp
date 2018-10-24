#include "alea.h"

// pour les int

generateurAlea::generateurAlea(int minimum, int maximum) /*: std::mt19937((std::random_device())())*/
{
    min = minimum;
    max = maximum;
    champsReel = maximum - minimum;

    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
}

void generateurAlea::setMin(int minimum)
{
    min = minimum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    champsReel = max - min;
}

void generateurAlea::setMax(int maximum)
{
    max = maximum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    champsReel = max - min;
}

void generateurAlea::setBornes(int minimum, int maximum){
    min = minimum;
    max = maximum;
    dis.param(std::uniform_int_distribution<>::param_type(min ,max));
    champsReel = max - min;
}

int generateurAlea::alea()
{
    return dis(gen);
}

int generateurAlea::alea(int minimum,int maximum)
{
    int champsVoulu = maximum - minimum;
    int ratio = champsVoulu / champsReel;
    return int(dis(gen)*ratio);
}

generateurAleaF::generateurAleaF(float minimum, float maximum) //
{
    min = minimum;
    max = maximum;
    champsReel = maximum - minimum;

    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
}

// pour les float

void generateurAleaF::setMin(float minimum)
{
    min = minimum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    champsReel = max - min;


}
void generateurAleaF::setMax(float maximum)
{
    max = maximum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    champsReel = max - min;

}

void generateurAleaF::setBornes(float minimum, float maximum)
{
    min = minimum;
    max = maximum;
    dis.param(std::uniform_real_distribution<>::param_type(min ,max));
    champsReel = max - min;
}

float generateurAleaF::alea()
{
    return (dis(gen));
}

float generateurAleaF::alea(float minimum,float maximum)
{
    float champsVoulu = minimum - maximum;
    float ratio = champsVoulu / champsReel;
    return float(dis(gen)*ratio);
}
