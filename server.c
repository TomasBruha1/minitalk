/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:26 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/24 15:41:50 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 💁👌🎍😍😊💙💜🖤
// valgrind --leak-check=full ./server

// DO NOW NOW: alloc_mgmt for double memory. Double free or corruption somewhere??

// DO NOW: below -> -> ->
// realocate global on server to double and memcpy to another variable and back.
// What about leaks? Free upon printing.
// Set up separate print function in handler.
// Set up handler that will free after SIGINT?
// How do I need to rename my static variables?

// ERRORS
// Client will sometimes print "OK", but will not shutdown.
// Server stops printing after roughly 10th (now even less) message.

#include "minitalk.h"

// If empty it allocates s_msg, if data_size is bigger it doubles the memory.
static char	*alloc_mgmt(int data_size, char *s_msg)
{
	int			start_buffer;
	static int	buffer;
	char 		*new_buffer;
	
	start_buffer = 4;
	ft_printf("data_size: %d\n\n", data_size);
	if (s_msg == NULL)
	{
		write(1, "s_msg was NULL\n", 15);
		s_msg = ft_calloc(1, start_buffer);
		buffer = start_buffer;
		return (s_msg);
	}
	else if (data_size >= buffer) // maybe buffer to start_buffer
	{
		write(1, "double alloc activated\n", 23);
		new_buffer = ft_calloc(1, buffer * 2);
		ft_memcpy(new_buffer, s_msg, buffer);
		buffer = buffer * 2;
		free(s_msg);
		return (new_buffer);
	}	
	return (s_msg);
}

// Handles SIGUSR1 and SIGUSR2 and get's client's PID via si_pid.
void	handle_sigusrs(int signum, siginfo_t *info, void *context_t)
{
	static char	*s_msg;
	static int	bites;
	static int	i;
	static int	j;
	pid_t		client_pid;

	(void)context_t;
	client_pid = 0; // put it directly into kill ft
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (signum == 12)
		bites = bites | (128 >> i);
	i++;
	if (i == 8)
	{
		s_msg = alloc_mgmt(j, s_msg);
		s_msg[j] = bites;
	//	kill(client_pid, SIGUSR1);
		write(1, "nullbyte check next\n", 20);
		if (bites == '\0') // set up separate function to save lines.
		{
			ft_printf("%s\n", s_msg); // Consider using write for g_msg.
			free(s_msg);
			s_msg = NULL;
			bites = 0;
			i = 0;
			j = 0;
			kill(client_pid, SIGUSR2);
			return ;
		}
		bites = 0;
		i = 0;
		j++;
	}
}

// Prints out it's PID and waits for msg. Then prints it char by char now.
// After receiving the entire message it will send SIGUSR1 back as confirmation
// I will do it char by char now and switch to full message later. UNI should work.
int	main(int argc, char **argv)
{
	struct sigaction 	sa;

	sa.sa_sigaction = handle_sigusrs;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	(void)argv;
	if (argc != 1)
	{
		ft_printf("No arguments allowed\n");
		return (EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID is %d.\n", getpid());
//	ft_printf("Waiting for message to print.\n\n");
//	ft_printf("Run ./client with server PID and message to send as args.\n");
	while (1)
		pause();
	return (0);
}

// ----------------------------------------------------------------------------

// After printing final msg, reset msg with bzero so it can receive new one. // DONE
// When '\0' is received, send SIGUSR2 to print confirmation at client. // DONE
// When char is assembled, send SIGUSR1 to send another char. // DONE
// Set up flag for sending another char and usleep for lower. // DONE
// Change signal to sigaction and get clients PID. // DONE
// Client's PID -> sigaction siginfo_t si_pid // DONE
// Emojis are working now. // DONE
// NOW: print stuff char by char on server side, check if condition. // DONE
// It receives multiple messages from different terminals. // DONE
// static for 8 bits, when 8 assemble char and add it to str[i] // DONE
// get PID and print PID upon start // DONE
// message "running and waiting for something to print" + while (1) // DONE
// unused argv -> (void)argv // DONE
// get message length via strlen. // DONE
// send the int len to server, char by char // DONE
