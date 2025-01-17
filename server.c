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

// NOW: print stuff char by char on server side

// how NOT to print LEN I sent at the beginning? set up other sigs after??
// sigaction within sigaction??
// alloc for max int so 10 + 1 spaces
// allocate for the message +1, int max 2147483647
// memset before using the char at server. Memset the allocated string?
// static for 8 bits, when 8 assemble char and add it to str[i]
// if '\0' send SIGUSR1/2 to print confirmation at client and close it.
// Client's PID -> sigaction siginfo_t si_pid
// Will I need bool for start/stop of sending chars to server? Try without 1st
// How to re-alocatte without realloc?

// ----------------------------------------------------------------------------

// get PID and print PID upon start // DONE
// message "running and waiting for something to print" + while (1) // DONE
// unused argv -> (void)argv // DONE
// get message length via strlen. // DONE
// send the int len to server, char by char // DONE

#include "minitalk.h"

char	g_msg[10];

// void	print_char()

// Handles SIGUSR1 and 2. 
void	handle_sigusrs(int signum)
{
	static int	bites;
	static int	i;
	static int	j;

	while (i < 8)
	{
		// print signum
		if (signum == SIGUSR2)
		{
			bites = bites | (1 << i);
			write(1, "1", 1);
			write(1, "test2\n", 6);
		}
		else
		{
			write(1, "0", 1);
			write(1, "test3\n", 6);
		}
		i++;
		if (i == 8)
		{
			write(1, "\n", 1);
			g_msg[j] = bites;
				if (bites == '\0')
				{
					// print and send SIGUSR1 to client as confirmation
					return;
				}
			bites = 0;
			i = 0;
			j++;
			write(1, "test2\n", 6);
		}
	}
}

// Prints out it's PID and waits for msg. Then prints it char by char now.
// After receiving the entire message it will send SIGUSR1 back as confirmation
// I will do it char by char now and switch to full message later. UNI should work.
int	main(int argc, char **argv)
{	
	(void)argv;
//	int	*len;
	
	// struct sigaction 	sa;

	// sa.sa_handler = handle_sigint;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_SIGINFO;
	ft_printf("AHOJ\n");
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
//	len = malloc(sizeof(int) *13);
	while (1)
		pause();
	return (0);
}
