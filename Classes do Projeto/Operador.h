#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionarios.h"

class Operador : public Funcionarios{
    public:
        Operador();
        virtual ~Operador();

        void Modificar();
        void concederAumento();

    private:
};

#endif