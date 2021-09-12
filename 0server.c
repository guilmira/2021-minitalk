/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:35 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/12 16:30:55 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_server(void)
{
	int	signal;

	signal = getpid();
	ft_putstr_fd("PID: ", 1);
	printf("%i\n", signal);
	ft_putnbr_fd(signal, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		printf("durmiendo\n");
		sleep(2);
	}
}
