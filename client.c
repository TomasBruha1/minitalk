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
	write(1, "\n", 1);
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
}	

int	main(int argc, char **argv)
{
	char	*str;
	int		len;	

	if (argc != 3)
		return (EXIT_FAILURE);
//	signal(SIGUSR1, handle_ok);
	str = argv[2];
	len = ft_strlen(str);
	ft_printf("%d\n", len);
	write(1, "\n", 1);
	char_to_binary(ft_atoi(argv[1]), ft_itoa(len));
	write(1, "\n", 1);
	char_to_binary(ft_atoi(argv[1]), str);
	write(1, "\n", 1);
	send_end(ft_atoi(argv[1]));
	ft_printf("Waiting for response....\n");
	pause(); // waiting for response from server
	return (EXIT_SUCCESS);
}
