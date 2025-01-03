/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:26:07 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 19:06:13 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Initializes the simulation table and validates input arguments.
//Allocate resources and prepare the philosophers and forks.
void	init_table(char **av, t_table *table)
{
	table->nbr_of_philos = ft_atoi(av[1]);
	if ((table->nbr_of_philos > 200) || (table->nbr_of_philos <= 0))
		error_exit("Error: 200 philosophers is the max allowed", STD_ERR,
			NULL, NONE);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (table->time_to_die < 60
		|| table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		error_exit("Error: wrong timestamp", STD_ERR, NULL, NONE);
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
	table->nbr_philos_full = 0;
	table->start_meal = get_time();
	table->end_meal = 0;
	table->philos = NULL;
	table->forks = NULL;
	init_philo_n_forks(table);
	init_mutexes(table);
}

//Allocates memory for philosophers and forks.
//Prepares individual philosophers structures and their associated forks.
void	init_philo_n_forks(t_table *table)
{
	int		i;

	i = -1;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!table->philos)
		error_exit("Error: Malloc failed", STD_ERR, table, NONE);
	table->forks = malloc(sizeof(t_mtx) * table->nbr_of_philos);
	if (!table->forks)
		error_exit("Error: Malloc failed", STD_ERR, table, MUTEX);
	while (++i < table->nbr_of_philos)
		prepare_table(table, i);
}

//Sets up a philosopher's attributes and initializes their forks
void	prepare_table(t_table *table, int i)
{
	table->philos[i].id = i + 1;
	table->philos[i].right_fork = i;
	table->philos[i].left_fork = (i + 1) % table->nbr_of_philos;
	table->philos[i].table = table;
	table->philos[i].meals_counter = 0;
	table->philos[i].last_meal_time = table->start_meal;
	if (pthread_mutex_init(&table->forks[i], NULL))
		error_exit("Error: Mutexes init failed", STD_ERR, table, MUTEX);
}

//Initializes additional mutexes used for synchronization
void	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->start_mtx, NULL))
		error_exit("Error: mutex", STD_ERR, table, MUTEX);
	if (pthread_mutex_init(&table->eat_mtx, NULL))
		error_exit("Error: mutex", STD_ERR, table, MUTEX);
	if (pthread_mutex_init(&table->end_mtx, NULL))
		error_exit("Error: mutex", STD_ERR, table, MUTEX);
	if (pthread_mutex_init(&table->print_mtx, NULL))
		error_exit("Error: mutex", STD_ERR, table, MUTEX);
}
