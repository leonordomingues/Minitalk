#include "minitalk.h"

int	reconvert_to_int(int *binary)
{
	int	power;
	int	power2;
	int	nb;
	int	n;

	power = 0;
	power2 = 0;
	nb = 0;
	n = 2;
	while (binary[power] != '\0' && power < 8)
	{
		if (SIGUSR2 && power == 0)
			nb = 1;
		else if (SIGUSR2)
		{
			power2 = power;
			while (power2 > 1)
			{
				n = n * 2;
				power2--;
			}
			nb += n;
		}
		power++;
	}
	return (nb);
}
int	main()
{
	printf("%d\n", getpid());
	sleep(2);
	signal(SIGUSR1);
	signal(SIGUSR2);
	return (0);
}
