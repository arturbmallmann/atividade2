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
//#include "Hash.h"
#include "processoDix.h"
using namespace std;
class lotery{
	private:
		vector<string>separarParametros(string entrada);
		inline bool isInteger(const std::string & s);
//		typedef Hash<processoDix> Procs;
//		typedef vector<processoDix> Procs;
		typedef map<int,processoDix> Procs;
		typedef pair<int,processoDix> Par;
		int nprocs;
		Procs pcbs;
		Procs executando;
		Procs prontos;
		Procs bloqueados;
		Procs terminados;
	public:		
		lotery();
		virtual ~lotery();
		processoDix *criarProcesso(vector<string> entrada);
		void escalonar();
};
#endif
