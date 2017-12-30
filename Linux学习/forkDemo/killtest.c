#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	int retval;
	pid = fork();
		
	if (pid < 0) {
		perror("fork failed");
		exit(1); 
	} 
	if (pid == 0) {
	    printf("%d pid I am child 111\n", getpid());
	    sleep(3);
	    printf("I am child 222\n");
	    exit(0);
	}
	// father
	else {
        printf("I am father \n");
        sleep(1);
        if (0 == waitpid(pid, NULL, WNOHANG)) {
            retval = kill(pid, SIGKILL);
            if (0 == retval)
                printf("%d is killed!\n", pid);
            else
                printf("kill fail\n");
        }
	}
	
	
	return 0;

}




