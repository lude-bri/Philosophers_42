/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   300_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:42:51 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:16:48 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

int	ended_meal(t_table *table)
{
	int		ended;

	pthread_mutex_lock(&table->end_mtx);
	ended = table->end_meal;
	pthread_mutex_unlock(&table->end_mtx);
	return (ended);
}
