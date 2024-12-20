/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:42:35 by tbruha            #+#    #+#             */
/*   Updated: 2024/12/06 22:22:23 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// What is next: 

// Implement my ft_printf here.
// swap printfs for ft_printfs.
// During that I will set up that for each writen letter I will convert it to ascii
// and to 00110010011 and send it as SIGUSR1 and SIGUSR2 to the server side from client.
// How to actually send it from client to server? The "how" part. kill(), but how?
// For multiple clients, check their PID and block others until message is not over.
// CodeVault -> UNIX processes in C Youtube.
// encrypt the message.
// send the message.
// Create a stop condition -> NULL byte?
// receive signals -> decrypt signals
// How to handle negative numbers in binary. example -16 
// 1. Find binary value of + character -> 00010000.
// 2. We flip the digits to the opposite of what it was -> 11101111
// 3. Add 1. 1 + 1 = 10, you leave 0 and carry a 1 -> 11110000
// ----------------------------------------------------------------------------

// Create minitalk's Makefile. // DONE
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
// last one for NULL byte?? That will tell server that it's over (that it's what?? over).

// MANDATORY PART:
// server first, it will print its PID
// client takes two parameters: client PID and string to send
// server will print the message, 1 sec for 100 chars is too much
// ONLY UNIS signals -> SIGUSR1 and SIGUSR2

// BONUS:
// server acknowledges the message by sending back a signal
// Unicode characters support! -> emojis

