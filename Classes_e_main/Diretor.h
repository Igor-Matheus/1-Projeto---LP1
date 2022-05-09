#ifndef DIRETOR_H
#define DIRETOR_H

#include "Gerente.h"

class Diretor : public Gerente{
    public:
        Diretor();
        virtual ~Diretor();

        void concederAumento();

    protected:
};

#endif