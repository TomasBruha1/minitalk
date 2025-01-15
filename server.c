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

// DO NOW: receive message len in bin and convert to 

// DO NOW NOW: find info on git for sending int len

// DO BEFORE LEAVING: commit to GIT to start a super long streak.

// how NOT to print LEN I sent at the beginning? set up other sigs after??
// sigaction within sigaction??
// alloc for max int so 10 + 1 spaces
// allocate for the message +1, int max 2147483647
// memset before using the char at server. Memset the allocated string?
// static for 8 bits, when 8 assemble char and add it to str[i]
// if '\0' send SIGUSR1/2 to print confirmation at client and close it.
// 
// Client's PID -> sigaction siginfo_t si_pid
// Will I need bool for start/stop of sending chars to server? Try without 1st
// Do I need to type out everything that is on my mind? It does help to clear
// my head out with thougts when preparing for new project @ 42 and my atf is better.

// ----------------------------------------------------------------------------

// get PID and print PID upon start // DONE
// message "running and waiting for something to print" + while (1) // DONE
// unused argv -> (void)argv // DONE
// get message length via strlen. // DONE
// send the int len to server, char by char // DONE

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
	(void)argv;
	char	len;
	
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
	ft_printf("Running... waiting for message to print\n");
	ft_printf("Run ./client with server PID and message to send as args.\n");
	fflush(stdout);

	len = malloc(sizeof(char) 100);



	while (1)
		pause();
	return (0);
}
