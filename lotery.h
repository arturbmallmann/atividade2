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
#include "processoDix.h"
#include "Pcb.h"
#include "Hash.hpp"
using namespace std;
typedef Hash<Pcb> Procs;
Procs ready;
Procs locked;
Pcb running;

processoDix criarProcesso(string entrada);


#endif
