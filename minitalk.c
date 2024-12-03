/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:42:35 by tbruha            #+#    #+#             */
/*   Updated: 2024/12/03 20:46:16 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// What is next: Create minitalk's Makefile.

// During that I will set up that for each writen letter I will convert it to ascii
// and to 00110010011 and send it as SIGUSR1 and SIGUSR2 to the server side from client.
// How to actually send it from client to server? The "how" part. kill(), but how?
// Implement my ft_printf here.
// swap printfs for ft_printfs.
// For multiple clients, check their PID and block others until message is not over.
// CodeVault -> UNIX processes in C Youtube.

// ----------------------------------------------------------------------------

// Send anything from client to server. // DONE
// Run each command in chatGPT and has it explain its use and its return again. // DONE
// I will need to block other signals while... doing what? What to block? // DONE
// create minitalk.h // DONE
// Read up on minitalk on gitbook web // DONE
// Create 2 files for each of 5 functions for signals to keep it clean. No need // DONE
// Print PID after launching 'server'. // DONE
// How to get PID for 'server'? // DONE
// Why pid_t not pid_ting? <header sys/types.h> // DONE
// How to run program that doesn't quit? Did I use it yet? sleep, while(1) // DONE

// ----------------------------------------------------------------------------

// Subject info:
// executable files as client and server
// libft YES
// one global variable per program
// write, ft_printf, signal, sigemptyset, sigaddset, sigaction
// kill, getpid, malloc, free, pause, sleep, usleep, exit

// My other info:
// message "Hello" will be turned to ASCII. H -> 72 -> 01001000, e -> 101 -> 01100101 etc.
// last one for NULL byte??

// MANDATORY PART:
// server first, it will print its PID
// client takes two parameters: client PID and string to send
// server will print the message, 1 sec for 100 chars is too much
// ONLY UNIS signals -> SIGUSR1 and SIGUSR2

// BONUS:
// server acknowledges the message by sending back a signal
// Unicode characters support! -> emojis

