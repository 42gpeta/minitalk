/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/17 16:49:00 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_pid(void)
{
	pid_t	pid;

	pid = getpid();

	printf("PID :%d\n", pid); // ! ft_print a la fin
}

int main(int ac, char **av)
{
	struct sigaction sa;
	
	ft_get_pid();
	

	return (0);
}