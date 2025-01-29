/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:18:04 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/29 14:10:20 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// HEADERS

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

// STRUCTS

// MINITALK - SERVER

void	handle_sigusrs(int signum, siginfo_t *info, void *context_t);
void	msg_end(char **msg, int pid, int *bites);
char	*alloc_mgmt(int data_size, char *s_msg);

// MINITALK - CLIENT

void	send_msg(pid_t pid, char *str);
void	send_byte(pid_t server_pid, char c);
void	send_sig(int signum, pid_t pid);
void	sigusr_handler(int signum);

// HELPER >> DELETE LATER

#endif
