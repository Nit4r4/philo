/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:36:15 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/15 14:51:18 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print(char *str, t_philo *philo, char *str2)
{
	pthread_mutex_lock(&(philo->args->mutex));
	if (philo->alive == true)
	{
		printf("%sTimestamp(ms): %ld |philo n°%d %s", str, timestamp(),
			philo->name, str2);
	}
	pthread_mutex_unlock(&(philo->args->mutex));
}

t_philo	*ft_present( t_args *args)
{
	long int	p;
	t_philo		*philos;

	philos = malloc(sizeof(t_philo) * (args->nbr_of_philo));
	if (!philos)
		return (0);
	p = 0;
	philos->nbr_of_fork = args->nbr_of_philo;
	args->start_time = 0;
	args->end_time = 0;
	args->all_meal_eaten = 0;
	philos->last_meal = 0;
	while (p < args->nbr_of_philo)
	{
		philos[p].name = p + 1;
		philos[p].meals_eaten = 0;
		philos[p].alive = true;
		philos[p].args = args;
		philos[p].args->end_time = 0;
		p++;
	}
	return (philos);
}

int	find_my_forks(t_philo *philos, t_args *args)
{
	long int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		if (pthread_mutex_init(&philos[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	if (args->nbr_of_philo == 1)
	{
		ft_usleep(args->time_to_die);
		ft_dead(philos, args);
	}
	else
		philo_thread(philos, args);
	return (0);
}
