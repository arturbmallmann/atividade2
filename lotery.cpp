/* 
 * File:   main.cpp
 * Author: decker
 *
 * Created on April 24, 2014, 8:55 AM
 */

#include "lotery.h"

processoDix *lotery::criarProcesso(vector<string> entrada) {
    string nome = entrada[0];
    string instanteChegada = entrada[1];
    string stringTempoExecucao = entrada[2];
    int tempoExecucao = ::atof(stringTempoExecucao.c_str());
	double chegada = ::atof(instanteChegada.c_str());
    int nice = ::atoi(entrada[3].c_str());
    /* Padrão: Nome instanteChegada TempoExec Nice*/
    return new processoDix(nome,chegada,tempoExecucao,nice);
}
inline bool lotery::isInteger(const string & s) {
    if ((s.empty()) || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
        return false;
    }
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}
vector<string> lotery::separarParametros(string entrada) {
    string buffer;
    vector<string> parametros;
    stringstream ss(entrada);
    //separando a entrada
    while (ss >> buffer) {
	        parametros.push_back(buffer);
    }
	cout<<"criando processo: parametros[0]\n	"<<
	parametros[1]<<"\n	chegada: "<<
	parametros[2]<<"\n	tempodE: "<<
	parametros[3]<<"\n	nice:	 ";
	return parametros;
}
lotery::lotery(){
    string entrada;
    vector<string> argumentos;
    bool finalizouEntrada = false;
    printf("Simulação de um escalonador LOTTERY SCHEDULER\n"
			"Digite o processo a ser inserido da seguinte maneira:\n"
            "nome Instante_de_chegada tempo_de_execução nice\n");
    while (!finalizouEntrada) {
        getline(std::cin, entrada);
        argumentos = separarParametros(entrada);
        if (argumentos.size() == 0) {
            finalizouEntrada = true;
            break;
        }
        if (argumentos.size() != 4) {
            printf("Argumentos insuficientes!");
            break;
        }
		prontos.push_back(*criarProcesso(argumentos));
	}
}
lotery::~lotery(){

}
