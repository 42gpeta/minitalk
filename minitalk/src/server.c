/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/21 20:03:22 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_pid(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid); // ! ft_print a la fin
}

void	handle_sigtstp(int signal) // ! a supprimer
{
	printf("\nTEST, ça fonctione\n");
}

// void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
void	handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
		printf("SIG 1\n");
	else if (sig == SIGUSR2)
		printf("SIG 2\n");
		
}

int main(int ac, char **av)
{
	pid_t	pid;

	struct sigaction sa;
	// sigaction sa;
	
	pid = getpid();
	// sa.sa_handler = &handle_sigtstp;
	sa.sa_handler = &handle_sigusr;
	sigemptyset(&sa.sa_mask); // initialise tous les masques a 0
	sa.sa_flags  = 0; // ! test
	// sa.sa_flags  = SA_SIGINFO; // ! real

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	// ft_get_pid();
	
	printf("PID : %d\n", pid); // ! ft_print a la fin

	// kill(pid, SIGUSR2);
	while (1)
	{
		sleep(1);
	}

	return (0);
}