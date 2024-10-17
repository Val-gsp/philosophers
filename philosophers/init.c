#include "philo.h"

int	init_info(t_data *data, char **argv, int argc)
{
	int	i;

	i = 0;
	data->number_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_eat = ft_atoi(argv[5]);
	else
		data->number_of_eat = 0;
	data->finish = 1;
	data->philo = malloc(sizeof(t_philo) * data->number_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_philo);
	if (!data->philo || !data->forks)
		return (1);
	while (data->number_philo > i)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_timestamp();
	while (++i < data->number_philo)
	{
		data->philo[i].ph_id = i;
		data->philo[i].number_meals = 0;
		data->philo[i].last_meals = get_timestamp() + data->time_to_die;
		data->philo[i].data = data;
		data->philo[i].first_fork = &data->forks[i];
		data->philo[i].second_fork = &data->forks[(i + 1) % data->number_philo];
	}
	i = -1;
	while (++i < data->number_philo)
	{
		if (pthread_create(&data->philo[i].ph_thread, NULL,
				start_routine, &data->philo[i]) != 0)
			return (1);
	}
	return (0);
}
