/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/21 20:04:48 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr_client(int sig)
{
	if (sig == SIGUSR1)
		printf("Change la variable globale\n");
	else if (sig == SIGUSR2)
		printf("Message reçu client\n");
}

void	ft_send_message(char *str, pid_t pid)
{
	static int octet;
	static int i;

	i = 0;
	octet = 7;
	
	while (str[i] != '\0')
	{
		if ((1 & (str[i] >> octet)) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		octet--;
	}
}

int	main(int ac, char **av)
{
	struct sigaction sa;
	int	pid;

	pid = ft_atoi(av[1]);
	
	// sa.sa_handler = &handle_sigtstp;
	sa.sa_handler = &handle_sigusr_client;
	sigemptyset(&sa.sa_mask); // initialise tous les masques a 0
	sa.sa_flags  = 0; // ! test
	// sa.sa_flags  = SA_SIGINFO; // ! real

	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	
	// kill(pid, SIGUSR2); // SIGUSR de handle_sigusr
	// int i = 0;
	while (av[2])
		ft_send_message(av[2], pid);
	

	return (0);
}