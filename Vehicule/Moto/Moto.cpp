#include "./Moto.hpp"
#include <iostream>
using namespace std;

Moto::Moto()
{
	marque = "JOG";
}
Moto::~Moto()
{
}
void Moto::conduire() const
{
	cout<<" start moto conduire"<<endl;
}
