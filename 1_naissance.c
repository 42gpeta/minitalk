#include <unistd.h> // fork()
#include <stdio.h> // printf
#include <fcntl.h> // type 'pid_t'

int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
		printf("erreur\n");

	if(pid == 0)
		printf("fils : PID = %d\n", pid);
	else if(pid > 0)
		printf("père : PID = %d\n", pid);

	return(0);
}