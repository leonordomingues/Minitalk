#include "minitalk.h"

int	reconvert_to_int(char *binary)
{
	int	power;
	int	temp;
	int	ascii;
	int	n;

	power = 0;
	temp = 0;
	ascii = 0;
	n = 2;
	while (binary[power] != '\0' && power < 8)
	{
		if (binary[power] == '1' && power == 0)
			ascii = 1;
		else if (binary[power] == '1')
		{
			temp = power;
			while (temp > 1)
			{
				n = n * 2;
				temp--;
			}
			ascii += n;
		}
		power++;
	}
	return (ascii);
}

void	receive_signal(int signal)
{
	char	binary[9];
	int	b;
	int	ascii;
//	printf("chega");
	b = 0;
	while (binary[b] && b < 8)
	{
		if (signal == 30)
			binary[b] = '0';
		else if (signal == 31)
			binary[b] = '1';
		b++;
	}
	binary[b] = '\0';
	ascii = reconvert_to_int(binary);
	printf("%c\n", ascii);
}

int	main()
{
	printf("%d\n", getpid());
	sleep(2);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1);
	return (0);
}
