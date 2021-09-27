/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:35 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/27 14:24:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** Global variable is declared to efficiently
 * use structure on function handler. This allows
 * for a single signal handler instead of two. */
t_message	*g_binary;

/** PURPOSE : Signal handler.
 * 1. Increases bit counter.
 * 2. Checks whether the counter is divisible by 8. If so, reinit bit.
 * 2. If signal 30 (SIGUSR1) is sent, increase one bit in letter. If not
 * then don´t do anthing. This meanss that when SIGUSR2 is recieved, the
 * only thing that the function does is increae the bit counter as well as
 * move by one position to the left the bit modifier.
 * 3. Move the bit modifier one position to the right. */
void	ft_handler(int sig)
{
	g_binary->bit_counter++;
	if (sig == ONE)
		g_binary->letter = g_binary->letter | g_binary->bit_modifier;
	g_binary->bit_modifier = g_binary->bit_modifier >> 1;
	if (!(g_binary->bit_counter % 8))
	{
		g_binary->bit_modifier = EIGHTH_BIT;
		ft_printf("%c", g_binary->letter);
		g_binary->letter = 0;
	}
}

/** PURPOSE : Runs the server.
 * 1. Obtain P-ID and display.
 * 2. Awaits. Loop runs indefinetly */
static void	ft_server(void)
{
	int	signal;

	signal = getpid();
	ft_printf("PID: %i\n", signal);
	while (1)
		;
}

/** PURPOSE : Init struct. */
void	struct_init(t_message *g_binary)
{
	g_binary->letter = 0;
	g_binary->bit_counter = 0;
	g_binary->bit_modifier = EIGHTH_BIT;
}

/** PURPOSE : Server program.
 * 1. Prepares handlers for SIGUSR1 (nº30) and SIGUSR2 (nº31).
 * 2. Executes server process. It will show P-ID and await.
 * Remember using process status (ps u) to check ID */
int	main(void)
{
	g_binary = ft_calloc(1, sizeof(*g_binary));
	if (!g_binary)
		ft_shutdown();
	struct_init(g_binary);
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	ft_server();
	free(g_binary);
}
