/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:50:49 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/13 18:19:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_philo		*philos;

	check_errors(argc, argv);
	argv_to_int(argc, argv, &args);
	philos = ft_present(&args);
	if (philos->args->nbr_of_meal == 0)
		no_meal_today(philos);
	find_my_forks(philos, &args);
	free_ture(philos);
	exit_thread(philos, &args);
	return (0);
}
