#include "philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!check_finish(philo))
			return (philo);
		write_status(philo, "think 💭");
		ft_eat(philo);
		ft_sleep(philo);
		if (check_end_conditions(philo))
			return (philo);
	}
}

int	check_finish(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&philo->data->finish_mutex);
	finish = philo->data->finish;
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return (finish);
}

int	check_end_conditions(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish_mutex);
	if (ft_win(philo->data) && philo->data->finish)
	{
		printf(GREEN"Philosophers eat %d out of %d\n"RESET,
			philo->number_meals, philo->number_meals);
		philo->data->finish = 0;
	}
	else if ((philo->last_meals != 0 && ft_lose(philo->data))
		|| !philo->data->finish)
	{
		if (philo->data->finish)
			printf(RED"n°(%d) is dead\n"RESET, philo->ph_id);
		philo->data->finish = 0;
	}
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return (!philo->data->finish);
}
