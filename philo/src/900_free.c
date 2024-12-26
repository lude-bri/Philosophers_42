/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   900_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:28:27 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:35:59 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	destroy_mutexes(t_table *table, int error_code)
{
	int		i;

	i = 0;
	if (error_code >= 2 && table->forks)
	{
		while (i < table->nbr_of_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	if (error_code >= 1)
	{
		pthread_mutex_destroy(&table->start_mtx);
		pthread_mutex_destroy(&table->print_mtx);
		pthread_mutex_destroy(&table->eat_mtx);
		pthread_mutex_destroy(&table->end_mtx);
	}
}

void	kill_philo(t_table *table, int error_code)
{
	int		i;

	i = -1;
	if (error_code >= 1 && table->philos)
	{
		while (++i < table->nbr_of_philos)
		{
			if (error_code >= 3)
			{
				if (pthread_join(table->philos[i].thread_id, NULL))
				{
					error_exit("Error: failed to join thread", STD_ERR,
						table, THREAD);
					return ;
				}
			}
		}
		free(table->philos);
	}
	if (error_code >= 2)
		destroy_mutexes(table, error_code);
}
