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

void	send_end(pid_t server_pid)
{
	int	count;

	count = 8;
	while (count > 0)
	{
		kill(server_pid, SIGUSR1);
		write(1, "0", 1);
		count--;
	}
}

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
				ft_printf("0");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf("1");
				kill(pid, SIGUSR2);
			}
			bites--;
			usleep(100);
		}
		i++;
		write(1, "\n", 1);
	}
	send_end(pid);
}	

int	main(int argc, char **argv)
{
	char *str;

	if (argc != 3)
		return (1);	
	ft_printf("Running....\n");
	str = argv[2];
	char_to_binary(ft_atoi(argv[1]), str);

	pause(); // waiting for response from server
	return (0);
}
