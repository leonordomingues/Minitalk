#include "minitalk.h"

int	g = 0;

int	reconvert_to_int(char *binary)
{
	int	len;
	int	i;
	int	ascii;
	int	n;
	int	j;

	len = 8;
	ascii = 0;
	i = 0;
	while (binary[i] != '\0' && i < len)
	{
		if (binary[i] == '1')
		{
			n = 1;
			j = len - 1;
			while (j > i)
			{
				n *= 2;
				j--;
			}
			ascii += n;
		}
	}
	printf("%d\n", ascii);
	return (ascii);
}

void	receive_signal(int signal)
{
	char	binary[9];
	int	ascii;
//	printf("%d\n", signal);
	if (signal == 30)
	{
		binary[g++] = '0';
	//	printf("0\n");
	}
	else if (signal == 31)
	{
		binary[g++] = '1';
	//	printf("1\n");
	}
	if (g == 8)
	{
		binary[g] = '\0';
		ascii = reconvert_to_int(binary);
	//	printf("%c\n", ascii);
		g = 0;
	}
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
