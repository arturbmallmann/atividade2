/* 
 * File:   main.cpp
 * Author: decker,artur
 *
 * Created on April 24, 2014, 8:55 AM
 */

#include "lotery.h"
int lotery::loop(){
	do{
		cout<<"PCBs= "<<pcbs.tamanho<<"\n"
			<<"tickets:\n"
			<<"	Block= "<<bloqueados.tamanho<<"\n"
			<<"	Terminados= "<<terminados.tamanho<<"\n";
		sleep(1);
		desbloquear();
//		timeCount++;
		preemptar();
		executar();
	}while(pcbs.tamanho!=0);
	cout<<"\nterminado\n";
	return 0;
}

void lotery::desbloquear(){
	processoDix *aux;
	if(chute(5)==true){
			if(bloqueados.tamanho!=0){
				int ran= 1 + (rand() % bloqueados.tamanho);//sortei o ticket que executara [0,tamanho)
				aux=bloqueados.retirarDaPosicao(ran);
				prontos.adicionarNoInicio(*aux);
			
//		cout<<"Desbloqueando ID="<<aux->getId()<<"\n";
			while(true){
				aux = bloqueados.retiraEspecifico(*aux);//enquanto ouver ticket ele manda pra prontos
				if(aux!=0)
					prontos.adicionarNoInicio(*aux);
				else
					return;
			}
		}
	}
}
void lotery::bloquear(processoDix p){
	processoDix *aux;
	executando.retiraEspecifico(p);
	bloqueados.adicionarNoInicio(p);
	while(true){
		aux = prontos.retiraEspecifico(p);
		if(aux!=0)
			bloqueados.adicionarNoInicio(p);
		else
			return;
	}
}

void lotery::terminar(processoDix p){//aqui ta indo lindo
	processoDix *aux=&p;
	executando.retiraEspecifico(*aux);
	pcbs.retiraEspecifico(*aux);
	while(true){
		aux = prontos.retiraEspecifico(p);
		if(aux!=0){
			cout<<"tirou\n";
			terminados.adicionarNoInicio(*aux);
		}else 
			return;
	}
}

processoDix *lotery::criarProcesso(vector<string> entrada,int id) {
    string nome = entrada[0];
	string stringTempoIniciar = entrada[1];
    int tempoIniciar = ::atoi(stringTempoIniciar.c_str());
    string stringTempoExecucao = entrada[2];//2
    int tempoExecucao = ::atoi(stringTempoExecucao.c_str());
    int nice = ::atoi(entrada[3].c_str());//3 //lembrete atoi> int,atof>double
    /* Padrão: Nome instanteChegada TempoExec Nice*/
    return new processoDix(id,nome,tempoIniciar,tempoExecucao,nice);
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

bool lotery::chute(int p){
	return (rand() % 100)+1 <= 5;
}

void lotery::preemptar(){
	if(executando.tamanho!=0){
		processoDix *antigo = executando.retirarDoInicio();
		prontos.adicionarNoInicio(*antigo);	
	}
	if(prontos.tamanho!=0){
		int ran= 1 + (rand() % prontos.tamanho);//sortei o ticket que executara [0,tamanho) + 1 = [1 .. tamanho]
		cout<<"sorteado:"<<ran<<" prontos: "<<prontos.tamanho<<" \n";
		processoDix *novo=prontos.retirarDaPosicao(ran);
		executando.adicionarNoFim(*novo);
	}
}

void lotery::executar(){
	if(executando.tamanho!=0){
	processoDix *proc=executando.ponta();
	cout<<"processo id: "<<proc->getId();
	int r=proc->executar();
	
		switch(r){
			case TERMINADO:
				cout<<"!========DEVE RETIRAR AGORA=======!\n\n";
				terminar(*proc);break;//por fim nem usei...
			case BLOQUEADO:
				bloquear(*proc);break;
			default:cout<<" normal\n";
		}
	}
}

lotery::lotery(){
	idCount = 0;
	timeCount = 0;
	string entrada;
    vector<string> argumentos;
    bool finalizouEntrada = false;
    printf("Simulação de um escalonador LOTTERY SCHEDULER\n"
			"Digite o processo a ser inserido da seguinte maneira:\n"
            "nome [hora de comecar] [tempo do programa] nice[-20..20]\n");
	int keys;
    while (!finalizouEntrada) {
        getline(std::cin, entrada);
        argumentos = separarParametros(entrada);
		timeCount++;//gambiarra we know..
        if(argumentos.size()==4){
			idCount++;
			processoDix *processo=criarProcesso(argumentos,idCount);
			int nice=::atoi(argumentos[3].c_str());
			if (nice>=-20&&nice<=20){
				for(int n = 41;n-20!=nice;n--){
					keys++;
					this->prontos.adicionarNoFim(*processo);
					cout<<"ticket:"<<n<<"\n";
				}
				this->pcbs.adicionarNoFim(*processo);
			}else{cout<<"valor nice nao suportado\n";}
		}else if (argumentos.size() == 0) {
            finalizouEntrada = true;
        }else {
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
