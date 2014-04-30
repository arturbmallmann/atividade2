/* 
 * File:   processoDix.h
 * Author: decker,artur
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
    processoDix(const int id,std::string nome, int iniciar, int tempoExecucao, int nice);
    virtual ~processoDix();

    void mudarEstado(estados novoEstado);
	int executar();
	int getId();
	bool comparaEstado(estados estado);
	bool operator==(processoDix a);
private:
	int id;
    std::string nome;
    int iniciar;
    int tempoExecucao;
	int tempoExecutado;
    int nice;
    estados estado;
};


#endif	/* PROCESSODIX_H */

