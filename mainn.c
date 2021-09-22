#include <stdio.h>
#include <stdlib.h>

//gcc -Wall -Wextra -Werror mainn.c

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
static void	binary_writer(int n, char *ptr)
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
	//ft_calloc
	ptr = calloc(ft_count_digits_base(n, 2), sizeof(char));
	binary_writer(n, ptr);

	return (ptr);
}

int main(void)
{
	printf("%s\n", int_tobinary(5));
}
