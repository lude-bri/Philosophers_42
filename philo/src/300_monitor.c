/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   300_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:42:51 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:38:31 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//Monitors the status of all philosophers during the simulation.
//Terminates the simulation if a philosophers dies of are full.
void	meal_monitor(t_table *table)
{
	int		i;
	int		monitor;

	monitor = 1;
	while (monitor)
	{
		i = -1;
		table->nbr_philos_full = 0;
		while (++i < table->nbr_of_philos)
		{
			if (monitor && check_philo_status(&table->philos[i]))
			{
				monitor = 0;
				break ;
			}
		}
		usleep(100);
	}
}

//Check if the simulation has ended.
//Returns the value of the 'end_meal' flag in a thread-safe manner
int	ended_meal(t_table *table)
{
	int		ended;

	pthread_mutex_lock(&table->end_mtx);
	ended = table->end_meal;
	pthread_mutex_unlock(&table->end_mtx);
	return (ended);
}
