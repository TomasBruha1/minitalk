/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:26 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/28 18:09:53 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// If empty it allocates s_msg, if data_size is bigger it doubles the memory.
char	*alloc_mgmt(int data_size, char *s_msg)
{
	int			start_buffer;
	static int	buffer;
	char		*new_buffer;

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

// Once the '\0' byte is received it will print the whole msg and prepare
// the variables for next msg to be received.
void	msg_end(char **msg, int pid, int *bites)
{
	ft_printf("%s\n", *msg);
	free(*msg);
	*msg = NULL;
	bites = 0;
	kill(pid, SIGUSR2);
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
		bites |= ((0x80) >> i);
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		s_msg = alloc_mgmt(j, s_msg);
		s_msg[j] = bites;
		if (bites == '\0')
		{
			msg_end(&s_msg, info->si_pid, &bites);
			i = 0;
			j = 0;
			return ;
		}
		bites = 0;
		i = 0;
		j++;
	}
}

// Prints out it's PID, setups sigaction struct and wait for msg.
int	main(int argc, char **argv)
{
	struct sigaction	sa;

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

// 💁👌🎍😍😊💙💜🖤
// valgrind --leak-check=full ./server

// DO NOW: below -> -> ->
// minitalk.h
// copy it to vogosphere
