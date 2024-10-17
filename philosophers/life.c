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
		printf("time : %ld - The philosopher n%d : %s\n",
			philo->last_meals, philo->ph_id, status);
	pthread_mutex_unlock(&philo->data->write_mutex);
}
