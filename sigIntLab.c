#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//global variables definitions:
int i;
int mask;
int k;
mask = -1;

i=0;
k=0;
void sig_handler(int sig);

int main(){
	if(signal(SIGINT, sig_handler) == SIG_ERR){
		printf("SIGINT wont get caught");
	}
	int j;
	j=1;
	while(1){
		sleep(2);
		if(i ==-1){
			printf("The program has run %d times.\n", j);
			if(k!= 0){
				retrun 0;
			}
		}
		++j;
	}
}

void sig_handler(int sig){
	if(sig ==SIGINT) i = i^mask;
	else if(sig == SIGSR1) k= -1;
}