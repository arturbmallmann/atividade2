/* 
 * File:   processoDix.cpp
 * Author: decker
 * 
 * Created on April 24, 2014, 9:31 AM
 */

#include "processoDix.h"
#include <iostream>
processoDix::processoDix(std::string nome, double instanteChegada, int tempoExecucao, int nice) {
    this->nome = nome;
    this->instanteChegada = instanteChegada;
    this->nice = nice;
    this->tempoExecucao = tempoExecucao;
}

void processoDix::mudarEstado(processoDix::estados novoEstado) {
    this->estadoAtual = novoEstado;
}
using namespace std;
int processoDix::executar(){
	this->tempoExecucao--;
	cout<<"executando a decrementacao do meu valor restante:\n"<<
	tempoExecucao<<"\n";
	return this->tempoExecucao;
}
processoDix::~processoDix() {

}


