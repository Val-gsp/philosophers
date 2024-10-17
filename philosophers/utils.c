#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

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
	pthread_mutex_destroy(&(data->m_eat));
	pthread_mutex_destroy(&(data->finish_mutex));
	free(data->philo);
	free(data->forks);
}
