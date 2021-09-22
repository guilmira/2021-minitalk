/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:38 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/22 16:49:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** PURPOSE : Output error, close the program. */
void	shutdown(void)
{
	ft_printf("Error\n");
	//ft_putstr_fd("Error\n", 1);
	exit(1);
}

/** PURPOSE : converts string into integer equivalent.
 * 1. Skip spaces, tabs and similar.
 * 2. Check sign.
 * 3. Take the string digit and add it to global number (multiplied by 10); */
static int	ft_aatoi(const char *str)
{
	unsigned int	n;
	unsigned int	i;
	int				sign;

	sign = 1;
	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
	str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - '0') + n * 10;
		if (n > 2147483647 && sign == 1)
			return (-1);
		else if (n > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (((int) n * sign));
}

/** PURPOSE : counts digits of an int (iterative)
 * Base might be binary, decimal, hexadecimal... */
int	ft_count_digits_base(int n, int base)
{
	int	digits;

	digits = 1;
	n /= base;
	while (n)
	{
		digits++;
		n /= base;
	}
	return (digits);
}

/** PURPOSE : */
int	binary_writer(int n, char *ptr)
{
	static int	i;

	if (n / 2)
		binary_writer(n / 2, ptr);
	else
	{
		i = 0;
		if (n < 0)
		{
			ptr[0] = '-';
			i++;
		}
	}
	ptr[i++] = '0' + n % 2;
	ptr[i] = '\0';
}

/** PURPOSE : converts integer into binary string equivalent.
 * 1. Check sign.
 * 2.  */
char *int_tobinary(int n)
{
	char	*ptr;
	/* if (n == -2147483648)
		return (ft_strdup("-2147483648")); */
	ptr = ft_calloc(ft_count_digits_base(n, 2), sizeof(char));
	binary_writer(n, ptr);

	return (ptr);
}

int main(int argc, char *argv[])
{

	if (!argc)
		shutdown();

	kill(ft_aatoi(argv[1]), 2); //cambiara cunado unficique lib y pf
	int_tobinary((int)argv[2][0]);
}


/* char *line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	free(line); */
