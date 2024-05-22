#include "./Auto.hpp"


#include <iostream>
using namespace std;

Auto::Auto()
{
    marque = "RENAUD";
}

Auto::~Auto()
{
}

void Auto::conduire() const
{
	cout<<" start Auto conduire"<<endl;
}
