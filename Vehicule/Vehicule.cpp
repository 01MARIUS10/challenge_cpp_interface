#include "Vehicule.hpp"
#include <iostream>

Vehicule::Vehicule()
{
    marque = "undefined";
}
void Vehicule::display()
{
    std::cout<<"marque :"<<marque<< std::endl;
}