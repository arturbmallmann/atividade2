/* 
 * File:   main.cpp
 * Author: decker
 *
 * Created on April 24, 2014, 8:55 AM
 */

#include "lotery.h"

using namespace std;
processoDix *lotery::criarProcesso(string entrada) {
    string buffer;
    vector<string> parametros;
    stringstream ss(entrada);
    //separando a entrada
    while (ss >> buffer) {
        parametros.push_back(buffer);
    }
    //entrada já separada
    //arrumando os tipos
    string nome = parametros[0];
    string instanteChegada = parametros[1];
    string stringTempoExecucao = parametros[2];
    //assumindo que ja tá tratado essa porra
    int tempoExecucao = ::atof(stringTempoExecucao.c_str());
	double chegada = ::atof(instanteChegada.c_str());
    int nice = ::atoi(parametros[3].c_str());
    //criando processo
    // Padrão: Nome instanteChegada TempoExec Nice
	return new processoDix(nome,chegada,tempoExecucao,nice);
}
lotery::lotery(){
	processoDix *aux;
	string entrada;

	do{/*criando os processos*/
		getline(cin,entrada);
		aux=criarProcesso(entrada);
		if(aux!=0)
			prontos.put(aux);
	}while(aux != 0);
}
int main(int argc,char** argv){
	lotery lotery;
}
