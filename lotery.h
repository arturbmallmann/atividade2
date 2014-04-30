/* 
 * File:   main.cpp
 * Author: decker
 *
 * Created on April 24, 2014, 8:55 AM
 */
#ifndef LOTERY_H
#define LOTERY_H
#include <cstdlib>
#include <iosfwd>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include "processoDix.h"
#include "ListaDupla.h"
#include "unistd.h"
using namespace std;
class lotery{
	private:
		vector<string>separarParametros(string entrada);
		inline bool isInteger(const std::string & s);
		typedef ListaDupla<processoDix> Procs;
		int idCount;
		int timeCount;

		Procs pcbs;
		Procs executando;
		Procs prontos;
		Procs bloqueados;
		Procs terminados;
	public:		
		lotery();
		int loop();
		virtual ~lotery();
		processoDix *criarProcesso(vector<string> entrada,int id);
		void preemptar();
		void executar();
		void terminar(processoDix p);
		void bloquear(processoDix p);
		void desbloquear();
		bool chute(int p);
};
#endif
