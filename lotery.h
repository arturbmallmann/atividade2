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
#include "processoDix.h"
#include "Hash.hpp"
using namespace std;
class lotery{
	private:
		typedef Hash<processoDix> Procs;
		Procs pcbs;
		Procs executando;
		Procs prontos;
		Procs bloqueados;
		Procs terminados;
	public:		
		lotery();
		virtual ~lotery();
		processoDix *criarProcesso(string entrada);
};
#endif
