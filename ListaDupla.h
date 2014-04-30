#ifndef LISTADUPLA_H
#define LISTADUPLA_H
#include "DadosDuplo.h"
template<class Tipo>
class ListaDupla
{

    public:
	   typedef DadosDuplo<Tipo> *Dado;

       ListaDupla();
       virtual ~ListaDupla();
       int adicionarNoInicio(Tipo &a);
       int adicionarNoFim(Tipo &a);
       int adicionarNaPosicao(Tipo &a,int pos);
       int adicionarEmOrdem(Tipo &a);
       Tipo* get(int n);
       Tipo* retirarDoFim();
       Tipo* retirarDoInicio();
       Tipo* retirarDaPosicao(int pos);
       Tipo* retiraEspecifico(Tipo &a);
       void mostrar();
       int tamanho;
    protected:
    private:
       DadosDuplo<Tipo> *cabeca;

       bool vazio();
       int posicao(Tipo a);
};
#include "ListaDupla.hpp"
#endif
