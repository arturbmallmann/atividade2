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
	this->tempoExecutado = 0;
    this->nice = nice;
    this->tempoExecucao = tempoExecucao;
	this->estado = PRONTO;
}
int processoDix::getId(){
	return this->id;
}
bool processoDix::operator==(processoDix a){
	std::cout<<"!=======Entrou na comparacao=======!\n";
	return this->getId() == a.getId();
//	return (this *) == &a;
}
bool processoDix::comparaEstado(int estado){
	return (this->estado==estado);
}
//void processoDix::mudarEstado(processoDix::estados novoEstado) {
void processoDix::mudarEstado(int novoEstado) {
    this->estado = novoEstado;
}
using namespace std;
int processoDix::executar(){
	this->tempoExecutado++;
	int restante = tempoExecucao-tempoExecutado;
	cout<<"Executando a decrementacao do meu valor. Restante: "<<
	restante<<"\n";
	//sorteio aleatório de lock aqui...
	if(restante<=0){
		this->estado=TERMINADO;
		return this->estado;
		}
	return 1;//normal
}
processoDix::~processoDix() {

}
