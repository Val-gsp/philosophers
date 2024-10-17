#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define RESET		"\033[0m" //Reset to default color
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				ph_id;
	int				number_meals;
	long int		start_time;
	long int		last_meals;
	t_data			*data;
	pthread_t		ph_thread;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}		t_philo;

typedef struct s_data
{
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				finish;
	long int		start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	m_eat;
}		t_data;

void			ft_free(t_data *data);
int				init_info(t_data *data, char **argv, int argc);
int				init_philo(t_data *data);
void			*start_routine(void *arg);
void			ft_sleep(t_philo *philo);
void			ft_eat(t_philo *philo);
long long int	get_timestamp(void);
long			get_elapsed_time(long start_time);
void			write_status(t_philo *philo, char *status);
int				ft_win(t_data *data);
int				ft_lose(t_data *data);
int				ft_atoi(const char *str);

#endif
