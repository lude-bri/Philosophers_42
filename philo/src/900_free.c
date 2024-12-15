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

void	kill_philo(t_table *table)
{
	int		i;

	i = -1;
	if (table->philos)
	{
		while (++i < table->nbr_of_philos)
			free(table->philos);
	}
	i = -1;
	if (table->forks)
	{
		while (++i < table->nbr_of_philos)
			pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->start_mtx);
		pthread_mutex_destroy(&table->end_mtx);
		pthread_mutex_destroy(&table->print_mtx);
		pthread_mutex_destroy(&table->eat_mtx);
		free(table->forks);
	}
}
