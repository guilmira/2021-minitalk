/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:47:38 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/23 13:55:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** PURPOSE : Output error, close the program. */
void	shutdown(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

/** PURPOSE : converts integer into its binary string equivalent.
 * 						--ALLOCATES MEMORY--
 * 1. Allocate enough memory to contain enough digits. Note how it allocates
 * extra space in order to be able to finish the string with the '\0'
 * and also in case the number is negative and needs a '-' char.
 * 2. Write binary digits as a string using recurssive funct-writer. */
char	*char_tobin(char z)
{
	int	ascii;

	ascii = (int) z;
	return (ft_tobinary(ascii));
}

void	send_binary_signal(char *binary, int pid)
{
	int	i;

	i = -1;
	while (binary[++i])
	{
		if (binary[i] == '1')
			kill(pid, SIGUSR1);
		else

			kill(pid, SIGUSR2);
		sleep(2);
	}

}

#bitwie operations in c

/** PURPOSE : process string to binary. Returns allocated binary string number.
 * 						--ALLOCATES MEMORY-- */
char	*string_mgmt(char *str)
{
	char	*string;
	char	*binary;

	string = ft_strdup(str);
	binary = char_tobin(string[0]);
	printf("%s\n",binary);
	free(string);
	return (binary);
}

/** PURPOSE : Client program.
 * 1. Argument 1 is Process-ID.
 * 2. Argument 2 is the string.
 * Remember using process status (ps u) to check ID */
int main(int argc, char *argv[])
{
	char	*binary;

	if (argc != 3)
		shutdown();
	binary = string_mgmt(argv[2]);
	send_binary_signal(binary, ft_atoi(argv[1]));
	free(binary);
}

/* char *line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	free(line); */
