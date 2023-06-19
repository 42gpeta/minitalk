#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Fils : Je suis le fils est mon PID est %d.\n", pid);
		sleep(1);
		printf("Fils : Terminé !\n");
	}
	else if (pid > 0)
	{
		printf("Père : Je suis le père, le PID de mon fils est %d.\n", pid);
		printf("Père : Terminé !\n");
	}

	return(0);
}