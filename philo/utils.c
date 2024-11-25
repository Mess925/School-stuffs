#include "philo.h"

void write_error_msg(const char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			write_error_msg("It only allows positive integers.");
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = (j * 10 + nptr[i]) - '0';
		i++;
	}
	if (j > 2147483647)
		write_error_msg("It is beyond the int limit.");
	return (j);
}