#include "minitalk.h"

void handler(int sig)
{
	printf("Señal es: %i", sig);
}

int main(void)
{
	char *line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);

	signal(SIGIO, &handler);
	ft_server();
}

/* kill -SIGIO 9469
ps u */
