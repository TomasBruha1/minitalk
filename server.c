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

// Do NOW: 

// get message length via strlen
// send the int len to server
// allocate for the message +1, int max 2147483647
// memset before using the char at server
// Client's PID -> sigaction siginfo_t si_pid

// ----------------------------------------------------------------------------

// get PID and print PID upon start // DONE
// message "running and waiting for something to print" + while (1) // DONE

#include "minitalk.h"

char	g_bites;

void	handle_sigusrs(int signum)
{
	char	to_print;
	
	to_print = '0';
	while (g_bites < 8)
	{
		if (signum == SIGUSR1)
		{
			
		}
		else
		{

		}
		g_bites++;
	}
}

int	main(int argc, char **argv)
{	
	// struct sigaction 	sa;

	// sa.sa_handler = handle_sigint;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = 0;
	
	if (argc != 1)
		return (EXIT_FAILURE);
	signal(SIGUSR1, handle_sigusrs);
	signal(SIGUSR2, handle_sigusrs);
//	sigaction(SIGINT, &sa, NULL);
	ft_printf("Server PID is %d.\n", getpid());
	fflush(stdout);
	while (1)
		pause();
	return (0);
}
