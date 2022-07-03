/* fork: create a new process */
#include <stdlib.h> /*needed to define exit() */
#include <unistd.h> /* needed for fork()*/ 
#include <sys/wait.h> /* needed for wait()*/
#include <stdio.h> /*needed for printf() */
int main(int argc, char **argv)
{
	int pid; /* process ID */
	pid = fork();

	if (pid == -1)
	{
		perror("Error");
	}

	else if (pid == 0)
	{
		printf("In Child\n");
		printf("Child process ID => %d\n", getpid());
		
	}
	else
	{
		wait(NULL);
		printf("\n");
		printf("\n");
		printf("IN Parent \n");
		printf("Parent's process ID => %d\n", getpid());
		printf("Child process ID => %d\n", pid);
	}
	sleep(1);
	exit(0);
	
}