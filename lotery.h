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
#include <string>
//#include "Hash.h"
#include "processoDix.h"
using namespace std;
class lotery{
	private:
		vector<string>separarParametros(string entrada);
		inline bool isInteger(const std::string & s);
//		typedef Hash<processoDix> Procs;
		typedef vector<processoDix> Procs;
		Procs pcbs;
		Procs executando;
		Procs prontos;
		Procs bloqueados;
		Procs terminados;
	public:		
		lotery();
		virtual ~lotery();
		processoDix *criarProcesso(vector<string> entrada);
};
#endif
