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
		timeCount++;
		preemptar();
		executar();
	}while(pcbs.tamanho!=0);
	cout<<"\nterminado\n";
	return 0;
}

void lotery::bloquear(processoDix p){
	processoDix *aux;
	while(true){
		aux = prontos.retiraEspecifico(p);
		if(aux!=0)
			bloqueados.adicionarNoInicio(*aux);
		else
			return;
	}
}

void lotery::terminar(processoDix p){
	processoDix *aux;
	while(true){
		aux = prontos.retiraEspecifico(p);
		if(aux!=0)
			terminados.adicionarNoInicio(*aux);
		else 
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

void lotery::preemptar(){ /*
	cout<<"entrou no preemt! prontos:"<<prontos.tamanho
		<<" executando:"<<executando.tamanho<<"\n";// */
	if(executando.tamanho!=0){//retira do executando
		processoDix *antigo = executando.retirarDoFim();
		prontos.adicionarNoInicio(*antigo);	
	}
//	bool ok=false;
	int ran;
//	while (!ok){
	if(prontos.tamanho!=0){
		ran=(rand() % prontos.tamanho)+1;//sortei o ticket que executara [0,tamanho)
		cout<<"sorteado:"<<ran<<" prontos: "<<prontos.tamanho<<" \n";
		processoDix *novo=prontos.retirarDaPosicao(ran);
//		if(novo->comparaEstado(processoDix::PRONTO)){//aqui temos um pseudo garbage colector hhehe
//				ok=true;*/
		executando.adicionarNoInicio(*novo);

/*			}else if(novo->comparaEstado(processoDix::BLOQUEADO)){
				bloqueados.adicionarNoInicio(*novo);
			}else if(novo->comparaEstado(processoDix::TERMINADO)){
				cout<<"tirando tickets de processo terminado id: "<<novo->getId()<<"tickets restantes= "<<prontos.tamanho<<"\n";
				terminados.adicionarNoInicio(*novo);
				if(pcbs.retiraEspecifico(*novo)==0)
					cout<<"processo: "<<novo->getId()<<"deixou lixo mas non ecsiste mais\n";
			}
		}// */
	}
}

void lotery::executar(){
	if(executando.tamanho!=0){
	processoDix *proc=executando.ponta();
	cout<<"processo id: "<<proc->getId();
	int r=proc->executar();
		switch(r){
			case 0:cout<<" terminou\n";break;//por fim nem usei...
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
