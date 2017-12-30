#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid1, pid2;
	int i, j, k;
	pid1 = fork();	
	// child1
	if (pid1 == 0) {
		for (i = 0; i < 50; i++) {
			sleep(1);
			printf("son\n");
		}
		
		
	} 
	// father
	else {
		pid2 = fork();
		if (pid2 == 0) {		
			for (j = 0; j < 50; j++) {
				sleep(1);
				printf("daughter\n");
			}
		} else {
					
			for (k = 0; k < 50; k++) {
				sleep(1);
				// usleep(10000);
				printf("father\n");
			}
			wait(&pid1);
			wait(&pid2);
		}
	}
	
	
	return 0;

}




