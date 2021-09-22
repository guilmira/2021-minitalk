/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:35 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/22 12:41:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
