#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid1, pid2;
	int i, j, k;
        char c='a';
	pid1 = fork();	
	// child1
	if (pid1 == 0) {
		for (i = 0; i < 26; i++) {
			sleep(1);
			printf("%c ",c+i);
		}
		
		
	} 
	// father
	else {
		pid2 = fork();
		if (pid2 == 0) {		
			printf("mypid=%d,myfatherpid=%d\n",getpid(),getppid());
			
		} else {
					
			printf("i am father pid=%d\n",getpid());
			wait(&pid1);
			wait(&pid2);
		}
	}
	
	
	return 0;

}




