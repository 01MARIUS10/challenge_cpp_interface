#ifndef VEHICULE_HPP
#define VEHICULE_HPP
#include <iostream>

class Vehicule {
    public:
        Vehicule();
        void display();
        virtual void conduire() const = 0;
    protected:
        std::string marque;
};

#endif
