/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:26 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/28 14:28:48 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 💁👌🎍😍😊💙💜🖤
// valgrind --leak-check=full ./server

// DO NOW: below -> -> ->
// Set up separate print function in handler.

#include "minitalk.h"

// If empty it allocates s_msg, if data_size is bigger it doubles the memory.
static char	*alloc_mgmt(int data_size, char *s_msg)
{
	int			start_buffer;
	static int	buffer;
	char 		*new_buffer;
	
	start_buffer = 1024;
	if (s_msg == NULL)
	{
		s_msg = ft_calloc(1, start_buffer);
		buffer = start_buffer;
		return (s_msg);
	}
	else if (data_size >= buffer)
	{
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

	(void)context_t;
	if (signum == SIGUSR2)
		bites = bites | ((0x80) >> i); // save it directly to s_msg[j]
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		s_msg = alloc_mgmt(j, s_msg);
		s_msg[j] = bites; // 
		if (bites == '\0') // separate function
		{
			ft_printf("%s\n", s_msg);
			free(s_msg);
			s_msg = NULL;
			bites = 0;
			i = 0;
			j = 0;
			kill(info->si_pid, SIGUSR2);
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
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

// Setup check for wrong pid when sending from client. -1 check how? // DONE
// free upon SIGINT(wrapper). Not needed // DONE
// How to check with valgrind? // DONE
// handler on client side compress to just one instead of two // DONE
// What about leaks? Free upon printing. // DONE
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
