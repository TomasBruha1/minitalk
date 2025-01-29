/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:40 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/29 13:51:41 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t	g_ready_flag;

void	send_sig(int signum, pid_t pid)
{
	if (kill(pid, signum) == -1)
	{
		write(1, "Signal failed to send !\n", 23);
		exit(EXIT_FAILURE);
	}
}

// Handler changes flag if SIGUSR1 and prints OK if SIGUSR2.
void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		g_ready_flag = 1;
	else if (signum == SIGUSR2)
	{
		write(1, "OK!\n", 4);
		exit(EXIT_SUCCESS);
	}
}

// It sends each char as 8 bits using SIGUSR1 and SIGUSR2.
void	send_byte(pid_t server_pid, char c)
{
	int	bites;

	bites = 7;
	while (bites >= 0)
	{
		if (((c >> bites) & 1) == 0)
			send_sig(SIGUSR1, server_pid);
		else
			send_sig(SIGUSR1, server_pid);
		bites--;
		while (g_ready_flag == 0)
			pause();
		g_ready_flag = 0;
	}
	usleep(50);
}

// It accepts the str and sends it to ft to send it to server and then '\0'.
void	send_msg(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_byte(pid, str[i]);
		i++;
	}
	usleep(100);
	send_byte(pid, '\0');
}

// It sends msg as 0 and 1 to server. Then it waits for response from server.
int	main(int argc, char **argv)
{
	char	*str;
	int		server_pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments.\n");
		ft_printf("Write server's PID and message to send next time. BYE\n");
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	send_msg(server_pid, str);
	pause();
	return (EXIT_SUCCESS);
}
