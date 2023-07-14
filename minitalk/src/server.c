/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:30:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/14 16:36:38 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_get_pid(void)
{
    pid_t   pid;

    pid = getpid();

    printf("PID :%d\n", pid);
}

int main(int ac, char **av)
{
    ft_get_pid();

    return (0);
}