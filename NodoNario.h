#ifndef NODONARIO_H
#define NODONARIO_H

#include <vector>
using namespace std;

class NodoNario
{
    public:
        int valor;
        vector<NodoNario*> hijos;
        NodoNario(int valor);
        void agregar(int valor);
        virtual ~NodoNario();
    protected:
    private:
};

#endif // NODONARIO_H
