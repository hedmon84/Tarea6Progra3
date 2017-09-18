#ifndef PAIS_H
#define PAIS_H

#include <iostream>
using namespace std;

class Pais
{
    public:
        string nombre;
        int habitantes;
        bool hablan_espanol;

        Pais();
        Pais(string nombre, int habitantes, bool hablan_espanol);
        virtual ~Pais();
    protected:
    private:
};

#endif // PAIS_H
