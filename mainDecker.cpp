/* 
 * File:   main.cpp
 * Author: decker
 *
 * Created on April 24, 2014, 8:55 AM
 */

#include <cstdlib>
#include <iosfwd>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include "processoDix.h"
using namespace std;

// let it #define
#define ET_NOT_INTEGER -1
#define NICE_NOT_INTEGER -2
// parara tim bum

inline bool isInteger(const string & s);

processoDix* criarProcesso(vector<string> entrada) {

    //criando processo

    // Padrão: Nome instanteChegada TempoExec Nice

}

//REMEMBER : PARE DE USAR FUNCOES MEGAZORD!

/*@Funcao Separa entrada por espacos e retorna num vector @Argumentos string entrada - string a ser separada*/
vector<string> separarParametros(string entrada) {
    string buffer;
    vector<string> parametros;
    stringstream ss(entrada);
    //separando a entrada
    while (ss >> buffer) {
        parametros.push_back(buffer);
    }
    //entrada já separada


}

inline bool isInteger(const string & s) {
    if ((s.empty()) || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
        return false;
    }
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

int main(int argc, char** argv) {
    string entrada;
    vector<string> argumentos;
    bool finalizouEntrada = false;
    printf("Simulação de um escalonador LOTTERY SCHEDULER\nDigite o processo a ser inserido da seguinte maneira:"
            " nome Instante_de_chegada tempo_de_execução nice");
    while (!finalizouEntrada) {
        getline(std::cin, entrada);
        argumentos = separarParametros(entrada);
        if (argumentos.size() == 0) {
            finalizouEntrada == true;
            break;
        }
        if (argumentos.size() != 4) {
            printf("Argumentos insuficientes!");
            break;
        }
        return 0;
    }
}

