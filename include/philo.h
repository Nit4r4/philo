/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:16 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/15 09:51:52 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

/* DEFINE COLORS */
# define PURP "\e[35m"
# define GREEN "\e[32m"
# define RED "\e[31m"
# define WHITE "\e[39m"
# define YELLOW "\033[33m"
# define ORANGE "$(shell tput setaf 208)"
# define RESET "\e[0"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

/* ERRORS MESSAGES */
# define ARG_NBR "\033[31mError : bad number of arguments"
# define ARG_C "\033[31mError : please do not use letters"
# define ARG_DEAD "\033[31mError : it seems that no philo is around the table..."
# define ARG_IMP "\033[31mError : the simulation cannot begin beacause of args"

/* ACTIONS MESSAGES */
# define M_TIME "Timestamp(ms): "
# define M_PHILO " philo n°"
# define M_FORK "has taken a fork\n"
# define M_EAT "is eating\n"
# define M_SLEEP "is sleeping\n"
# define M_THINK "is thinking\n"
# define M_DIE " died\n"

/* STRUCT */
typedef struct s_args
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meal;
	int				time_to_think;
	int				all_meal_eaten;
	long int		start_time;
	long int		end_time;
	pthread_mutex_t	mutex;
	struct s_philo	*philos;
}	t_args;

typedef struct s_philo
{
	int				nbr_of_fork;
	int				name;
	int				meals_eaten;
	int				last_meal;
	bool			alive;
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	t_args			*args;
}	t_philo;

/* UTILS */
long long int	ft_atol(const char *str);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);

/* MANDATORY */
void			check_errors(int argc, char **argv);
void			argv_to_int(int argc, char **argv, t_args *args);
int				error_exit(char *str);
t_philo			*ft_present( t_args *args);
int				find_my_forks(t_philo *philo, t_args *args);
long int		get_current_time_ms(void);
void			ft_start(t_args *args);
void			takes_forks(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			free_ture(t_philo *philo);
void			ft_dead(t_philo *philo, t_args *args);
int				lets_eat(t_philo *philo);
void			philo_thread(t_philo *philo, t_args *args);
void			ft_init_mutex(t_philo *philo);
void			exit_mutex(t_philo *philo, t_args *args);
void			ft_destroy_mutex(t_philo *philo);
int				launch_philos(t_philo *philo, t_args *args);
void			exit_thread(t_philo *philo, t_args *args);
long int		timestamp(void);
void			print(char *str, t_philo *philo, char *str2);
void			ft_usleep(int time);
void			ft_die(t_philo *philo, int i);
int				no_meal_today(t_philo *philo);
int				check_philos(t_philo *philo);

/* Petites fonctions parties trop tot... RIP */
long int		ft_end(t_args *args);
void			ft_quincunx(t_philo *philo);
void			print_die(char *str, t_philo *philo, long int time, char *str2);
void			can_i_leave_the_table(t_philo *philo);

#endif
