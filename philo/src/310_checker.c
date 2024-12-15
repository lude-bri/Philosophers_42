/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:17:16 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:27:49 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_philo_status(t_philo *philo)
{
	t_table		*table;
	long long	time;

	table = philo->table;
	pthread_mutex_lock(&table->eat_mtx);
	time = get_time();
	if (time - philo->last_meal_time >= table->time_to_die)
	{
		philo_do(philo, 0, "died");
		pthread_mutex_unlock(&table->eat_mtx);
		pthread_mutex_lock(&table->eat_mtx);
		table->end_meal = 1;
		pthread_mutex_unlock(&table->eat_mtx);
		return (1);
	}
	pthread_mutex_unlock(&table->eat_mtx);
	if (check_philo_full(philo))
		return (1);
	return(0);
}

int	check_philo_full(t_philo *philo)
{
	t_table		*table;
	int			res;

	table = philo->table;
	res = 0;
	pthread_mutex_lock(&table->eat_mtx);
	if (table->nbr_limit_meals != -1 && philo->meals_counter >= table->nbr_limit_meals)
	{
		pthread_mutex_unlock(&table->eat_mtx);
		pthread_mutex_lock(&table->end_mtx);
		table->nbr_philos_full += 1;
		if (table->nbr_philos_full >= table->nbr_of_philos)
		{
			table->end_meal = 1;
			res = 1;
		}
		pthread_mutex_unlock(&table->end_mtx);
	}
	else	
		pthread_mutex_unlock(&table->eat_mtx);
	return (res);
}
