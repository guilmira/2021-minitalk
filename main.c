#include "minitalk.h"

void handler(int sig)
{
	printf("Señal es: %i", sig);
}

int main(void)
{
	signal(SIGIO, &handler);
	ft_server();
}

/* kill -SIGIO 9469
ps u */
