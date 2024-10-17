#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	if (ft_atoi(argv[1]) == 1)
		return (printf("The philosophe (1) think\n"
				"The philosophe (1) dead\n"));
	if (init_info(&data, argv, argc))
		return (printf("error init info"));
	if (init_philo(&data))
		return (printf("error init philo"));
	ft_free(&data);
}
