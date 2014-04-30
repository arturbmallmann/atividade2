/* 
 * File:   processoDix.cpp
 * Author: decker,artur
 * 
 * Created on April 24, 2014, 9:31 AM
 */

#include "processoDix.h"
#include <iostream>
processoDix::processoDix(int id,std::string nome, int iniciar, int tempoExecucao, int nice) {
	this->id = id;
	this->nome = nome;
    this->iniciar = iniciar;
//	this->tempoExecutado = 0;
    this->nice = nice;
    this->tempoExecucao = tempoExecucao;
}
int processoDix::getId(){
	return this->id;
}

bool chute(int p){
	return (rand() % 100)+1 <= 5;
}

bool processoDix::operator==(processoDix a){
	return this->getId() == a.getId();
}

using namespace std;
int processoDix::executar(){
//	this->tempoExecutado++;
//	int restante = tempoExecucao-tempoExecutado;
	tempoExecucao--;
	cout<<"Executando a decrementacao do meu valor. Restante: "<<
	tempoExecucao;
//	restante<<"\n";
	//sorteio aleatório de lock aqui...
	if(tempoExecucao==0){
//	if(restante==0){
		return TERMINADO;
		}
	if(chute(5)){
		return BLOQUEADO;
	}
	return PRONTO;//normal
}
processoDix::~processoDix() {

}
