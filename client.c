#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * m);
}

int	*convert_to_binary(int ascii)
{
	int	*binary;
	int	b;

	b = 7;
	binary = malloc(sizeof(int) * 8);
	while (ascii >= 0)
	{
		binary[b] = b % 2;
		b /= 2;
		b--;
	}
	while (b >= 0)
		binary[b--] = 0;
	return (binary);
}

int	check_if_character(int ascii)
{
	if (ascii >= 32 && ascii <= 126)
		return (ascii);
	return (0);
}

void	sendsignal(int *binary, int pid)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if (binary[b] == 0)
			kill(pid, SIGUSR1);
		else if (binary[b] == 1)
			kill(pid, SIGUSR2);
		b++;
	}
	free(binary);
}
int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	character;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i] != '\0')
		{
			character = check_if_character(av[2][i]);
			sendsignal(convert_to_binary(character), pid);
			i++;
		}

	}
}
