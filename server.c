/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:26 by tbruha            #+#    #+#             */
/*   Updated: 2024/12/06 12:04:52 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigint(int signum)
{
	ft_printf("\nReceived signal number %d.\n", signum);
	ft_printf("Exiting with peace on my mind (aka status 0).\n");
	exit(0);
}

void	handle_sigusr1(int signum)
{
	ft_printf("Received signal number %d.\n\n", signum);
	ft_printf("Hello World\n");
}

void	handle_sigusr2(int signum)
{
	ft_printf("%d", signum);
	return ;
}

int	main(void)
{
	struct sigaction 	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
		
	signal(SIGUSR1, handle_sigusr1);
	sigaction(SIGINT, &sa, NULL);
	// signal(SIGINT, handle_sigint);
	ft_printf("Server PID is %d.\n", getpid());
	fflush(stdout);
	ft_printf("Running... waiting for stuff to print...\n\n");
	while (1)
		pause();
	return (0);
}