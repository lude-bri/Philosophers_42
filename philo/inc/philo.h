/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:03 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 16:57:06 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// ========================================================================== //
//								INCLUDES                                      //
// ========================================================================== //

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

// ========================================================================== //
//								DEFINES                                       //
// ========================================================================== //


// ========================================================================== //
//								STRUCTS                                       //
// ========================================================================== //


//Philosophers alternatively eat, think or sleep
//While they're eating, they're not thinking nor sleeping
//While they're thinking, they're not eating nor sleeping
//While they're sleeping, they're not eating nor thinking

typedef pthread_mutex_t t_mtx;
typedef struct s_table	t_table;

//philosophers struct
typedef struct s_philo 
{
	int			id;
	pthread_t	thread_id;
	int			left_fork;
	int			right_fork;
	long		meals_counter;
	long		last_meal_time; //check if philo has died
	bool		full;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
	long		nbr_limit_meals;
	long		nbr_of_philos;
	long		nbr_philos_full;
	long		start_meal;
	long		end_meal;
	t_mtx		start_mtx;
	t_mtx		eat_mtx;
	t_mtx		end_mtx;
	t_mtx		print_mtx;
	t_mtx		*forks;
	t_philo		*philos;
}				t_table;

// ========================================================================== //
//								FUNCTIONS                                     //
// ========================================================================== //

// ============ //
//     100      //
// ============ //

//110_init.c
void	init_table(char **av, t_table *table);
void	init_philo_n_forks(t_table *table);
void	init_mutexes(t_table *table);
void	prepare_table(t_table *table, int i);

//111_init_utils.c
int			ft_atoi(const char *nprt);
int			ft_atol(const char *str);
const char	*sanity_check(const char *str);
bool		is_space(char c);
bool		is_digit(char c);
long long	get_time(void);

//200_start.c
void	start_philo(t_table *table);
void	*start_meal(void *data);

//210_action.c
void	philo_do(t_philo *philo, long long time, char *action);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo, t_table *table);

//300_monitor.c
int		ended_meal(t_table *table);
void	meal_monitor(t_table *table);

//310_checker.c
int		check_philo_status(t_philo *philo);
int		check_philo_full(t_philo *philo);

//800_error.c
void	error_exit(char *error_msg, int error_no);

//900_free.c
void	kill_philo(t_table *table);


#endif

