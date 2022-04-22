#ifndef DIRETOR_H
#define DIRETOR_H

#include "Gerente.h"

class Diretor : public Gerente{
    public:
        Diretor();
        virtual ~Diretor();

        void concederAumento();

        std::string getAreaSupervisao();
        void setAreaSupervisao(std::string aS);

        std::string getAreaFormacao();
        void setAreaFormacao(std::string aF);

    protected:
        std::string areaSupervisao;
        std::string areaFormacao;
};

#endif