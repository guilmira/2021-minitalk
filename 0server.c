/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:35 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 12:17:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** PURPOSE : Output error, close the program. */
void	handler_1(int sig)
{
	ft_printf("Señal %i es ahora %i\n", sig, 1);
}

void	handler_0(int sig)
{
	ft_printf("Señal %i es ahora %i\n", sig, 0);
}

/** PURPOSE : Runs the server.
 * 1. Obtain P-ID and display.
 * 2. Awaits. Loop runs every 2 seconds */
void ft_server(void)
{
	int	signal;

	signal = getpid();
	ft_printf("PID: %i\n", signal);
	while (1)
	{
		ft_printf("durmiendo\n");
		sleep(2);
	}
}

/** PURPOSE : Server program.
 * 1. Prepares handlers for SIGUSR1 (nº30) and SIGUSR2 (nº31).
 * 2. Executes server process. It will show P-ID and await.
 * Remember using process status (ps u) to check ID */
int main(void)
{
	signal(SIGUSR1, &handler_1); //30
	signal(SIGUSR2, &handler_0);
	ft_server();
}
