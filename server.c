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

// DO NOW NOW: Set up flag for sending another char and usleep for lower. 
// DO NOW NOW NOW: change signal to sigaction and get clients PID.


#include "minitalk.h"

char	g_msg[1000]; // Could it be just a static? Why do I have global

// Handles SIGUSR1 and 2. 
void	handle_sigusrs(int signum)
{
	static int	bites;
	static int	i;
	static int	j;

	if (signum == 12)
		bites = bites | (128 >> i);
	i++;
	if (i == 8)
	{
		g_msg[j] = bites;
		kill()
		if (bites == '\0')
		{
			ft_printf("%s\n\n", g_msg);
			ft_bzero(g_msg, 0);
			bites = 0;
			i = 0;
			// print and send SIGUSR1 to client as confirmation
			return;
		}
		bites = 0;
		i = 0;
		j++;
	}
//	How to receive multiple messages while running?
}

// Prints out it's PID and waits for msg. Then prints it char by char now.
// After receiving the entire message it will send SIGUSR1 back as confirmation
// I will do it char by char now and switch to full message later. UNI should work.
int	main(int argc, char **argv)
{	
	(void)argv;
	
	// struct sigaction 	sa;

	// sa.sa_handler = handle_sigint;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("No arguments allowed\n");
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, handle_sigusrs);
	signal(SIGUSR2, handle_sigusrs);
//	sigaction(SIGINT, &sa, NULL);
	ft_printf("Server PID is %d.\n", getpid());
	ft_printf("Waiting for message to print.\n\n");
	ft_printf("Run ./client with server PID and message to send as args.\n");
//	fflush(stdout);
	while (1)
		pause();
	return (0);
}

// Client's PID -> sigaction siginfo_t si_pid
// memset/bzero memory on heap? It is necessary?
// When char is assembled, send SIGUSR1 to send another char.
// When '\0' is received, send SIGUSR2 to print confirmation at client.
// After printing final msg, reset msg with bzero so it can receive new one.

// ----------------------------------------------------------------------------

// Emojis are working now. // DONE
// NOW: print stuff char by char on server side, check if condition. // DONE
// It receives multiple messages from different terminals. // DONE
// static for 8 bits, when 8 assemble char and add it to str[i] // DONE
// get PID and print PID upon start // DONE
// message "running and waiting for something to print" + while (1) // DONE
// unused argv -> (void)argv // DONE
// get message length via strlen. // DONE
// send the int len to server, char by char // DONE