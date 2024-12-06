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

void	send_end()
{
	
}

void	char_to_binary(pid_t pid, char *str)
{
	int	bites;
	int	i;
	
	i = 0;
	ft_printf("%s\n", str);
	ft_printf("pid: %d\n", pid);
	while (str[i] != '\0')
	{
		bites = 7;
		while (bites > 0)
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
		}
		i++;
		write(1, "\n", 1);
	}
	send_end();
}	

int	main(int argc, char **argv)
{
	char *str;

	if (argc != 3)
		return (1);	
	ft_printf("Running....\n");
	str = argv[2];
	char_to_binary(ft_atoi(argv[1]), str);

	// while (1)
	// 	pause();
	// // wait for a 'OK' response after sending the terminating char.
	return (0);
}
