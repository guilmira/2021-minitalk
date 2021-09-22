#include "minitalk.h"

void handler(int sig)
{
	ft_printf("Señal es: %i", sig);
}

void signal_controller(int signal)
{
	ft_printf("Ahora contro la señal: %i", signal);
	//explotar ordena
}

int main(void)
{
	signal(SIGIO, &handler);
	ft_server();
}

/* kill -SIGIO 9469
ps u */
