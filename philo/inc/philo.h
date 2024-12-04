/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:03 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 16:38:53 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// ========================================================================== //
//								INCLUDES                                      //
// ========================================================================== //

# include <unistd.h>
# include <stdio.h>
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

//fork == mutex
//forks structs
typedef struct s_fork 
{
	t_mtx	fork;
	int		fork_id;
}			t_fork;

//philosophers struct
typedef struct s_philo 
{

	//philosophers id
	int			id;
	pthread_t	thread_id;

	//left fork
	t_fork		*left_fork;
	//right right
	t_fork		*right_fork;
	
	long		meals_counter;
	long		last_meal_time; //check if philo has died
	bool		full;
	t_table		*table;

}	t_philo;

typedef struct s_table
{
	long		philo_number;
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
	long		nbr_limit_meals;
	long		start_simulation;
	long		end_simulation;
	t_fork		*forks;
	t_philo		*philos;
}				t_table;

// ========================================================================== //
//								FUNCTIONS                                     //
// ========================================================================== //

// ============ //
//     100      //
// ============ //

//110_init.c
void	init_philo(int ac, char **av);
void	build_philo(char **av);
void	build_philo_plus(char **av);


#endif

