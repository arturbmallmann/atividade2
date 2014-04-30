/* 
 * File:   processoDix.h
 * Author: decker
 *
 * Created on April 24, 2014, 9:31 AM
 */

#ifndef PROCESSODIX_H
#define	PROCESSODIX_H
#include <cstdlib>
#include <string>

class processoDix {
public:

    enum estados {
        EXECUTANDO,
        PRONTO,
        BLOQUEADO,
        TERMINADO
    };
    processoDix(const int id,std::string nome, int instanteChegada, int tempoExecucao, int nice);
	int executar();
    void mudarEstado(estados novoEstado);
    virtual ~processoDix();
	int getId();
	bool comparaEstado(estados estado);
private:
	int id;
    std::string nome;
    int instanteChegada;
    int tempoExecucao;
	int tempoExecutado;
    int nice;
    estados estado;
};


#endif	/* PROCESSODIX_H */

