/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:54:26 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 12:53:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
//# define ONE 'SIGUSR1'
//# define ZERO 'SIGUSR2'

void	ft_server(void);

#endif
