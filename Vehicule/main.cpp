#include "./Moto/Moto.hpp"
#include "./Auto/Auto.hpp"
#include "./Vehicule.hpp"


int main()
{
    // Vehicule A;
    // A.display();

    Moto B;
    B.conduire();
    B.display();

    Auto C;
    C.conduire();
    C.display();

    return 0;
}
