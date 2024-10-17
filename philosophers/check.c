#include "philo.h"

long long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1e3 + current_time.tv_usec / 1e3);
}

int	ft_win(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (data->number_of_eat == 0)
			return (0);
		else if (data->philo[i].number_meals < data->number_of_eat)
			return (0);
		i++;
	}
	return (1);
}

int	ft_lose(t_data *data)
{
	int		i;
	long	time;

	i = 0;
	time = get_timestamp();
	while (i < data->number_philo)
	{
		if (time >= (data->philo[i].last_meals + (long)data->time_to_die))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
