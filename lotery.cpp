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
#include "processoDix.h"
#include "Hash.hpp"
using namespace std;

processoDix criarProcesso(string entrada) {
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
    double tempoExecucao = ::atof(stringTempoExecucao.c_str());
    int nice = ::atoi(parametros[3].c_str());
    //criando processo
    // Padrão: Nome instanteChegada TempoExec Nice
}

int main(int argc, char** argv) {

    return 0;
}

