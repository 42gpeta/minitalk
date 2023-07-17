/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/17 18:01:30 by gpeta            ###   ########.fr       */
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
	
	ft_get_pid();
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags  = SA_RESTART; // ! test
	// sa.sa_flags  = SA_SIGINFO; // ! real

	sigaction(SIGTSTP, &sa, NULL);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("result %d * 5 = %d\n", x, x * 5);

	return (0);
}