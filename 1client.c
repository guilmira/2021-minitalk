/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:38 by guilmira          #+#    #+#             */
/*   Updated: 2021/11/16 13:45:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** PURPOSE : Signal sender using bitwise operations.
 * EIGHTH_BIT = 128, in binary is equivalent to 		10000000.
 * Example: Let us take for example the letter h 		(01101000).
 * If the operator '&' is used :  'letter h' & 128		(-0- ... 0000000)
 * The key one is the leftmost bit, i.e. '0'. Signal '0' will be sent.
 * Afterwards, 'letter = letter<<1' will transform 'h	(01101000)'
 * 												into	(11010000).
 * When 'letter & 128' is evaluated --> will result -->	(10000000).
 * This in turn´ll send the signal '1' */
static void	send_binary_signal(char letter, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (letter & EIGHTH_BIT)
			kill(pid, ONE);
		else
			kill(pid, ZERO);
		letter = letter << 1;
		usleep(50);
	}
}

/** PURPOSE : Simple parser function
 * 1. Control number of arguments.
 * 2. Control PID.
 * 3. Control string. */
static void	mt_parser(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number.\
		Introduce the PID follwed by the message.\
		./client [PID] [string] \n", 2);
		ft_shutdown();
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd("PID must be a number. \
			./client [PID] [string] \n", 2);
			ft_shutdown();
		}
	}
	if (!argv[2][0])
		ft_putstr_fd("Sending empty string.\n", 2);
}

/** PURPOSE : Client program.
 * 1. Argument 1 is Process-ID.
 * 2. Argument 2 is the string.
 * Remember using process status (ps u) to check ID */
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*string;

	mt_parser(argc, argv);
	string = ft_strdup(argv[2]);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (string[++i])
		send_binary_signal(string[i], pid);
	send_binary_signal('\n', pid);
	free(string);
}
