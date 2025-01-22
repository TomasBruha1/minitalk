/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:57:40 by tbruha            #+#    #+#             */
/*   Updated: 2024/12/07 00:13:46 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t	g_ready_flag;

// Handler changes flag to 1 upon receiving SIGUSR1.
void	flag_handler(int signum)
{
	if (signum == 10)
		g_ready_flag = 1;
}

// Handler prints "message received" and exits once receives SIGUSR2.
void	msg_ok_handler(int signum)
{
	if (signum == 12)
	{
		write(1, "Message received!\n", 18);
		EXIT_SUCCESS;
	}
}

// It sends the last char so server knows the message is over and sends Ok back
void	send_end(pid_t server_pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		kill(server_pid, SIGUSR1);
		count--;
		usleep(200);
	}
}

// It converts the msg and send it via bits to server.
void	char_to_binary(pid_t pid, char *str)
{
	int	bites;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		bites = 7;
		while (bites >= 0)
		{
			if (((str[i] >> bites) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bites--;
			usleep(300);
		}
		g_ready_flag = 0;
		while (g_ready_flag == 1)
			usleep(50);
		i++;
	}
	send_end(pid);
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
	signal(SIGUSR1, flag_handler);
	signal(SIGUSR2, msg_ok_handler);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	char_to_binary(server_pid, str);
	pause();
	return (EXIT_SUCCESS);
}
