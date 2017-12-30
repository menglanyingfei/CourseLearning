#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	pid_t pid1, pid2, pid;
	int i;
	
	while( (pid1=fork())==-1)
		;
	if(pid1==0){ //child1
		printf("I am child1,pid=%d,parent pid=%d\n",getpid(),getppid());
		//execl("/bin/ls", "ls", "executed by excel", NULL);
		exit(1); 
	}else{ 
		while( (pid2=fork())==-1)
			;
		if(pid2==0){ //child2
			printf("I am child2,pid=%d,parent pid=%d,I will sleep for 5 seconds!\n",getpid(),getppid());                        
			sleep(5);                        
			printf("I am child2.I have awaked and I will exit!\n");                        
			exit(2);        

		}
		//father
		int status_val1,status_val2;
		pid=waitpid(pid1,&status_val1,0);
		pid = waitpid(pid2,&status_val2,WNOHANG);
		printf("I am father,pid=%d\n",getpid());
		if(WIFEXITED(status_val1))
		{
			printf("child1 exit with code %d\n",WEXITSTATUS(status_val1));	
		}
		if(WIFEXITED(status_val2))
		{
			printf("child2 exit with code %d\n",WEXITSTATUS(status_val2));	
		}
		
		exit(0);	
	}
}
