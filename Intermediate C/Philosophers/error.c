#include "philo.h"

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, "Error: ", 7);
	write(1, str, len);
	write(1, "\n", 1);
	return (1);
}

int	which_error(int err)
{
	if (err == 1)
		return (write_error("At least one wrong argumnrt"));
	if (err == 2)
		return (write_error("Can't initialize mutex"));
	return (1);
}
