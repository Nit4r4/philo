/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday_ms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:40:44 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/15 14:51:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	get_current_time_ms(void)
{
	struct timeval	time;
	long int		current_time;
	long int		current_time_sec;
	long int		current_time_usec;

	gettimeofday(&time, NULL);
	current_time_sec = time.tv_sec * 1000;
	current_time_usec = time.tv_usec / 1000;
	current_time = current_time_sec + current_time_usec;
	return (current_time);
}

void	ft_start(t_args *args)
{
	args->start_time = get_current_time_ms();
}

long int	ft_end(t_args *args)
{
	args->end_time = get_current_time_ms() - args->start_time;
	return (args->end_time);
}

long int	timestamp(void)
{
	static long long	times;

	if (times == 0)
		times = get_current_time_ms();
	return (get_current_time_ms() - times);
}

void	ft_usleep(int time)
{
	int	start;

	start = timestamp();
	while (1)
	{
		if (start + time <= timestamp())
			break ;
		usleep(100);
	}
}
