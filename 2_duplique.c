#include <unistd.h> // fork()
#include <stdio.h> // printf
#include <fcntl.h> // type 'pid_t'
#include <stdlib.h> // EXIT_FAILLURE


void	routine_fils(pid_t pid, int *nb)
{
	printf("Fils : Hello, je suis le fils. PID recu de fork() : %d\n", pid);
	printf("Fils : le nombre est %d\n", *nb);
}

void	routine_pere(pid_t pid, int *nb)
{
	printf("Père : Hello, je suis le père. PID recu de fork() : %d\n", pid);
	printf("Père : le nombre est %d\n", *nb);
	*nb *= 2;
	printf("Père : le nombre modifié est %d\n", *nb);
}


int main()
{
	pid_t pid;
	int		nb;

	nb = 42;

	printf("Avant fork, le nombre est %d\n", nb);
	pid = fork();

	if (pid < 0)
		return (EXIT_FAILURE);
	else if (pid == 0)
		routine_fils(pid, &nb);
	else if (pid > 0)
		routine_pere(pid, &nb);
	return (EXIT_SUCCESS);
	
}