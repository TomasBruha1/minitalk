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

// sig handler for receiving SIGUSR1 -> "Message received!"
// void	handle_ok(int signum)

// It sends the last char so server knows the message is over and sends Ok back
void	send_end(pid_t server_pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		kill(server_pid, SIGUSR1);
		count--;
		write(1, "0",1);
		usleep(200);
	}
	write(1, "\n", 1);
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
			{
				write(1, "0", 1);
				kill(pid, SIGUSR1);
			}	
			else
			{	
				write(1, "1", 1);
				kill(pid, SIGUSR2);
			}
			bites--;
			usleep(200);
		}
		write(1, "\n", 1);
		i++;
	}
}

// It sends msg as 0 and 1 to server. Then it waits for response from server.
int	main(int argc, char **argv)
{
	char	*str;
	int		len;	

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments.\n");
		ft_printf("Write server's PID and message to send next time. BYE\n");
		return (EXIT_FAILURE);
	}
//	signal(SIGUSR1, handle_ok);
	str = argv[2];
	len = ft_strlen(str);
//	char_to_binary(ft_atoi(argv[1]), ft_itoa(len)); // For sending len
	char_to_binary(ft_atoi(argv[1]), str); // sending msg
	send_end(ft_atoi(argv[1])); // send '\0'
	ft_printf("Waiting for response....\n");
	pause(); // waiting for response from server
	return (EXIT_SUCCESS);
}
