/*
 * File:   DadosDuplo.h
 * Author: wagner
 *
 * Created on May 8, 2013, 10:58 AM
 */

#ifndef DADOSDUPLO_H
#define	DADOSDUPLO_H
#include<stdlib.h>

template<class Tipo>
class DadosDuplo {
public:
    Tipo *dado;
    DadosDuplo *proximo;
    DadosDuplo *anterior;
    DadosDuplo(Tipo &a);

    bool operator==(DadosDuplo a);
    bool operator<(DadosDuplo a);
    bool operator>(DadosDuplo a);
    virtual ~DadosDuplo();
protected:
private:
};

template <typename T>
DadosDuplo<T>::DadosDuplo(T &a) {
    dado = &a;
    proximo = NULL;
}

template <typename T>
DadosDuplo<T>::~DadosDuplo() {

}

template <typename T>
bool DadosDuplo<T>::operator==(DadosDuplo<T> a) {
	//std::cout<<"entrou no op == de DadosDuplos ==============!\n";
    if ( this->dado == a->dado )return true;
    return false;
}

template <typename T>
bool DadosDuplo<T>::operator<(DadosDuplo<T> a) {
    if ( *(this->dado) < *(a.dado) )return true;
    return false;
}

template <typename T>
bool DadosDuplo<T>::operator>(DadosDuplo<T> a) {
    if ( *(this->dado) > *(a.dado) )return true;
    return false;
}


#endif	/* DADOSDUPLO_H */

