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
    processoDix(std::string nome, std::string instanteChegada, int tempoExecucao, int nice);

    void mudarEstado(estados novoEstado);
    virtual ~processoDix();
private:
    std::string nome;
    std::string instanteChegada;
    int tempoExecucao;
    int nice;
    estados estadoAtual;

};


#endif	/* PROCESSODIX_H */

