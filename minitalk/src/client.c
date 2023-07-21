/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/21 15:14:58 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int	main(int ac, char **av)
// {
// 	pid_t pid;
// 	struct sigaction sa;
	
// 	pid = ft_atoi(av[1]);
	
// 	sa.sa_handler = kill(pid, SIGTSTP);
	
// 	// sa.sa_handler = &handle_sigtstp;
// 	sa.sa_flags  = SA_RESTART; // ! test
// 	// sa.sa_flags  = SA_SIGINFO; // ! real

// 	sigaction(SIGTSTP, &sa, NULL);

// 	int x;
// 	printf("Input number: ");
// 	scanf("%d", &x);
// 	printf("result %d * 5 = %d\n", x, x * 5);
// 	return (0);
// }

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);

	printf("Envoi du signal SIGUSR1 au serveur (PID: %d)\n", pid);
	kill(pid, SIGUSR1);

	return (0);
}