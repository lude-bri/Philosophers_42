/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:13:57 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:36:58 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	start_philo(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->start_mtx);
	while (++i < table->nbr_of_philos)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				start_meal, &table->philos[i]))
			error_exit("Error: philo was not created", 2, table, 2);
	}
	pthread_mutex_unlock(&table->start_mtx);
}

void	*start_meal(void *data)
{
	t_table		*table;
	t_philo		*philo;

	philo = (t_philo *)data;
	table = philo->table;
	pthread_mutex_lock(&table->start_mtx);
	pthread_mutex_unlock(&table->start_mtx);
	if ((!(philo->id % 2)) || (table->nbr_of_philos % 2
			&& table->nbr_of_philos > 1
			&& philo->id == 1))
		philo_do(philo, philo->table->time_to_eat,
			"is thinking");
	while (!ended_meal(table))
	{
		if (table->nbr_of_philos == 1)
		{
			philo_do(philo, 0, "has taken a fork");
			break ;
		}
		philo_eat(philo);
		philo_sleep(philo, table);
	}
	return (NULL);
}
