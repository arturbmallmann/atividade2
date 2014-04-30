/* 
 * File:   main.cpp
 * Author: decker,artur
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
	return parametros;
}

void lotery::escalonar(){
	int ran=rand() % prontos.tamanho;
	cout<<"ticket sorteado: \n"<<ran<<"\n";
	processoDix *pro1=prontos.retirarDaPosicao(ran);
//	cout<<"processo de nome"<<
	pro1->executar();
}

lotery::lotery(){
	string entrada;
    vector<string> argumentos;
    bool finalizouEntrada = false;
    printf("Simulação de um escalonador LOTTERY SCHEDULER\n"
			"Digite o processo a ser inserido da seguinte maneira:\n"
            "nome Instante_de_chegada tempo_de_execução nice[-20..20]\n");
	int keys;
    while (!finalizouEntrada) {
        getline(std::cin, entrada);
        argumentos = separarParametros(entrada);
        if(argumentos.size()==4){
			processoDix *processo=criarProcesso(argumentos);
			int nice=::atoi(argumentos[3].c_str());
			if (nice>=-20&&nice<=20){
				for(int n = 41;n-20!=nice;n--){
					keys++;
					this->prontos.adicionarNoFim(*processo);
					cout<<"ticket:"<<n<<"\n";
				}
				this->pcbs.adicionarNoFim(*processo);
				this->nprocs=keys;
			}else{cout<<"valor nice nao suportado\n";}
		}else if (argumentos.size() == 0) {
            finalizouEntrada = true;
        }else if (argumentos.size() != 4) {
            printf("Argumentos insuficientes!\n");
        }
	}
}
lotery::~lotery(){
	/*arrumas */
/*	for(int i=prontos.size()-1;i!=-1;i--){
		cout<<"deletando ="<<i<<"\n";
		delete &prontos[i];
		prontos.pop_back();
	}
	for(int i=terminados.size();i!=0;i--){
		delete &terminados[i];
		terminados.pop_back();
	}*/
}
