#ifndef GERENTE_H
#define GERENTE_H

#include "Operador.h"

class Gerente : public Operador{
    public:
        Gerente();
        ~Gerente();

        void concederAumento();

    protected:
};

#endif