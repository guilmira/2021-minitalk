/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3ft_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:55:27 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/12 16:25:27 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** PURPOSE : outputs lenght of the string.
 * 1. Advances string while increasing counter. */
static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/** PURPOSE : Prints char to file/ std output(fd = 1). */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

/** PURPOSE : Prints string to file/ std output(fd = 1). */
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/** PURPOSE : Prints nbr to file/ std output(fd = 1). */
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		x = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		x = n;
	if (x / 10 == 0)
		ft_putchar_fd('0' + x, fd);
	else
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd('0' + (x % 10), fd);
	}
}
