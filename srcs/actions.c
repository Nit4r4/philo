/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:00:35 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/13 18:49:37 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	takes_forks(t_philo *philo)
{
	int			i;
	long int	time;

	time = philo->args->end_time;
	i = philo->name - 1;
	pthread_mutex_lock(&philo->fork);
	print(YELLOW, philo, M_FORK);
	if (philo->args->nbr_of_philo - 1 == philo->name - 1)
		pthread_mutex_lock(&philo->args->philos[0].fork);
	else
		pthread_mutex_lock(&philo->args->philos[i + 1].fork);
	print(YELLOW, philo, M_FORK);
}

void	ft_eat(t_philo *philo)
{
	int	i;

	i = philo->name -1;
	print(GREEN, philo, M_EAT);
	ft_usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	if (philo->args->nbr_of_philo - 1 == philo->name - 1)
		pthread_mutex_unlock(&philo->args->philos[0].fork);
	else
		pthread_mutex_unlock(&philo->args->philos[i + 1].fork);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->args->nbr_of_meal)
		philo->args->all_meal_eaten++;
	philo->last_meal = timestamp();
}

void	ft_think(t_philo *philo)
{
	print(PURP, philo, M_THINK);
}

void	ft_sleep(t_philo *philo)
{
	print(BLUE, philo, M_SLEEP);
	ft_usleep(philo->args->time_to_sleep);
}

void	ft_dead(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (philo[i].alive)
	{
		if (args->all_meal_eaten == args->nbr_of_philo)
		{
			pthread_mutex_lock(&args->mutex);
			printf(WHITE"All %d meals has been eaten by all philos 🍝\n",
				philo->meals_eaten);
			ft_die(philo, i);
			break ;
		}
		usleep(1000);
		if (philo[i].last_meal + philo->args->time_to_die < timestamp())
			break ;
		i++;
		if (i >= philo->args->nbr_of_philo)
			i = 0;
	}
	print(RED, philo, M_DIE);
	ft_die(philo, i);
	usleep(1500);
	free_ture(philo);
	exit_thread(philo, args);
}
