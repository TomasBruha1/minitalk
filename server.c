/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:26 by tbruha            #+#    #+#             */
/*   Updated: 2024/12/06 11:40:00 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigint(int signum)
{
	printf("\nReceived signal number %d.\n", signum);
	printf("Exiting with peace on my mind (aka status 0).\n");
	exit(0);
}

void	handle_sigusr1(int signum)
{
	printf("Received signal number %d.\n\n", signum);
	printf("Hello World\n");
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction 	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
		
	server_pid = getpid();
	signal(SIGUSR1, handle_sigusr1);
	sigaction(SIGINT, &sa, NULL);
	// signal(SIGINT, handle_sigint);
	printf("Server PID is %d.\n", server_pid);
	fflush(stdout);
	printf("Running... waiting for stuff to print...\n\n");
	while (1)
		pause();
	return (0);
}