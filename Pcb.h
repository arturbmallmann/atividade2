#ifndef PCB_H
#define PCB_H
#include <string>
class Pcb{
	public:
		Pcb();
		Pcb(std::string nome,double chegada,double tempo,int nice);
		virtual ~Pcb();
		int run();
	private:
		int rtime;

};
#endif
