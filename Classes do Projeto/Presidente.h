#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Diretor.h"

class Presidente : public Diretor{
    public:
        Presidente();
        virtual ~Presidente();

        void concederAumento();

    protected:
        string formacaoMaxima;
};

#endif