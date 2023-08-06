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
	while (i < len)
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
		i++;
	}
	return (ascii);
}

void	receive_signal(int signal)
{
	char	binary[9];
	int	ascii;

	if (signal == 30)
		binary[g++] = '0';
	else if (signal == 31)
		binary[g++] = '1';
	if (g == 8)
	{
		binary[g] = '\0';
		ascii = reconvert_to_int(binary);
		printf("%c\n", ascii);
		g = 0;
	}
}

int	main()
{
	printf("%d\n", getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1);
	return (0);
}
