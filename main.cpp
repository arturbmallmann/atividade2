#include "lotery.h"
#include "unistd.h"
int main(int argc,char** argv){
	lotery lot;
	while (true){
		sleep(1);
		lot.timeCount++;
		lot.preemptar();
		lot.executar();
	}
//	lot.~lotery();
}
