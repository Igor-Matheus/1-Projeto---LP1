#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H

class GerenciaFuncionario{
    public:
        GerenciaFuncionario();
        ~GerenciaFuncionario();
        virtual double calculaSalario(double salario) = 0;

    private:
};

#endif