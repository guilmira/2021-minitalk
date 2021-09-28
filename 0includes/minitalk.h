/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:54:26 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/28 09:36:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "libft.h"
# define ONE SIGUSR1
# define ZERO SIGUSR2
# define EIGHTH_BIT 128

typedef struct s_recieved
{
	char	letter;
	int		bit_counter;
	int		bit_modifier;
}			t_message;

#endif
