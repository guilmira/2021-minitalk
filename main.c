#include "minitalk.h"

void handler(int sig)
{
	printf("Señael es: %i", sig);
}

int main(void)
{
	char *string = "hola mundo";

	signal(SIGIO, &handler);
	ft_server();
	printf("%s", string);
}

/* kill -SIGIO 9469
ps u */
