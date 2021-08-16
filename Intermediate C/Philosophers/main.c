#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount if arguments"));
	ret = init_all(&rules, argv);
	if (ret)
		return (which_error(ret));
	if (launch_philos(&rules))
		return (write_error("There was an error creating the threads"));
	return (0);
}
