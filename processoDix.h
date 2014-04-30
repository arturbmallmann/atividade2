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
#define EXECUTANDO 3
#define PRONTO 2
#define BLOQUEADO 1
#define TERMINADO 0
class processoDix {
public:

/*    enum estados {
        EXECUTANDO,
        PRONTO,
        BLOQUEADO,
        TERMINADO
    };*/
    processoDix(const int id,std::string nome, int iniciar, int tempoExecucao, int nice);
    virtual ~processoDix();

	int executar();
	int getId();
	bool operator==(processoDix a);
private:
	int id;
    std::string nome;
    int iniciar;
    int tempoExecucao;
	int tempoExecutado;
    int nice;
};


#endif	/* PROCESSODIX_H */

