/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/21 15:20:43 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_pid(void)
{
	pid_t	pid;

	pid = getpid();

	printf("PID : %d\n", pid); // ! ft_print a la fin
}

void	handle_sigtstp(int signal)
{
	printf("\nTEST, ça fonctione\n");
}

int main(int ac, char **av)
{
	struct sigaction sa;
	// sigaction sa;
	
	sa.sa_handler = &handle_sigtstp;
	sigemptyset(&sa.sa_mask); // initialise tous les masques a 0
	sa.sa_flags  = 0; // ! test
	// sa.sa_flags  = SA_SIGINFO; // ! real

	sigaction(SIGUSR1, &sa, NULL);
	ft_get_pid();

	while (1)
	{
		sleep(1);
	}

	return (0);
}