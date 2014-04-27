/* 
 * File:   processoDix.cpp
 * Author: decker
 * 
 * Created on April 24, 2014, 9:31 AM
 */

#include "processoDix.h"

processoDix::processoDix(std::string nome, double instanteChegada, int tempoExecucao, int nice) {
    this->nome = nome;
    this->instanteChegada = instanteChegada;
    this->nice = nice;
    this->tempoExecucao = tempoExecucao;
}

void processoDix::mudarEstado(processoDix::estados novoEstado) {
    this->estadoAtual = novoEstado;
}
int processoDix::executar(){

}
processoDix::~processoDix() {

}


