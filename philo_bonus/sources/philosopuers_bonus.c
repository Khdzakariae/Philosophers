
#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		status;

	if (check_arguments(argc, argv, &data) != 0)
		return (1);
	philo = initialize_philosophers(&data);
	if (philo == NULL)
		return (1);
	start_simulation(&data, philo);
	while (1)
	{
		status = waitpid(-1, &status, 0);
		if (status == -1)
		{
			free(philo);
			exit(22);
		}
		else
		{
			arrete(philo);
			exit(1);
		}
	}
}
