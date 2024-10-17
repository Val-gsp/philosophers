#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philo)
		pthread_join(data->philo[i].ph_thread, NULL);
	i = -1;
	while (++i < data->number_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write_mutex));
	free(data->philo);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	if (ft_atoi(argv[1]) == 1)
		return (ft_printf("Le philosophe (1) pense\n"
				"Le philosophe (1) est dead\n"));
	if (init_info(&data, argv, argc))
		return (ft_printf("error init info"));
	if (init_philo(&data))
		return (ft_printf("error init philo"));
	ft_free(&data);
}
