/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:47:16 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/13 18:49:56 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	stringlenght;

	stringlenght = 0;
	while (s[stringlenght] != '\0')
	{
		stringlenght++;
	}
	return (stringlenght);
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
	{
		return (1);
	}
	return (0);
}

void	ft_die(t_philo *philo, int i)
{
	i = -1;
	while (++i < philo->args->nbr_of_philo)
		philo[i].alive = false;
}

int	no_meal_today(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo[i].alive)
	{
		printf(RED"Check your args : Sorry, no meals to eat 🍽\n");
		ft_die(philo, i);
		pthread_mutex_unlock(&philo->args->mutex);
		break ;
	}
	return (0);
}
