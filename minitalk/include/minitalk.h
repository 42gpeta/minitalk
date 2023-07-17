/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:33:01 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/17 18:01:02 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/**** INCLUDE A supprimer ****/ // ! a supprimer
# include <stdio.h>
# include <stdlib.h>

/* ************************************************************************** */
/*							      	 INCLUDE							      */
/* ************************************************************************** */
# include <limits.h> // ! a supprimer ??
# include "libft.h"
# include <unistd.h> // fork()
# include <fcntl.h> // type 'pid_t'
# include <signal.h> // sigaction

/* ************************************************************************** */
/*							      	 STRUCURE							      */
/* ************************************************************************** */

// struct sigaction {
// 	void		(*sa_handler)(int);
// 	void		(*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t	sa_mask;
// 	intvoid		sa_flags;
// 	void		(*sa_restorer)(void);
// };

/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
client.c
*************/


/*************
server.c
*************/
void    ft_get_pid(void);
void	handle_sigtstp(int signal);


# endif