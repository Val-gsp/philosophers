#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	write_status(philo, CYAN"Sleep 🛏️"RESET);
	usleep(philo->data->time_to_sleep * 1e3);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	pthread_mutex_lock(philo->second_fork);
	write_status(philo, GREEN"Eat   🍽️"RESET);
	philo->last_meals = get_timestamp();
	usleep(philo->data->time_to_eat * 1e3);
	philo->number_meals++;
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	write_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (philo->data->finish)
		printf("time : %ld - The philosopher n%d : %s - number eat %d\n",
			philo->last_meals, philo->ph_id, status, philo->number_meals);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->finish)
			write_status(philo, "think 💭");
		ft_eat(philo);
		ft_sleep(philo);
		if (ft_win(philo->data) && philo->data->finish)
		{
			ft_printf(GREEN"Philosophers eat %d fout of %d\n"RESET,
				philo->number_meals, philo->number_meals);
			philo->data->finish = 0;
			return (philo);
		}
		if ((philo->last_meals != 0 && ft_lose(philo->data))
			|| !philo->data->finish)
		{
			if (philo->data->finish)
				ft_printf(RED"n°(%d) is dead\n"RESET, philo->ph_id);
			philo->data->finish = 0;
			return (philo);
		}
	}
}
