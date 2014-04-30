#ifndef LISTADUPLA_HPP_
#define LISTADUPLA_HPP_
#include "ListaDupla.h"
template <class T>
ListaDupla<T>::ListaDupla()
{
    tamanho=0;
    cabeca=0;
}
template <class T>
ListaDupla<T>::~ListaDupla()
{
        DadosDuplo<T> *avanca = cabeca;
        DadosDuplo<T> *aux;
        for(int i=0;i<tamanho;i++){
            aux=avanca;
            avanca=avanca->proximo;
            aux->~DadosDuplo();
        }
}

template <class T>
int ListaDupla<T>::adicionarNoInicio(T &b){
    DadosDuplo<T>* novo=new DadosDuplo<T>(b);

        if(vazio()){
            cabeca=novo;
            novo->anterior=novo;
            novo->proximo=novo;
        }else{
        Dado ultimo=cabeca->anterior;
        Dado segundo=cabeca;

        novo->anterior=ultimo;
        novo->proximo=segundo;

        ultimo->proximo=novo;
        segundo->anterior=novo;

        cabeca=novo;
        }
        tamanho++;
        return 1;
}

template <class T>
int ListaDupla<T>::adicionarNoFim(T &b){
    if(vazio()){
        return adicionarNoInicio(b);
    }else{
	    return adicionarNaPosicao(b,tamanho+1);
    }

};

template <class T>
int ListaDupla<T>::adicionarNaPosicao(T& b,int p){
  if(p>tamanho+1)return -1;
  if(p==1){
     return adicionarNoInicio(b);

  }

  else{
      if(p<=tamanho+1){
        DadosDuplo<T>* novo=new DadosDuplo<T>(b);
        Dado pos=cabeca;
        for(int i=1; i<p;i++){
            pos=pos->proximo;
        }

        novo->proximo=pos;
        novo->anterior=pos->anterior;

        novo->anterior->proximo=novo;
        novo->proximo->anterior=novo;
        tamanho++;
        return p;

      }
  }
  return p;

}

template <class T>
int ListaDupla<T>::adicionarEmOrdem(T& b){


    if(vazio()){
       return adicionarNoInicio(b);
    }else{
       // Dado novo=Dado(b);
       DadosDuplo<T> novo=DadosDuplo<T>(b);
        Dado pos=cabeca;
        int i=1;
        for( i=1; i<=tamanho;i++){

           if(novo< *pos)break;
            pos=pos->proximo;
        }
       return adicionarNaPosicao(b,i);
    }

}

//retirar DadosDuplo
template <class T>
T* ListaDupla<T>::retirarDoFim(){
    return retirarDaPosicao(tamanho);

}

template <class T>
T* ListaDupla<T>::retirarDoInicio(){
    return retirarDaPosicao(1);
}

template <class T>
T* ListaDupla<T>::retirarDaPosicao(int p){
    if(p>tamanho){
        return 0;
    }
    if(tamanho==1){
        T *t=cabeca->dado;
        delete(cabeca);
        cabeca=0;
        tamanho--;
        return t;
    }else{
        Dado d=cabeca;
        T *t;
        for(int i=1;i<p;i++){
            d=d->proximo;
        }
        t=d->dado;
        d->proximo->anterior=d->anterior;
        d->anterior->proximo=d->proximo;
        if(p==1){
            cabeca=d->proximo;
        }
        delete(d);
        tamanho --;
        return t;
    }


}


template <class T>
T* ListaDupla<T>::retiraEspecifico(T& b){
    if(vazio()){
        return 0;
    }
    if(&b==cabeca->dado){
        return retirarDoInicio();
    }
       DadosDuplo<T> *avanca = cabeca->proximo;
        for(int i=2;i<tamanho;i++){
            if(&b == avanca->dado){
                return retirarDaPosicao(i);
                break;
            }
            avanca=avanca->proximo;
        }
    return 0;
}

template <class T>
bool ListaDupla<T>::vazio(){
    return tamanho==0;
}
#include <iostream>

template <class T>
void ListaDupla<T>::mostrar() {
    Dado pos=cabeca;
        for(int i=0; i<tamanho;i++){
           std::cout<<*(pos->dado)<<" ";
            pos=pos->proximo;
        }
}
template <class T>
T* ListaDupla<T>::get(int n) {

    Dado pos=cabeca;
        for(int i=1; i<n;i++){
            pos=pos->proximo;
        }
       return pos->dado;
}
template <class T>
T* ListaDupla<T>::ponta(){
	return cabeca->anterior->dado;
}
#endif
