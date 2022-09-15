/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:07:09 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/15 14:51:15 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_exit(char *str)
{
	printf("%s\n", str);
	exit (EXIT_FAILURE);
}

void	check_errors(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		error_exit(ARG_NBR);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error_exit(ARG_C);
			j++;
		}
	}
}

void	argv_to_int(int argc, char **argv, t_args *args)
{
	args->nbr_of_philo = ft_atol(argv[1]);
	args->time_to_die = ft_atol(argv[2]);
	args->time_to_eat = ft_atol(argv[3]);
	args->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
		args->nbr_of_meal = -1;
	if (argc == 6)
		args->nbr_of_meal = ft_atol(argv[5]);
	if (args->nbr_of_philo == 0)
		error_exit(ARG_DEAD);
}
